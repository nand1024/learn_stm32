################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32.s 

OBJS += \
./startup/startup_stm32.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -I"C:/Users/Oleg/workspace/smt32f103rbt6_freeRtos_uartDeb/HAL_Driver/Inc/Legacy" -I"C:/Users/Oleg/workspace/smt32f103rbt6_freeRtos_uartDeb/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/Oleg/workspace/smt32f103rbt6_freeRtos_uartDeb/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3" -I"C:/Users/Oleg/workspace/smt32f103rbt6_freeRtos_uartDeb/inc" -I"C:/Users/Oleg/workspace/smt32f103rbt6_freeRtos_uartDeb/CMSIS/device" -I"C:/Users/Oleg/workspace/smt32f103rbt6_freeRtos_uartDeb/CMSIS/core" -I"C:/Users/Oleg/workspace/smt32f103rbt6_freeRtos_uartDeb/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/Oleg/workspace/smt32f103rbt6_freeRtos_uartDeb/HAL_Driver/Inc" -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


