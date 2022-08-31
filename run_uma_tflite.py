# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.

import pytest

pytest.importorskip("tflite")
pytest.importorskip("tensorflow")

import os
import tensorflow as tf
from tvm.micro.testing.aot_test_utils import AOT_DEFAULT_RUNNER
from tvm.relay import transform, testing
from tvm.testing.aot import (
    AOTTestModel,
    AOTTestRunner,
    AOTCompiledTestModel,
    generate_ref_data,
    compile_and_run,
    run_and_check,
    create_relay_module_and_inputs_from_tflite_file,
)

import tvm
from test_uma_vanilla_accelerator import VanillaAcceleratorBackend
from tvm import relay
import numpy as np
from collections import OrderedDict

from tvm.relay.backend.contrib.uma.api.utils import uma_available
from tvm.relay.backend import Executor, Runtime




def generate_tflite_file(tflite_filename):
    mnist = tf.keras.datasets.mnist
    (x_train, y_train), (x_test, y_test) = mnist.load_data()
    x_train, x_test = x_train / 255.0, x_test / 255.0
    x_train, x_test = x_train.reshape(-1, 28, 28, 1), x_test.reshape(-1, 28, 28, 1)
    tf_model = tf.keras.models.Sequential(
        [
            tf.keras.Input(shape=(28, 28, 1)),
            tf.keras.layers.Conv2D(4, (3, 3), padding="same", activation="relu"),
            tf.keras.layers.Flatten(input_shape=(28, 28)),
            tf.keras.layers.Dense(32, activation="relu"),
            tf.keras.layers.Dropout(0.2),
            tf.keras.layers.Dense(10),
        ]
    )
    output = tf_model(x_train[:1])
    output = output.numpy()
    loss = tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True)
    loss(y_train[:1], output).numpy()
    tf_model.compile(metrics=["accuracy"], optimizer="adam", loss=loss)
    tf_model.fit(x_train, y_train, epochs=1)

    tflite_converter = tf.lite.TFLiteConverter.from_keras_model(tf_model)
    tflite_model = tflite_converter.convert()
    with open(tflite_filename, "wb") as f:
        f.write(tflite_model)


def main():

    use_unpacked_api = True
    interface_api = "c"
    test_runner = AOT_DEFAULT_RUNNER

    tflite_file = "/tmp/model_custom.tflite"

    '''
    tflite_file = "/tmp/model.tflite"
    if os.path.exists(tflite_file):
        os.remove(tflite_file)
    generate_tflite_file(tflite_file)
    '''

    pytest.importorskip("tflite")

    interpreter = tf.lite.Interpreter(model_path=tflite_file)
    tf_model_details = interpreter.get_input_details()
    mod, _, params = create_relay_module_and_inputs_from_tflite_file(
        tflite_file, bind_params_by_name=False
    )

    uma_backend = VanillaAcceleratorBackend()
    uma_backend.register()
    target = tvm.target.Target("vanilla_accelerator", host=tvm.target.Target("c"))
    target_c = tvm.target.Target("c")

    # Generation of test input and output
    data_shape = [int(x) for x in mod["main"].params[0].type_annotation.shape]
    data = np.random.uniform(size=data_shape).astype("float32")
    input_list = {str(tf_model_details[0]["name"]): data}
    output_list = generate_ref_data(mod, input_list, params)

    # UMA partitioning (needs to be done after generate_ref_data)
    mod = uma_backend.partition(mod)

    aot_test_model = AOTTestModel(module=mod, inputs=input_list, outputs=output_list, params=params)

    if isinstance(target, str):
        target = tvm.target.Target(target)

    runtime = Runtime("crt")

    executor = Executor(
        "aot",
        {
            "workspace-byte-alignment": 1,
            "constant-byte-alignment": 8,
            "interface-api": "c",
            "unpacked-api": True,
        },
    )

    config = {"tir.disable_vectorize": True}

    with tvm.transform.PassContext(opt_level=3, config=config):

        executor_factory = tvm.relay.build(
            aot_test_model.module,
            [target_c, target],
            executor=executor,
            runtime=runtime,
            #workspace_memory_pools=workspace_memory_pools,
            #constant_memory_pools=constant_memory_pools,
            params=aot_test_model.params,
            mod_name=aot_test_model.name,
        )

        compiled_mods = list()
        compiled_mods.append(
            AOTCompiledTestModel(model=aot_test_model, executor_factory=executor_factory)
        )

        lib = executor_factory.get_lib()
        print(lib)

        run_and_check(
            models=compiled_mods,
            runner=test_runner,
            interface_api=interface_api,
            debug_calculated_workspaces=False,
            workspace_byte_alignment=1,
            #constant_byte_alignment=constant_byte_alignment,
            #data_linkage=data_linkage,
            test_dir="/tmp/uma",
            verbose=True,
        )



    #print(input_list)
    #print(output_list)


if __name__ == "__main__":
    main()
