################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP.c \
../DIO_Prog.c \
../EEPROM_prog.c \
../I2C_Prog.c 

OBJS += \
./APP.o \
./DIO_Prog.o \
./EEPROM_prog.o \
./I2C_Prog.o 

C_DEPS += \
./APP.d \
./DIO_Prog.d \
./EEPROM_prog.d \
./I2C_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


