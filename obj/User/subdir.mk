################################################################################
# MRS Version: 1.9.1
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/ch32v00x_it.c \
../User/main.c \
../User/system_ch32v00x.c \
../User/systick_delay.c 

OBJS += \
./User/ch32v00x_it.o \
./User/main.o \
./User/system_ch32v00x.o \
./User/systick_delay.o 

C_DEPS += \
./User/ch32v00x_it.d \
./User/main.d \
./User/system_ch32v00x.d \
./User/systick_delay.d 


# Each subdirectory must supply rules for building sources it contributes
User/%.o: ../User/%.c
	@	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\SourceCode\MRS\CH32V003F4P6_Servo\Core" -I"E:\SourceCode\MRS\CH32V003F4P6_Servo\User" -I"E:\SourceCode\MRS\CH32V003F4P6_Servo\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

