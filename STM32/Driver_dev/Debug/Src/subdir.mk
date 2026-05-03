################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Gpio_Toggle.c \
../Src/Gpioint.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/Gpio_Toggle.o \
./Src/Gpioint.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/Gpio_Toggle.d \
./Src/Gpioint.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"/Users/nilaNila/Desktop/STM32/Driver_dev/Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/Gpio_Toggle.cyclo ./Src/Gpio_Toggle.d ./Src/Gpio_Toggle.o ./Src/Gpio_Toggle.su ./Src/Gpioint.cyclo ./Src/Gpioint.d ./Src/Gpioint.o ./Src/Gpioint.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

