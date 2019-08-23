################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ST/AI/AI/src/gru_l1_n12.c 

OBJS += \
./Middlewares/ST/AI/AI/src/gru_l1_n12.o 

C_DEPS += \
./Middlewares/ST/AI/AI/src/gru_l1_n12.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/AI/AI/src/%.o: ../Middlewares/ST/AI/AI/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DARM_MATH_CM7 '-D__FPU_PRESENT=1' -DUSE_HAL_DRIVER -DSTM32F722xx -I"/Users/metwaly_aly/OneDrive - Helvar Oy Ab/final_projects/f7/f7_gru_l1_n12/Inc" -I"/Users/metwaly_aly/OneDrive - Helvar Oy Ab/final_projects/f7/f7_gru_l1_n12/Middlewares/ST/AI/AI/data" -I"/Users/metwaly_aly/OneDrive - Helvar Oy Ab/final_projects/f7/f7_gru_l1_n12/Middlewares/ST/AI/AI/include" -I"/Users/metwaly_aly/OneDrive - Helvar Oy Ab/final_projects/f7/f7_gru_l1_n12/Drivers/CMSIS/DSP/Include" -I"/Users/metwaly_aly/OneDrive - Helvar Oy Ab/final_projects/f7/f7_gru_l1_n12/Drivers/STM32F7xx_HAL_Driver/Inc" -I"/Users/metwaly_aly/OneDrive - Helvar Oy Ab/final_projects/f7/f7_gru_l1_n12/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"/Users/metwaly_aly/OneDrive - Helvar Oy Ab/final_projects/f7/f7_gru_l1_n12/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"/Users/metwaly_aly/OneDrive - Helvar Oy Ab/final_projects/f7/f7_gru_l1_n12/Drivers/CMSIS/Include" -I"/Users/metwaly_aly/OneDrive - Helvar Oy Ab/final_projects/f7/f7_gru_l1_n12/Middlewares/ST/Application/SystemPerformance/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


