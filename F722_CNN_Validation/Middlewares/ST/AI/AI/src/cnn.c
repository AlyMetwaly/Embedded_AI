/**
  ******************************************************************************
  * @file    cnn.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Mon Apr 29 12:54:30 2019
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */



#include "cnn.h"

#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "layers.h"

#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#define AI_TOOLS_VERSION_MAJOR 3
#define AI_TOOLS_VERSION_MINOR 3
#define AI_TOOLS_VERSION_MICRO 0

#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#define AI_TOOLS_API_VERSION_MAJOR 1
#define AI_TOOLS_API_VERSION_MINOR 1
#define AI_TOOLS_API_VERSION_MICRO 0

#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_cnn
 
#undef AI_CNN_MODEL_SIGNATURE
#define AI_CNN_MODEL_SIGNATURE     "10e2e81f1b31ccf66772449da10b70b2"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     "(rev-)"
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Mon Apr 29 12:54:30 2019"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_CNN_N_BATCHES
#define AI_CNN_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network arrays declarations  *************************************/
AI_STATIC ai_array input_0_output_array;   /* Array #0 */
AI_STATIC ai_array conv2d_1_output_array;   /* Array #1 */
AI_STATIC ai_array batch_normalization_1_output_array;   /* Array #2 */
AI_STATIC ai_array conv2d_2_output_array;   /* Array #3 */
AI_STATIC ai_array batch_normalization_2_output_in_array;   /* Array #4 */
AI_STATIC ai_array batch_normalization_2_output_out_array;   /* Array #5 */
AI_STATIC ai_array dense_1_output_array;   /* Array #6 */
AI_STATIC ai_array dense_2_output_array;   /* Array #7 */
AI_STATIC ai_array dense_2_nl_output_array;   /* Array #8 */
AI_STATIC ai_array dense_3_output_array;   /* Array #9 */
AI_STATIC ai_array dense_3_nl_output_array;   /* Array #10 */


/**  Forward network tensors declarations  ************************************/
AI_STATIC ai_tensor input_0_output;   /* Tensor #0 */
AI_STATIC ai_tensor conv2d_1_output;   /* Tensor #1 */
AI_STATIC ai_tensor batch_normalization_1_output;   /* Tensor #2 */
AI_STATIC ai_tensor conv2d_2_output;   /* Tensor #3 */
AI_STATIC ai_tensor batch_normalization_2_output_in;   /* Tensor #4 */
AI_STATIC ai_tensor batch_normalization_2_output_out;   /* Tensor #5 */
AI_STATIC ai_tensor dense_1_output;   /* Tensor #6 */
AI_STATIC ai_tensor dense_2_output;   /* Tensor #7 */
AI_STATIC ai_tensor dense_2_nl_output;   /* Tensor #8 */
AI_STATIC ai_tensor dense_3_output;   /* Tensor #9 */
AI_STATIC ai_tensor dense_3_nl_output;   /* Tensor #10 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain conv2d_1_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain batch_normalization_1_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain conv2d_2_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain batch_normalization_2_chain;   /* Chain #3 */
AI_STATIC_CONST ai_tensor_chain dense_1_chain;   /* Chain #4 */
AI_STATIC_CONST ai_tensor_chain dense_2_chain;   /* Chain #5 */
AI_STATIC_CONST ai_tensor_chain dense_2_nl_chain;   /* Chain #6 */
AI_STATIC_CONST ai_tensor_chain dense_3_chain;   /* Chain #7 */
AI_STATIC_CONST ai_tensor_chain dense_3_nl_chain;   /* Chain #8 */


/**  Subgraph network operators tensor chain declarations  *********************************/


/**  Subgraph network operators declarations  *********************************/


/**  Forward network layers declarations  *************************************/
AI_STATIC ai_layer_conv2d conv2d_1_layer; /* Layer #0 */
AI_STATIC ai_layer_bn batch_normalization_1_layer; /* Layer #1 */
AI_STATIC ai_layer_conv2d conv2d_2_layer; /* Layer #2 */
AI_STATIC ai_layer_bn batch_normalization_2_layer; /* Layer #3 */
AI_STATIC ai_layer_dense dense_1_layer; /* Layer #4 */
AI_STATIC ai_layer_dense dense_2_layer; /* Layer #5 */
AI_STATIC ai_layer_nl dense_2_nl_layer; /* Layer #6 */
AI_STATIC ai_layer_dense dense_3_layer; /* Layer #7 */
AI_STATIC ai_layer_sm dense_3_nl_layer; /* Layer #8 */


/**  Arrays declarations section  *********************************************/
AI_ARRAY_OBJ_DECLARE(
  input_0_output_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 490,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_output_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 7840,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  batch_normalization_1_output_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 7840,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_output_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 1920,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  batch_normalization_2_output_in_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 1920,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  batch_normalization_2_output_out_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 1920,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  dense_1_output_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 16,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  dense_2_output_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 128,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  dense_2_nl_output_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 128,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  dense_3_output_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 12,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  dense_3_nl_output_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 12,
  AI_STATIC)


/**  Activations tensors declaration section  *********************************/
AI_TENSOR_OBJ_DECLARE(
  input_0_output,
  AI_SHAPE_INIT(49, 10, 1, 1),
  AI_STRIDE_INIT(40, 4, 4, 4),
  &input_0_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_output,
  AI_SHAPE_INIT(40, 7, 28, 1),
  AI_STRIDE_INIT(784, 112, 4, 4),
  &conv2d_1_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  batch_normalization_1_output,
  AI_SHAPE_INIT(40, 7, 28, 1),
  AI_STRIDE_INIT(784, 112, 4, 4),
  &batch_normalization_1_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_output,
  AI_SHAPE_INIT(16, 4, 30, 1),
  AI_STRIDE_INIT(480, 120, 4, 4),
  &conv2d_2_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  batch_normalization_2_output_in,
  AI_SHAPE_INIT(16, 4, 30, 1),
  AI_STRIDE_INIT(480, 120, 4, 4),
  &batch_normalization_2_output_in_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  batch_normalization_2_output_out,
  AI_SHAPE_INIT(1, 1, 1920, 1),
  AI_STRIDE_INIT(7680, 7680, 4, 4),
  &batch_normalization_2_output_out_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  dense_1_output,
  AI_SHAPE_INIT(1, 1, 16, 1),
  AI_STRIDE_INIT(64, 64, 4, 4),
  &dense_1_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  dense_2_output,
  AI_SHAPE_INIT(1, 1, 128, 1),
  AI_STRIDE_INIT(512, 512, 4, 4),
  &dense_2_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  dense_2_nl_output,
  AI_SHAPE_INIT(1, 1, 128, 1),
  AI_STRIDE_INIT(512, 512, 4, 4),
  &dense_2_nl_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  dense_3_output,
  AI_SHAPE_INIT(1, 1, 12, 1),
  AI_STRIDE_INIT(48, 48, 4, 4),
  &dense_3_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  dense_3_nl_output,
  AI_SHAPE_INIT(1, 1, 12, 1),
  AI_STRIDE_INIT(48, 48, 4, 4),
  &dense_3_nl_output_array,
  AI_STATIC)





/* Layer #0: "conv2d_1" (Conv2D) */
  

/* Weight tensor #1 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_weights_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 1120,
  AI_STATIC)

AI_TENSOR_OBJ_DECLARE(
  conv2d_1_weights,
  AI_SHAPE_INIT(28, 10, 4, 1),
  AI_STRIDE_INIT(160, 16, 4, 4),
  &conv2d_1_weights_array,
  AI_STATIC)

/* Weight tensor #2 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_bias_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 28,
  AI_STATIC)

AI_TENSOR_OBJ_DECLARE(
  conv2d_1_bias,
  AI_SHAPE_INIT(1, 1, 28, 1),
  AI_STRIDE_INIT(112, 112, 4, 4),
  &conv2d_1_bias_array,
  AI_STATIC)


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_1_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&input_0_output),
  AI_TENSOR_LIST_ENTRY(&conv2d_1_output),
  AI_TENSOR_LIST_ENTRY(&conv2d_1_weights, &conv2d_1_bias),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_1_layer, 0,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &batch_normalization_1_layer, AI_STATIC,
  .tensors = &conv2d_1_chain, 
  .groups = 1, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_2D_INIT(0, 0), 
)

/* Layer #1: "batch_normalization_1" (ScaleBias) */
  

/* Weight tensor #1 */
AI_ARRAY_OBJ_DECLARE(
  batch_normalization_1_scale_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 28,
  AI_STATIC)

AI_TENSOR_OBJ_DECLARE(
  batch_normalization_1_scale,
  AI_SHAPE_INIT(1, 1, 28, 1),
  AI_STRIDE_INIT(112, 112, 4, 4),
  &batch_normalization_1_scale_array,
  AI_STATIC)

/* Weight tensor #2 */
AI_ARRAY_OBJ_DECLARE(
  batch_normalization_1_bias_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 28,
  AI_STATIC)

AI_TENSOR_OBJ_DECLARE(
  batch_normalization_1_bias,
  AI_SHAPE_INIT(1, 1, 28, 1),
  AI_STRIDE_INIT(112, 112, 4, 4),
  &batch_normalization_1_bias_array,
  AI_STATIC)


AI_TENSOR_CHAIN_OBJ_DECLARE(
  batch_normalization_1_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv2d_1_output),
  AI_TENSOR_LIST_ENTRY(&batch_normalization_1_output),
  AI_TENSOR_LIST_ENTRY(&batch_normalization_1_scale, &batch_normalization_1_bias),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  batch_normalization_1_layer, 1,
  BN_TYPE,
  bn, forward_bn,
  &AI_NET_OBJ_INSTANCE, &conv2d_2_layer, AI_STATIC,
  .tensors = &batch_normalization_1_chain, 
)

/* Layer #2: "conv2d_2" (Conv2D) */
  

/* Weight tensor #1 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_weights_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 33600,
  AI_STATIC)

AI_TENSOR_OBJ_DECLARE(
  conv2d_2_weights,
  AI_SHAPE_INIT(30, 10, 4, 28),
  AI_STRIDE_INIT(4480, 448, 112, 4),
  &conv2d_2_weights_array,
  AI_STATIC)

/* Weight tensor #2 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_bias_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 30,
  AI_STATIC)

AI_TENSOR_OBJ_DECLARE(
  conv2d_2_bias,
  AI_SHAPE_INIT(1, 1, 30, 1),
  AI_STRIDE_INIT(120, 120, 4, 4),
  &conv2d_2_bias_array,
  AI_STATIC)


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_2_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&batch_normalization_1_output),
  AI_TENSOR_LIST_ENTRY(&conv2d_2_output),
  AI_TENSOR_LIST_ENTRY(&conv2d_2_weights, &conv2d_2_bias),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_2_layer, 2,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &batch_normalization_2_layer, AI_STATIC,
  .tensors = &conv2d_2_chain, 
  .groups = 1, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 1), 
  .filter_pad = AI_SHAPE_2D_INIT(0, 0), 
)

/* Layer #3: "batch_normalization_2" (ScaleBias) */
  

/* Weight tensor #1 */
AI_ARRAY_OBJ_DECLARE(
  batch_normalization_2_scale_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 30,
  AI_STATIC)

AI_TENSOR_OBJ_DECLARE(
  batch_normalization_2_scale,
  AI_SHAPE_INIT(1, 1, 30, 1),
  AI_STRIDE_INIT(120, 120, 4, 4),
  &batch_normalization_2_scale_array,
  AI_STATIC)

/* Weight tensor #2 */
AI_ARRAY_OBJ_DECLARE(
  batch_normalization_2_bias_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 30,
  AI_STATIC)

AI_TENSOR_OBJ_DECLARE(
  batch_normalization_2_bias,
  AI_SHAPE_INIT(1, 1, 30, 1),
  AI_STRIDE_INIT(120, 120, 4, 4),
  &batch_normalization_2_bias_array,
  AI_STATIC)


AI_TENSOR_CHAIN_OBJ_DECLARE(
  batch_normalization_2_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv2d_2_output),
  AI_TENSOR_LIST_ENTRY(&batch_normalization_2_output_in),
  AI_TENSOR_LIST_ENTRY(&batch_normalization_2_scale, &batch_normalization_2_bias),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  batch_normalization_2_layer, 3,
  BN_TYPE,
  bn, forward_bn,
  &AI_NET_OBJ_INSTANCE, &dense_1_layer, AI_STATIC,
  .tensors = &batch_normalization_2_chain, 
)

/* Layer #4: "dense_1" (Dense) */
  

/* Weight tensor #1 */
AI_ARRAY_OBJ_DECLARE(
  dense_1_weights_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 30720,
  AI_STATIC)

AI_TENSOR_OBJ_DECLARE(
  dense_1_weights,
  AI_SHAPE_INIT(1, 1, 16, 1920),
  AI_STRIDE_INIT(122880, 122880, 7680, 4),
  &dense_1_weights_array,
  AI_STATIC)

/* Weight tensor #2 */
AI_ARRAY_OBJ_DECLARE(
  dense_1_bias_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 16,
  AI_STATIC)

AI_TENSOR_OBJ_DECLARE(
  dense_1_bias,
  AI_SHAPE_INIT(1, 1, 16, 1),
  AI_STRIDE_INIT(64, 64, 4, 4),
  &dense_1_bias_array,
  AI_STATIC)


AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_1_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&batch_normalization_2_output_out),
  AI_TENSOR_LIST_ENTRY(&dense_1_output),
  AI_TENSOR_LIST_ENTRY(&dense_1_weights, &dense_1_bias),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_1_layer, 5,
  DENSE_TYPE,
  dense, forward_dense,
  &AI_NET_OBJ_INSTANCE, &dense_2_layer, AI_STATIC,
  .tensors = &dense_1_chain, 
)

/* Layer #5: "dense_2" (Dense) */
  

/* Weight tensor #1 */
AI_ARRAY_OBJ_DECLARE(
  dense_2_weights_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 2048,
  AI_STATIC)

AI_TENSOR_OBJ_DECLARE(
  dense_2_weights,
  AI_SHAPE_INIT(1, 1, 128, 16),
  AI_STRIDE_INIT(8192, 8192, 64, 4),
  &dense_2_weights_array,
  AI_STATIC)

/* Weight tensor #2 */
AI_ARRAY_OBJ_DECLARE(
  dense_2_bias_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 128,
  AI_STATIC)

AI_TENSOR_OBJ_DECLARE(
  dense_2_bias,
  AI_SHAPE_INIT(1, 1, 128, 1),
  AI_STRIDE_INIT(512, 512, 4, 4),
  &dense_2_bias_array,
  AI_STATIC)


AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_2_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&dense_1_output),
  AI_TENSOR_LIST_ENTRY(&dense_2_output),
  AI_TENSOR_LIST_ENTRY(&dense_2_weights, &dense_2_bias),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_2_layer, 6,
  DENSE_TYPE,
  dense, forward_dense,
  &AI_NET_OBJ_INSTANCE, &dense_2_nl_layer, AI_STATIC,
  .tensors = &dense_2_chain, 
)

/* Layer #6: "dense_2_nl" (Nonlinearity) */
  


AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_2_nl_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&dense_2_output),
  AI_TENSOR_LIST_ENTRY(&dense_2_nl_output),
  AI_TENSOR_LIST_EMPTY,
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_2_nl_layer, 6,
  NL_TYPE,
  nl, forward_relu,
  &AI_NET_OBJ_INSTANCE, &dense_3_layer, AI_STATIC,
  .tensors = &dense_2_nl_chain, 
)

/* Layer #7: "dense_3" (Dense) */
  

/* Weight tensor #1 */
AI_ARRAY_OBJ_DECLARE(
  dense_3_weights_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 1536,
  AI_STATIC)

AI_TENSOR_OBJ_DECLARE(
  dense_3_weights,
  AI_SHAPE_INIT(1, 1, 12, 128),
  AI_STRIDE_INIT(6144, 6144, 512, 4),
  &dense_3_weights_array,
  AI_STATIC)

/* Weight tensor #2 */
AI_ARRAY_OBJ_DECLARE(
  dense_3_bias_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 12,
  AI_STATIC)

AI_TENSOR_OBJ_DECLARE(
  dense_3_bias,
  AI_SHAPE_INIT(1, 1, 12, 1),
  AI_STRIDE_INIT(48, 48, 4, 4),
  &dense_3_bias_array,
  AI_STATIC)


AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_3_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&dense_2_nl_output),
  AI_TENSOR_LIST_ENTRY(&dense_3_output),
  AI_TENSOR_LIST_ENTRY(&dense_3_weights, &dense_3_bias),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_3_layer, 7,
  DENSE_TYPE,
  dense, forward_dense,
  &AI_NET_OBJ_INSTANCE, &dense_3_nl_layer, AI_STATIC,
  .tensors = &dense_3_chain, 
)

/* Layer #8: "dense_3_nl" (Nonlinearity) */
  


AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_3_nl_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&dense_3_output),
  AI_TENSOR_LIST_ENTRY(&dense_3_nl_output),
  AI_TENSOR_LIST_EMPTY,
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_3_nl_layer, 7,
  SM_TYPE,
  sm, forward_sm,
  &AI_NET_OBJ_INSTANCE, &dense_3_nl_layer, AI_STATIC,
  .tensors = &dense_3_nl_chain, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 277416, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 39044, 1,
                     NULL),
  &input_0_output, &dense_3_nl_output,
  &conv2d_1_layer, 0)


AI_DECLARE_STATIC
ai_bool cnn_configure_activations(
  ai_network* net_ctx, const ai_buffer* activation_buffer)
{
  AI_ASSERT(net_ctx &&  activation_buffer && activation_buffer->data)

  ai_ptr activations = AI_PTR(AI_PTR_ALIGN(activation_buffer->data, 4));
  AI_ASSERT( activations )
  AI_FLAG_SET(net_ctx->flags, AI_NETWORK_FLAG_OUT_COPY);

  {
    /* Updating activations (byte) offsets */
    input_0_output_array.data = NULL;
  input_0_output_array.data_start = NULL;
  conv2d_1_output_array.data = activations + 0;
  conv2d_1_output_array.data_start = activations + 0;
  batch_normalization_1_output_array.data = activations + 0;
  batch_normalization_1_output_array.data_start = activations + 0;
  conv2d_2_output_array.data = activations + 31360;
  conv2d_2_output_array.data_start = activations + 31360;
  batch_normalization_2_output_in_array.data = activations + 31360;
  batch_normalization_2_output_in_array.data_start = activations + 31360;
  batch_normalization_2_output_out_array.data = activations + 31360;
  batch_normalization_2_output_out_array.data_start = activations + 31360;
  dense_1_output_array.data = activations + 0;
  dense_1_output_array.data_start = activations + 0;
  dense_2_output_array.data = activations + 64;
  dense_2_output_array.data_start = activations + 64;
  dense_2_nl_output_array.data = activations + 64;
  dense_2_nl_output_array.data_start = activations + 64;
  dense_3_output_array.data = activations + 0;
  dense_3_output_array.data_start = activations + 0;
  dense_3_nl_output_array.data = activations + 0;
  dense_3_nl_output_array.data_start = activations + 0;
  
  }
  return true;
}

AI_DECLARE_STATIC
ai_bool cnn_configure_weights(
  ai_network* net_ctx, const ai_buffer* weights_buffer)
{
  AI_ASSERT(net_ctx &&  weights_buffer && weights_buffer->data)

  ai_ptr weights = AI_PTR(weights_buffer->data);
  AI_ASSERT( weights )

  {
    /* Updating weights (byte) offsets */
    conv2d_1_weights_array.format |= AI_FMT_FLAG_CONST;
  conv2d_1_weights_array.data = weights + 0;
  conv2d_1_weights_array.data_start = weights + 0;
  conv2d_1_bias_array.format |= AI_FMT_FLAG_CONST;
  conv2d_1_bias_array.data = weights + 4480;
  conv2d_1_bias_array.data_start = weights + 4480;
  batch_normalization_1_scale_array.format |= AI_FMT_FLAG_CONST;
  batch_normalization_1_scale_array.data = weights + 4592;
  batch_normalization_1_scale_array.data_start = weights + 4592;
  batch_normalization_1_bias_array.format |= AI_FMT_FLAG_CONST;
  batch_normalization_1_bias_array.data = weights + 4704;
  batch_normalization_1_bias_array.data_start = weights + 4704;
  conv2d_2_weights_array.format |= AI_FMT_FLAG_CONST;
  conv2d_2_weights_array.data = weights + 4816;
  conv2d_2_weights_array.data_start = weights + 4816;
  conv2d_2_bias_array.format |= AI_FMT_FLAG_CONST;
  conv2d_2_bias_array.data = weights + 139216;
  conv2d_2_bias_array.data_start = weights + 139216;
  batch_normalization_2_scale_array.format |= AI_FMT_FLAG_CONST;
  batch_normalization_2_scale_array.data = weights + 139336;
  batch_normalization_2_scale_array.data_start = weights + 139336;
  batch_normalization_2_bias_array.format |= AI_FMT_FLAG_CONST;
  batch_normalization_2_bias_array.data = weights + 139456;
  batch_normalization_2_bias_array.data_start = weights + 139456;
  dense_1_weights_array.format |= AI_FMT_FLAG_CONST;
  dense_1_weights_array.data = weights + 139576;
  dense_1_weights_array.data_start = weights + 139576;
  dense_1_bias_array.format |= AI_FMT_FLAG_CONST;
  dense_1_bias_array.data = weights + 262456;
  dense_1_bias_array.data_start = weights + 262456;
  dense_2_weights_array.format |= AI_FMT_FLAG_CONST;
  dense_2_weights_array.data = weights + 262520;
  dense_2_weights_array.data_start = weights + 262520;
  dense_2_bias_array.format |= AI_FMT_FLAG_CONST;
  dense_2_bias_array.data = weights + 270712;
  dense_2_bias_array.data_start = weights + 270712;
  dense_3_weights_array.format |= AI_FMT_FLAG_CONST;
  dense_3_weights_array.data = weights + 271224;
  dense_3_weights_array.data_start = weights + 271224;
  dense_3_bias_array.format |= AI_FMT_FLAG_CONST;
  dense_3_bias_array.data = weights + 277368;
  dense_3_bias_array.data_start = weights + 277368;
  
  }

  return true;
}

/**  PUBLIC APIs SECTION  *****************************************************/

AI_API_ENTRY
ai_bool ai_cnn_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if ( report && net_ctx )
  {
    ai_network_report r = {
      .model_name        = AI_CNN_MODEL_NAME,
      .model_signature   = AI_CNN_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = {AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR,
                            AI_TOOLS_API_VERSION_MICRO, 0x0},

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 2527950,
      .n_inputs          = AI_CNN_IN_NUM,
      .inputs            = AI_BUFFER_OBJ_INIT(
                              AI_BUFFER_FORMAT_FLOAT,
                              49,
                              10,
                              1,
                              1, NULL),
      .n_outputs         = AI_CNN_OUT_NUM,
      .outputs           = AI_BUFFER_OBJ_INIT(
                              AI_BUFFER_FORMAT_FLOAT,
                              1,
                              1,
                              12,
                              1, NULL),
      .activations       = net_ctx->activations,
      .weights           = net_ctx->params,
      .n_nodes           = 0,
      .signature         = net_ctx->signature,
    };

    AI_FOR_EACH_NODE_DO(node, net_ctx->input_node)
    {
      r.n_nodes++;
    }

    *report = r;

    return ( r.n_nodes>0 ) ? true : false;
  }
  
  return false;
}

AI_API_ENTRY
ai_error ai_cnn_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_cnn_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_handle ai_cnn_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_cnn_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if ( !net_ctx ) return false;

  ai_bool ok = true;
  ok &= cnn_configure_weights(net_ctx, &params->params);
  ok &= cnn_configure_activations(net_ctx, &params->activations);
  
  return ok;
}


AI_API_ENTRY
ai_i32 ai_cnn_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_cnn_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}

#undef AI_CNN_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

