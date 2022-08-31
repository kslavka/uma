#include "/usr/uma/apps/uma/_template/conv2dnchw.cc"// tvm target: vanilla_accelerator
#define TVM_EXPORTS
#include "tvm/runtime/c_runtime_api.h"
#include "tvm/runtime/c_backend_api.h"
#include <math.h>
#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_vanilla_accelerator_main_0(float* placeholder, float* placeholder_1, float* conv2d_nhwc) {
  void* pad_temp = TVMBackendAllocWorkspace(1, 0, (uint64_t)3600, 2, 32);
  if (pad_temp == NULL) {
    return -1;
  }
  for (int32_t i1 = 0; i1 < 30; ++i1) {
    for (int32_t i2 = 0; i2 < 30; ++i2) {
      ((float*)pad_temp)[((i1 * 30) + i2)] = (((((1 <= i1) && (i1 < 29)) && (1 <= i2)) && (i2 < 29)) ? placeholder[(((i1 * 28) + i2) - 29)] : 0.000000e+00f);
    }
  }
  for (int32_t i1_1 = 0; i1_1 < 28; ++i1_1) {
    for (int32_t i2_1 = 0; i2_1 < 28; ++i2_1) {
      for (int32_t i3 = 0; i3 < 4; ++i3) {
        for (int32_t i4 = 0; i4 < 3; ++i4) {
          for (int32_t i5 = 0; i5 < 3; ++i5) {
            int32_t cse_var_1 = (((i1_1 * 112) + (i2_1 * 4)) + i3);
            if ((i4 == 0) && (i5 == 0)) {
              conv2d_nhwc[cse_var_1] = 0.000000e+00f;
            }
            conv2d_nhwc[cse_var_1] = (conv2d_nhwc[cse_var_1] + (((float*)pad_temp)[((((i1_1 * 30) + (i4 * 30)) + i2_1) + i5)] * placeholder_1[(((i4 * 12) + (i5 * 4)) + i3)]));
          }
        }
      }
    }
  }
  if (TVMBackendFreeWorkspace(1, 0, pad_temp) != 0) {
    return -1;
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_vanilla_accelerator_main_4(float* placeholder, float* placeholder_1, float* T_matmul_NT) {
  for (int32_t i1 = 0; i1 < 10; ++i1) {
    for (int32_t i2 = 0; i2 < 32; ++i2) {
      if (i2 == 0) {
        T_matmul_NT[i1] = 0.000000e+00f;
      }
      T_matmul_NT[i1] = (T_matmul_NT[i1] + (placeholder[i2] * placeholder_1[((i1 * 32) + i2)]));
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_vanilla_accelerator_main_2(float* placeholder, float* placeholder_1, float* T_matmul_NT) {
  for (int32_t i1 = 0; i1 < 32; ++i1) {
    for (int32_t i2 = 0; i2 < 3136; ++i2) {
      if (i2 == 0) {
        T_matmul_NT[i1] = 0.000000e+00f;
      }
      T_matmul_NT[i1] = (T_matmul_NT[i1] + (placeholder[i2] * placeholder_1[((i1 * 3136) + i2)]));
    }
  }
  return 0;
}

