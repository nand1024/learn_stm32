################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3/port.c 

OBJS += \
./Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3/port.o 

C_DEPS += \
./Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3/port.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3/%.o: ../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32 -DSTM32F1 -DSTM32F103RBTx -DDEBUG -DSTM32F103xB -DUSE_HAL_DRIVER -DUSE_RTOS_SYSTICK -I"C:/Users/Oleg/workspace/smt32f103rbt6_freeRtos_uartDeb/HAL_Driver/Inc/Legacy" -I"C:/Users/Oleg/workspace/smt32f103rbt6_freeRtos_uartDeb/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/Oleg/workspace/smt32f103rbt6_freeRtos_uartDeb/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3" -I"C:/Users/Oleg/workspace/smt32f103rbt6_freeRtos_uartDeb/inc" -I"C:/Users/Oleg/workspace/smt32f103rbt6_freeRtos_uartDeb/CMSIS/device" -I"C:/Users/Oleg/workspace/smt32f103rbt6_freeRtos_uartDeb/CMSIS/core" -I"C:/Users/Oleg/workspace/smt32f103rbt6_freeRtos_uartDeb/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/Oleg/workspace/smt32f103rbt6_freeRtos_uartDeb/HAL_Driver/Inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


