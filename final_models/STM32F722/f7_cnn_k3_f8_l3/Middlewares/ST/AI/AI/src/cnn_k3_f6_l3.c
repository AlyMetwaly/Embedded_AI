/**
  ******************************************************************************
  * @file    cnn_k3_f6_l3.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Thu Aug 22 12:03:43 2019
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



#include "cnn_k3_f6_l3.h"

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
#define AI_NET_OBJ_INSTANCE g_cnn_k3_f6_l3
 
#undef AI_CNN_K3_F6_L3_MODEL_SIGNATURE
#define AI_CNN_K3_F6_L3_MODEL_SIGNATURE     "68e6523016eb905145563906e1e5b8ea"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     "(rev-)"
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Thu Aug 22 12:03:43 2019"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_CNN_K3_F6_L3_N_BATCHES
#define AI_CNN_K3_F6_L3_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network arrays declarations  *************************************/
AI_STATIC ai_array input_0_output_array;   /* Array #0 */
AI_STATIC ai_array conv2d_24_output_array;   /* Array #1 */
AI_STATIC ai_array conv2d_25_output_array;   /* Array #2 */
AI_STATIC ai_array conv2d_26_output_in_array;   /* Array #3 */
AI_STATIC ai_array conv2d_26_output_out_array;   /* Array #4 */
AI_STATIC ai_array dense_11_output_array;   /* Array #5 */
AI_STATIC ai_array dense_11_nl_output_array;   /* Array #6 */


/**  Forward network tensors declarations  ************************************/
AI_STATIC ai_tensor input_0_output;   /* Tensor #0 */
AI_STATIC ai_tensor conv2d_24_output;   /* Tensor #1 */
AI_STATIC ai_tensor conv2d_25_output;   /* Tensor #2 */
AI_STATIC ai_tensor conv2d_26_output_in;   /* Tensor #3 */
AI_STATIC ai_tensor conv2d_26_output_out;   /* Tensor #4 */
AI_STATIC ai_tensor dense_11_output;   /* Tensor #5 */
AI_STATIC ai_tensor dense_11_nl_output;   /* Tensor #6 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain conv2d_24_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain conv2d_25_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain conv2d_26_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain dense_11_chain;   /* Chain #3 */
AI_STATIC_CONST ai_tensor_chain dense_11_nl_chain;   /* Chain #4 */


/**  Subgraph network operators tensor chain declarations  *********************************/


/**  Subgraph network operators declarations  *********************************/


/**  Forward network layers declarations  *************************************/
AI_STATIC ai_layer_conv2d conv2d_24_layer; /* Layer #0 */
AI_STATIC ai_layer_conv2d conv2d_25_layer; /* Layer #1 */
AI_STATIC ai_layer_conv2d conv2d_26_layer; /* Layer #2 */
AI_STATIC ai_layer_dense dense_11_layer; /* Layer #3 */
AI_STATIC ai_layer_nl dense_11_nl_layer; /* Layer #4 */


/**  Arrays declarations section  *********************************************/
AI_ARRAY_OBJ_DECLARE(
  input_0_output_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 768,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_output_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 5280,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_output_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 4480,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_output_in_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 3744,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_output_out_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 3744,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  dense_11_output_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 1,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  dense_11_nl_output_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 1,
  AI_STATIC)


/**  Activations tensors declaration section  *********************************/
AI_TENSOR_OBJ_DECLARE(
  input_0_output,
  AI_SHAPE_INIT(24, 32, 1, 1),
  AI_STRIDE_INIT(128, 4, 4, 4),
  &input_0_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_output,
  AI_SHAPE_INIT(22, 30, 8, 1),
  AI_STRIDE_INIT(960, 32, 4, 4),
  &conv2d_24_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_output,
  AI_SHAPE_INIT(20, 28, 8, 1),
  AI_STRIDE_INIT(896, 32, 4, 4),
  &conv2d_25_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_output_in,
  AI_SHAPE_INIT(18, 26, 8, 1),
  AI_STRIDE_INIT(832, 32, 4, 4),
  &conv2d_26_output_in_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_output_out,
  AI_SHAPE_INIT(1, 1, 3744, 1),
  AI_STRIDE_INIT(14976, 14976, 4, 4),
  &conv2d_26_output_out_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  dense_11_output,
  AI_SHAPE_INIT(1, 1, 1, 1),
  AI_STRIDE_INIT(4, 4, 4, 4),
  &dense_11_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  dense_11_nl_output,
  AI_SHAPE_INIT(1, 1, 1, 1),
  AI_STRIDE_INIT(4, 4, 4, 4),
  &dense_11_nl_output_array,
  AI_STATIC)





/* Layer #0: "conv2d_24" (Conv2D) */
  

/* Weight tensor #1 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_weights_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 72,
  AI_STATIC)

AI_TENSOR_OBJ_DECLARE(
  conv2d_24_weights,
  AI_SHAPE_INIT(8, 3, 3, 1),
  AI_STRIDE_INIT(36, 12, 4, 4),
  &conv2d_24_weights_array,
  AI_STATIC)

/* Weight tensor #2 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_bias_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 8,
  AI_STATIC)

AI_TENSOR_OBJ_DECLARE(
  conv2d_24_bias,
  AI_SHAPE_INIT(1, 1, 8, 1),
  AI_STRIDE_INIT(32, 32, 4, 4),
  &conv2d_24_bias_array,
  AI_STATIC)


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_24_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&input_0_output),
  AI_TENSOR_LIST_ENTRY(&conv2d_24_output),
  AI_TENSOR_LIST_ENTRY(&conv2d_24_weights, &conv2d_24_bias),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_24_layer, 0,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_25_layer, AI_STATIC,
  .tensors = &conv2d_24_chain, 
  .groups = 1, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_2D_INIT(0, 0), 
)

/* Layer #1: "conv2d_25" (Conv2D) */
  

/* Weight tensor #1 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_weights_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 576,
  AI_STATIC)

AI_TENSOR_OBJ_DECLARE(
  conv2d_25_weights,
  AI_SHAPE_INIT(8, 3, 3, 8),
  AI_STRIDE_INIT(288, 96, 32, 4),
  &conv2d_25_weights_array,
  AI_STATIC)

/* Weight tensor #2 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_bias_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 8,
  AI_STATIC)

AI_TENSOR_OBJ_DECLARE(
  conv2d_25_bias,
  AI_SHAPE_INIT(1, 1, 8, 1),
  AI_STRIDE_INIT(32, 32, 4, 4),
  &conv2d_25_bias_array,
  AI_STATIC)


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_25_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv2d_24_output),
  AI_TENSOR_LIST_ENTRY(&conv2d_25_output),
  AI_TENSOR_LIST_ENTRY(&conv2d_25_weights, &conv2d_25_bias),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_25_layer, 2,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_26_layer, AI_STATIC,
  .tensors = &conv2d_25_chain, 
  .groups = 1, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_2D_INIT(0, 0), 
)

/* Layer #2: "conv2d_26" (Conv2D) */
  

/* Weight tensor #1 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_weights_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 576,
  AI_STATIC)

AI_TENSOR_OBJ_DECLARE(
  conv2d_26_weights,
  AI_SHAPE_INIT(8, 3, 3, 8),
  AI_STRIDE_INIT(288, 96, 32, 4),
  &conv2d_26_weights_array,
  AI_STATIC)

/* Weight tensor #2 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_bias_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 8,
  AI_STATIC)

AI_TENSOR_OBJ_DECLARE(
  conv2d_26_bias,
  AI_SHAPE_INIT(1, 1, 8, 1),
  AI_STRIDE_INIT(32, 32, 4, 4),
  &conv2d_26_bias_array,
  AI_STATIC)


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_26_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv2d_25_output),
  AI_TENSOR_LIST_ENTRY(&conv2d_26_output_in),
  AI_TENSOR_LIST_ENTRY(&conv2d_26_weights, &conv2d_26_bias),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_26_layer, 4,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &dense_11_layer, AI_STATIC,
  .tensors = &conv2d_26_chain, 
  .groups = 1, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_2D_INIT(0, 0), 
)

/* Layer #3: "dense_11" (Dense) */
  

/* Weight tensor #1 */
AI_ARRAY_OBJ_DECLARE(
  dense_11_weights_array, AI_DATA_FORMAT_LUT4_FLOAT, 
  NULL, NULL, 3744,
  AI_STATIC)

AI_TENSOR_OBJ_DECLARE(
  dense_11_weights,
  AI_SHAPE_INIT(1, 1, 1, 3744),
  AI_STRIDE_INIT(1872, 1872, 1872, 1),
  &dense_11_weights_array,
  AI_STATIC)

/* Weight tensor #2 */
AI_ARRAY_OBJ_DECLARE(
  dense_11_bias_array, AI_DATA_FORMAT_FLOAT, 
  NULL, NULL, 1,
  AI_STATIC)

AI_TENSOR_OBJ_DECLARE(
  dense_11_bias,
  AI_SHAPE_INIT(1, 1, 1, 1),
  AI_STRIDE_INIT(4, 4, 4, 4),
  &dense_11_bias_array,
  AI_STATIC)


AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_11_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv2d_26_output_out),
  AI_TENSOR_LIST_ENTRY(&dense_11_output),
  AI_TENSOR_LIST_ENTRY(&dense_11_weights, &dense_11_bias),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_11_layer, 7,
  DENSE_TYPE,
  dense, forward_dense,
  &AI_NET_OBJ_INSTANCE, &dense_11_nl_layer, AI_STATIC,
  .tensors = &dense_11_chain, 
)

/* Layer #4: "dense_11_nl" (Nonlinearity) */
  


AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_11_nl_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&dense_11_output),
  AI_TENSOR_LIST_ENTRY(&dense_11_nl_output),
  AI_TENSOR_LIST_EMPTY,
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_11_nl_layer, 7,
  NL_TYPE,
  nl, forward_relu,
  &AI_NET_OBJ_INSTANCE, &dense_11_nl_layer, AI_STATIC,
  .tensors = &dense_11_nl_chain, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 6932, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 39044, 1,
                     NULL),
  &input_0_output, &dense_11_nl_output,
  &conv2d_24_layer, 0)


AI_DECLARE_STATIC
ai_bool cnn_k3_f6_l3_configure_activations(
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
  conv2d_24_output_array.data = activations + 0;
  conv2d_24_output_array.data_start = activations + 0;
  conv2d_25_output_array.data = activations + 21120;
  conv2d_25_output_array.data_start = activations + 21120;
  conv2d_26_output_in_array.data = activations + 0;
  conv2d_26_output_in_array.data_start = activations + 0;
  conv2d_26_output_out_array.data = activations + 0;
  conv2d_26_output_out_array.data_start = activations + 0;
  dense_11_output_array.data = activations + 14976;
  dense_11_output_array.data_start = activations + 14976;
  dense_11_nl_output_array.data = activations + 14976;
  dense_11_nl_output_array.data_start = activations + 14976;
  
  }
  return true;
}

AI_DECLARE_STATIC
ai_bool cnn_k3_f6_l3_configure_weights(
  ai_network* net_ctx, const ai_buffer* weights_buffer)
{
  AI_ASSERT(net_ctx &&  weights_buffer && weights_buffer->data)

  ai_ptr weights = AI_PTR(weights_buffer->data);
  AI_ASSERT( weights )

  {
    /* Updating weights (byte) offsets */
    conv2d_24_weights_array.format |= AI_FMT_FLAG_CONST;
  conv2d_24_weights_array.data = weights + 0;
  conv2d_24_weights_array.data_start = weights + 0;
  conv2d_24_bias_array.format |= AI_FMT_FLAG_CONST;
  conv2d_24_bias_array.data = weights + 288;
  conv2d_24_bias_array.data_start = weights + 288;
  conv2d_25_weights_array.format |= AI_FMT_FLAG_CONST;
  conv2d_25_weights_array.data = weights + 320;
  conv2d_25_weights_array.data_start = weights + 320;
  conv2d_25_bias_array.format |= AI_FMT_FLAG_CONST;
  conv2d_25_bias_array.data = weights + 2624;
  conv2d_25_bias_array.data_start = weights + 2624;
  conv2d_26_weights_array.format |= AI_FMT_FLAG_CONST;
  conv2d_26_weights_array.data = weights + 2656;
  conv2d_26_weights_array.data_start = weights + 2656;
  conv2d_26_bias_array.format |= AI_FMT_FLAG_CONST;
  conv2d_26_bias_array.data = weights + 4960;
  conv2d_26_bias_array.data_start = weights + 4960;
  dense_11_weights_array.format |= AI_FMT_FLAG_CONST;
  dense_11_weights_array.data = weights + 4992;
  dense_11_weights_array.data_start = weights + 6864;
  dense_11_bias_array.format |= AI_FMT_FLAG_CONST;
  dense_11_bias_array.data = weights + 6928;
  dense_11_bias_array.data_start = weights + 6928;
  
  }

  return true;
}

/**  PUBLIC APIs SECTION  *****************************************************/

AI_API_ENTRY
ai_bool ai_cnn_k3_f6_l3_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if ( report && net_ctx )
  {
    ai_network_report r = {
      .model_name        = AI_CNN_K3_F6_L3_MODEL_NAME,
      .model_signature   = AI_CNN_K3_F6_L3_MODEL_SIGNATURE,
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
      
      .n_macc            = 656921,
      .n_inputs          = AI_CNN_K3_F6_L3_IN_NUM,
      .inputs            = AI_BUFFER_OBJ_INIT(
                              AI_BUFFER_FORMAT_FLOAT,
                              24,
                              32,
                              1,
                              1, NULL),
      .n_outputs         = AI_CNN_K3_F6_L3_OUT_NUM,
      .outputs           = AI_BUFFER_OBJ_INIT(
                              AI_BUFFER_FORMAT_FLOAT,
                              1,
                              1,
                              1,
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
ai_error ai_cnn_k3_f6_l3_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_cnn_k3_f6_l3_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_handle ai_cnn_k3_f6_l3_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_cnn_k3_f6_l3_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if ( !net_ctx ) return false;

  ai_bool ok = true;
  ok &= cnn_k3_f6_l3_configure_weights(net_ctx, &params->params);
  ok &= cnn_k3_f6_l3_configure_activations(net_ctx, &params->activations);
  
  return ok;
}


AI_API_ENTRY
ai_i32 ai_cnn_k3_f6_l3_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_cnn_k3_f6_l3_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}

#undef AI_CNN_K3_F6_L3_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

