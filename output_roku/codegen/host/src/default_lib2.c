#include "/usr/uma/apps/uma/_template/conv2dnchw.cc"// tvm target: vanilla_accelerator
#define TVM_EXPORTS
#include "tvm/runtime/c_runtime_api.h"
#include "tvm/runtime/c_backend_api.h"
#include <math.h>
#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_vanilla_accelerator_main_20(float* placeholder, float* placeholder_1, float* T_matmul_NT) {
  for (int32_t i1 = 0; i1 < 12; ++i1) {
    for (int32_t i2 = 0; i2 < 1408; ++i2) {
      if (i2 == 0) {
        T_matmul_NT[i1] = 0.000000e+00f;
      }
      T_matmul_NT[i1] = (T_matmul_NT[i1] + (placeholder[i2] * placeholder_1[((i1 * 1408) + i2)]));
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_vanilla_accelerator_main_10(float* placeholder, float* placeholder_1, float* conv2d_nhwc) {
  void* pad_temp = TVMBackendAllocWorkspace(1, 0, (uint64_t)22528, 2, 32);
  if (pad_temp == NULL) {
    return -1;
  }
  for (int32_t i1 = 0; i1 < 22; ++i1) {
    for (int32_t i2 = 0; i2 < 8; ++i2) {
      for (int32_t i3 = 0; i3 < 32; ++i3) {
        int32_t cse_var_1 = (((i1 * 256) + (i2 * 32)) + i3);
        ((float*)pad_temp)[cse_var_1] = placeholder[cse_var_1];
      }
    }
  }
  for (int32_t i1_1 = 0; i1_1 < 22; ++i1_1) {
    for (int32_t i2_1 = 0; i2_1 < 8; ++i2_1) {
      for (int32_t i3_1 = 0; i3_1 < 32; ++i3_1) {
        for (int32_t i6 = 0; i6 < 32; ++i6) {
          int32_t cse_var_3 = ((i1_1 * 256) + (i2_1 * 32));
          int32_t cse_var_2 = (cse_var_3 + i3_1);
          if (i6 == 0) {
            conv2d_nhwc[cse_var_2] = 0.000000e+00f;
          }
          conv2d_nhwc[cse_var_2] = (conv2d_nhwc[cse_var_2] + (((float*)pad_temp)[(cse_var_3 + i6)] * placeholder_1[((i6 * 32) + i3_1)]));
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
TVM_DLL int32_t tvmgen_default_vanilla_accelerator_main_18(float* placeholder, float* placeholder_1, float* conv2d_nhwc) {
  void* pad_temp = TVMBackendAllocWorkspace(1, 0, (uint64_t)22528, 2, 32);
  if (pad_temp == NULL) {
    return -1;
  }
  for (int32_t i1 = 0; i1 < 22; ++i1) {
    for (int32_t i2 = 0; i2 < 8; ++i2) {
      for (int32_t i3 = 0; i3 < 32; ++i3) {
        int32_t cse_var_1 = (((i1 * 256) + (i2 * 32)) + i3);
        ((float*)pad_temp)[cse_var_1] = placeholder[cse_var_1];
      }
    }
  }
  for (int32_t i1_1 = 0; i1_1 < 22; ++i1_1) {
    for (int32_t i2_1 = 0; i2_1 < 8; ++i2_1) {
      for (int32_t i3_1 = 0; i3_1 < 32; ++i3_1) {
        for (int32_t i6 = 0; i6 < 32; ++i6) {
          int32_t cse_var_3 = ((i1_1 * 256) + (i2_1 * 32));
          int32_t cse_var_2 = (cse_var_3 + i3_1);
          if (i6 == 0) {
            conv2d_nhwc[cse_var_2] = 0.000000e+00f;
          }
          conv2d_nhwc[cse_var_2] = (conv2d_nhwc[cse_var_2] + (((float*)pad_temp)[(cse_var_3 + i6)] * placeholder_1[((i6 * 32) + i3_1)]));
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
TVM_DLL int32_t tvmgen_default_vanilla_accelerator_main_12(float* placeholder, float* placeholder_1, float* conv2d_nhwc) {
  void* pad_temp = TVMBackendAllocWorkspace(1, 0, (uint64_t)22528, 2, 32);
  if (pad_temp == NULL) {
    return -1;
  }
  for (int32_t i1 = 0; i1 < 22; ++i1) {
    for (int32_t i2 = 0; i2 < 8; ++i2) {
      for (int32_t i3 = 0; i3 < 32; ++i3) {
        int32_t cse_var_1 = (((i1 * 256) + (i2 * 32)) + i3);
        ((float*)pad_temp)[cse_var_1] = placeholder[cse_var_1];
      }
    }
  }
  for (int32_t i1_1 = 0; i1_1 < 22; ++i1_1) {
    for (int32_t i2_1 = 0; i2_1 < 8; ++i2_1) {
      for (int32_t i3_1 = 0; i3_1 < 32; ++i3_1) {
        for (int32_t i6 = 0; i6 < 32; ++i6) {
          int32_t cse_var_3 = ((i1_1 * 256) + (i2_1 * 32));
          int32_t cse_var_2 = (cse_var_3 + i3_1);
          if (i6 == 0) {
            conv2d_nhwc[cse_var_2] = 0.000000e+00f;
          }
          conv2d_nhwc[cse_var_2] = (conv2d_nhwc[cse_var_2] + (((float*)pad_temp)[(cse_var_3 + i6)] * placeholder_1[((i6 * 32) + i3_1)]));
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
TVM_DLL int32_t tvmgen_default_vanilla_accelerator_main_14(float* placeholder, float* placeholder_1, float* conv2d_nhwc) {
  void* pad_temp = TVMBackendAllocWorkspace(1, 0, (uint64_t)22528, 2, 32);
  if (pad_temp == NULL) {
    return -1;
  }
  for (int32_t i1 = 0; i1 < 22; ++i1) {
    for (int32_t i2 = 0; i2 < 8; ++i2) {
      for (int32_t i3 = 0; i3 < 32; ++i3) {
        int32_t cse_var_1 = (((i1 * 256) + (i2 * 32)) + i3);
        ((float*)pad_temp)[cse_var_1] = placeholder[cse_var_1];
      }
    }
  }
  for (int32_t i1_1 = 0; i1_1 < 22; ++i1_1) {
    for (int32_t i2_1 = 0; i2_1 < 8; ++i2_1) {
      for (int32_t i3_1 = 0; i3_1 < 32; ++i3_1) {
        for (int32_t i6 = 0; i6 < 32; ++i6) {
          int32_t cse_var_3 = ((i1_1 * 256) + (i2_1 * 32));
          int32_t cse_var_2 = (cse_var_3 + i3_1);
          if (i6 == 0) {
            conv2d_nhwc[cse_var_2] = 0.000000e+00f;
          }
          conv2d_nhwc[cse_var_2] = (conv2d_nhwc[cse_var_2] + (((float*)pad_temp)[(cse_var_3 + i6)] * placeholder_1[((i6 * 32) + i3_1)]));
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
// this is the implementation of the first convolution , but it seems like it uses default tvm instead of my_ai_hw_conv2dnchw
// maybe because of the fused RELU the pattern matching did not work
TVM_DLL int32_t tvmgen_default_vanilla_accelerator_main_0(float* placeholder, float* placeholder_1, float* conv2d_nhwc) {
  void* pad_temp = TVMBackendAllocWorkspace(1, 0, (uint64_t)15520, 2, 32);
  if (pad_temp == NULL) {
    return -1;
  }
  for (int32_t i1 = 0; i1 < 97; ++i1) {
    for (int32_t i2 = 0; i2 < 40; ++i2) {
      int32_t cse_var_1 = ((i1 * 40) + i2);
      ((float*)pad_temp)[cse_var_1] = placeholder[cse_var_1];
    }
  }
  for (int32_t i1_1 = 0; i1_1 < 95; ++i1_1) {
    for (int32_t i2_1 = 0; i2_1 < 38; ++i2_1) {
      for (int32_t i3 = 0; i3 < 20; ++i3) {
        for (int32_t i4 = 0; i4 < 3; ++i4) {
          for (int32_t i5 = 0; i5 < 3; ++i5) {
            int32_t cse_var_2 = (((i1_1 * 760) + (i2_1 * 20)) + i3);
            if ((i4 == 0) && (i5 == 0)) {
              conv2d_nhwc[cse_var_2] = 0.000000e+00f;
            }
            conv2d_nhwc[cse_var_2] = (conv2d_nhwc[cse_var_2] + (((float*)pad_temp)[((((i1_1 * 40) + (i4 * 40)) + i2_1) + i5)] * placeholder_1[(((i4 * 60) + (i5 * 20)) + i3)]));
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
TVM_DLL int32_t tvmgen_default_vanilla_accelerator_main_4(float* placeholder, float* placeholder_1, float* conv2d_nhwc) {
  void* pad_temp = TVMBackendAllocWorkspace(1, 0, (uint64_t)22528, 2, 32);
  if (pad_temp == NULL) {
    return -1;
  }
  for (int32_t i1 = 0; i1 < 22; ++i1) {
    for (int32_t i2 = 0; i2 < 8; ++i2) {
      for (int32_t i3 = 0; i3 < 32; ++i3) {
        int32_t cse_var_1 = (((i1 * 256) + (i2 * 32)) + i3);
        ((float*)pad_temp)[cse_var_1] = placeholder[cse_var_1];
      }
    }
  }
  for (int32_t i1_1 = 0; i1_1 < 22; ++i1_1) {
    for (int32_t i2_1 = 0; i2_1 < 8; ++i2_1) {
      for (int32_t i3_1 = 0; i3_1 < 32; ++i3_1) {
        for (int32_t i6 = 0; i6 < 32; ++i6) {
          int32_t cse_var_3 = ((i1_1 * 256) + (i2_1 * 32));
          int32_t cse_var_2 = (cse_var_3 + i3_1);
          if (i6 == 0) {
            conv2d_nhwc[cse_var_2] = 0.000000e+00f;
          }
          conv2d_nhwc[cse_var_2] = (conv2d_nhwc[cse_var_2] + (((float*)pad_temp)[(cse_var_3 + i6)] * placeholder_1[((i6 * 32) + i3_1)]));
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
TVM_DLL int32_t tvmgen_default_vanilla_accelerator_main_22(float* placeholder, float* placeholder_1, float* T_matmul_NT) {
  for (int32_t i1 = 0; i1 < 2; ++i1) {
    for (int32_t i2 = 0; i2 < 12; ++i2) {
      if (i2 == 0) {
        T_matmul_NT[i1] = 0.000000e+00f;
      }
      T_matmul_NT[i1] = (T_matmul_NT[i1] + (placeholder[i2] * placeholder_1[((i1 * 12) + i2)]));
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_vanilla_accelerator_main_8(float* placeholder, float* placeholder_1, float* conv2d_nhwc) {
  void* pad_temp = TVMBackendAllocWorkspace(1, 0, (uint64_t)22528, 2, 32);
  if (pad_temp == NULL) {
    return -1;
  }
  for (int32_t i1 = 0; i1 < 22; ++i1) {
    for (int32_t i2 = 0; i2 < 8; ++i2) {
      for (int32_t i3 = 0; i3 < 32; ++i3) {
        int32_t cse_var_1 = (((i1 * 256) + (i2 * 32)) + i3);
        ((float*)pad_temp)[cse_var_1] = placeholder[cse_var_1];
      }
    }
  }
  for (int32_t i1_1 = 0; i1_1 < 22; ++i1_1) {
    for (int32_t i2_1 = 0; i2_1 < 8; ++i2_1) {
      for (int32_t i3_1 = 0; i3_1 < 32; ++i3_1) {
        for (int32_t i6 = 0; i6 < 32; ++i6) {
          int32_t cse_var_3 = ((i1_1 * 256) + (i2_1 * 32));
          int32_t cse_var_2 = (cse_var_3 + i3_1);
          if (i6 == 0) {
            conv2d_nhwc[cse_var_2] = 0.000000e+00f;
          }
          conv2d_nhwc[cse_var_2] = (conv2d_nhwc[cse_var_2] + (((float*)pad_temp)[(cse_var_3 + i6)] * placeholder_1[((i6 * 32) + i3_1)]));
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
TVM_DLL int32_t tvmgen_default_vanilla_accelerator_main_2(float* placeholder, float* placeholder_1, float* conv2d_nhwc) {
  void* pad_temp = TVMBackendAllocWorkspace(1, 0, (uint64_t)71440, 2, 32);
  if (pad_temp == NULL) {
    return -1;
  }
  for (int32_t i1 = 0; i1 < 47; ++i1) {
    for (int32_t i2 = 0; i2 < 19; ++i2) {
      for (int32_t i3 = 0; i3 < 20; ++i3) {
        int32_t cse_var_1 = (((i1 * 380) + (i2 * 20)) + i3);
        ((float*)pad_temp)[cse_var_1] = placeholder[cse_var_1];
      }
    }
  }
  for (int32_t i1_1 = 0; i1_1 < 45; ++i1_1) {
    for (int32_t i2_1 = 0; i2_1 < 17; ++i2_1) {
      for (int32_t i3_1 = 0; i3_1 < 32; ++i3_1) {
        for (int32_t i4 = 0; i4 < 3; ++i4) {
          for (int32_t i5 = 0; i5 < 3; ++i5) {
            for (int32_t i6 = 0; i6 < 20; ++i6) {
              int32_t cse_var_2 = (((i1_1 * 544) + (i2_1 * 32)) + i3_1);
              if (((i4 == 0) && (i5 == 0)) && (i6 == 0)) {
                conv2d_nhwc[cse_var_2] = 0.000000e+00f;
              }
              conv2d_nhwc[cse_var_2] = (conv2d_nhwc[cse_var_2] + (((float*)pad_temp)[(((((i1_1 * 380) + (i4 * 380)) + (i2_1 * 20)) + (i5 * 20)) + i6)] * placeholder_1[((((i4 * 1920) + (i5 * 640)) + (i6 * 32)) + i3_1)]));
            }
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
TVM_DLL int32_t tvmgen_default_vanilla_accelerator_main_6(float* placeholder, float* placeholder_1, float* conv2d_nhwc) {
  void* pad_temp = TVMBackendAllocWorkspace(1, 0, (uint64_t)22528, 2, 32);
  if (pad_temp == NULL) {
    return -1;
  }
  for (int32_t i1 = 0; i1 < 22; ++i1) {
    for (int32_t i2 = 0; i2 < 8; ++i2) {
      for (int32_t i3 = 0; i3 < 32; ++i3) {
        int32_t cse_var_1 = (((i1 * 256) + (i2 * 32)) + i3);
        ((float*)pad_temp)[cse_var_1] = placeholder[cse_var_1];
      }
    }
  }
  for (int32_t i1_1 = 0; i1_1 < 22; ++i1_1) {
    for (int32_t i2_1 = 0; i2_1 < 8; ++i2_1) {
      for (int32_t i3_1 = 0; i3_1 < 32; ++i3_1) {
        for (int32_t i6 = 0; i6 < 32; ++i6) {
          int32_t cse_var_3 = ((i1_1 * 256) + (i2_1 * 32));
          int32_t cse_var_2 = (cse_var_3 + i3_1);
          if (i6 == 0) {
            conv2d_nhwc[cse_var_2] = 0.000000e+00f;
          }
          conv2d_nhwc[cse_var_2] = (conv2d_nhwc[cse_var_2] + (((float*)pad_temp)[(cse_var_3 + i6)] * placeholder_1[((i6 * 32) + i3_1)]));
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
TVM_DLL int32_t tvmgen_default_vanilla_accelerator_main_16(float* placeholder, float* placeholder_1, float* conv2d_nhwc) {
  void* pad_temp = TVMBackendAllocWorkspace(1, 0, (uint64_t)22528, 2, 32);
  if (pad_temp == NULL) {
    return -1;
  }
  for (int32_t i1 = 0; i1 < 22; ++i1) {
    for (int32_t i2 = 0; i2 < 8; ++i2) {
      for (int32_t i3 = 0; i3 < 32; ++i3) {
        int32_t cse_var_1 = (((i1 * 256) + (i2 * 32)) + i3);
        ((float*)pad_temp)[cse_var_1] = placeholder[cse_var_1];
      }
    }
  }
  for (int32_t i1_1 = 0; i1_1 < 22; ++i1_1) {
    for (int32_t i2_1 = 0; i2_1 < 8; ++i2_1) {
      for (int32_t i3_1 = 0; i3_1 < 32; ++i3_1) {
        for (int32_t i6 = 0; i6 < 32; ++i6) {
          int32_t cse_var_3 = ((i1_1 * 256) + (i2_1 * 32));
          int32_t cse_var_2 = (cse_var_3 + i3_1);
          if (i6 == 0) {
            conv2d_nhwc[cse_var_2] = 0.000000e+00f;
          }
          conv2d_nhwc[cse_var_2] = (conv2d_nhwc[cse_var_2] + (((float*)pad_temp)[(cse_var_3 + i6)] * placeholder_1[((i6 * 32) + i3_1)]));
        }
      }
    }
  }
  if (TVMBackendFreeWorkspace(1, 0, pad_temp) != 0) {
    return -1;
  }
  return 0;
}

