################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/zlstudio/workspace/LePlasma/Socket/inet.cpp 

OBJS += \
./Socket/inet.o 

CPP_DEPS += \
./Socket/inet.d 


# Each subdirectory must supply rules for building sources it contributes
Socket/inet.o: /home/zlstudio/workspace/LePlasma/Socket/inet.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/zlstudio/workspace/LePlasma/Socket" -I"/home/zlstudio/workspace/Transmitter/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


