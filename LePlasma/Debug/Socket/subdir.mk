################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Socket/inet.cpp 

OBJS += \
./Socket/inet.o 

CPP_DEPS += \
./Socket/inet.d 


# Each subdirectory must supply rules for building sources it contributes
Socket/%.o: ../Socket/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	mpic++ -I"/home/ylang/workspace/LePlasma/include" -I"/home/ylang/workspace/LePlasma/Socket" -I"/home/ylang/workspace/LePlasma" -O0 -g3 -Wall -c -fmessage-length=0 -fopenmp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


