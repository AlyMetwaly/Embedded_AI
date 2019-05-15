################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_f32.c 

OBJS += \
./Drivers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_f32.o 

C_DEPS += \
./Drivers/CMSIS/DSP/Source/BasicMathFunctions/arm_dot_prod_f32.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/DSP/Source/BasicMathFunctions/%.o: ../Drivers/CMSIS/DSP/Source/BasicMathFunctions/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DARM_MATH_CM7 '-D__FPU_PRESENT=1' -DUSE_HAL_DRIVER -DSTM32F722xx -I"/Users/metwaly_aly/STM32Cube/projects/F7_SP_test_2/Inc" -I"/Users/metwaly_aly/STM32Cube/projects/F7_SP_test_2/Middlewares/ST/AI/AI/include" -I"/Users/metwaly_aly/STM32Cube/projects/F7_SP_test_2/Middlewares/ST/AI/AI/data" -I"/Users/metwaly_aly/STM32Cube/projects/F7_SP_test_2/Drivers/CMSIS/DSP/Include" -I"/Users/metwaly_aly/STM32Cube/projects/F7_SP_test_2/Drivers/STM32F7xx_HAL_Driver/Inc" -I"/Users/metwaly_aly/STM32Cube/projects/F7_SP_test_2/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"/Users/metwaly_aly/STM32Cube/projects/F7_SP_test_2/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"/Users/metwaly_aly/STM32Cube/projects/F7_SP_test_2/Drivers/CMSIS/Include" -I"/Users/metwaly_aly/STM32Cube/projects/F7_SP_test_2/Middlewares/ST/Application/SystemPerformance/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


