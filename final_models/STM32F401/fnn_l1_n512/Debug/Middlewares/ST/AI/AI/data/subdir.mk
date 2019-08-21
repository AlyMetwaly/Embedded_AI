################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ST/AI/AI/data/fnn_l1_n512_data.c 

OBJS += \
./Middlewares/ST/AI/AI/data/fnn_l1_n512_data.o 

C_DEPS += \
./Middlewares/ST/AI/AI/data/fnn_l1_n512_data.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/AI/AI/data/%.o: ../Middlewares/ST/AI/AI/data/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DARM_MATH_CM4 '-D__FPU_PRESENT=1U' -DUSE_HAL_DRIVER -DSTM32F401xE -I"/Users/metwaly_aly/OneDrive - Helvar Oy Ab/final_projects/f4/fnn_l1_n512/Inc" -I"/Users/metwaly_aly/OneDrive - Helvar Oy Ab/final_projects/f4/fnn_l1_n512/Middlewares/ST/AI/AI/include" -I"/Users/metwaly_aly/OneDrive - Helvar Oy Ab/final_projects/f4/fnn_l1_n512/Middlewares/ST/AI/AI/data" -I"/Users/metwaly_aly/OneDrive - Helvar Oy Ab/final_projects/f4/fnn_l1_n512/Drivers/CMSIS/DSP/Include" -I"/Users/metwaly_aly/OneDrive - Helvar Oy Ab/final_projects/f4/fnn_l1_n512/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/Users/metwaly_aly/OneDrive - Helvar Oy Ab/final_projects/f4/fnn_l1_n512/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/Users/metwaly_aly/OneDrive - Helvar Oy Ab/final_projects/f4/fnn_l1_n512/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/Users/metwaly_aly/OneDrive - Helvar Oy Ab/final_projects/f4/fnn_l1_n512/Drivers/CMSIS/Include" -I"/Users/metwaly_aly/OneDrive - Helvar Oy Ab/final_projects/f4/fnn_l1_n512/Middlewares/ST/Application/SystemPerformance/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


