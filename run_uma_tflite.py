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
from tvm.micro.testing.aot_test_utils import AOT_DEFAULT_RUNNER
from tvm.relay import transform, testing
import os
import tensorflow as tf

from tvm.testing.aot import (
    AOTTestModel,
    AOTTestRunner,
    generate_ref_data,
    compile_and_run,
    create_relay_module_and_inputs_from_tflite_file,
)

import tvm
from test_uma_vanilla_accelerator import VanillaAcceleratorBackend
from tvm import relay
import numpy as np
from collections import OrderedDict
from tvm.relay.backend.contrib.uma.api.utils import uma_available
from tvm.contrib import utils, graph_executor
from tvm.relay.backend import Executor, Runtime

def main():

    use_unpacked_api = True
    interface_api = "c"
    test_runner = AOT_DEFAULT_RUNNER

    tflite_file = "/tmp/model.tflite"
    if not os.path.exists(tflite_file):
        generate_tflite_file(tflite_file)

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



    runtime = Runtime("crt")
    config = {"tir.disable_vectorize": True}

    mod = AOTTestModel(module=mod, inputs=input_list, outputs=output_list, params=params)

    with tvm.transform.PassContext(opt_level=3, config=config):
        executor_factory = tvm.relay.build(
            mod.module,
            tvm.target.Target(target, host=target),
            params=mod.params,
            mod_name=mod.name,
            runtime=runtime,
        )

        print(executor_factory)


    #print(input_list)
    #print(output_list)


if __name__ == "__main__":
    main()
