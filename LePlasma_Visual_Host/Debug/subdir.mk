################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../LePlasma_Visualizer.cpp 

OBJS += \
./LePlasma_Visualizer.o 

CPP_DEPS += \
./LePlasma_Visualizer.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	mpic++ -I"/home/zlstudio/workspace/LePlasma_Visual_Host/include" -I"/home/zlstudio/workspace/LePlasma_Visual_Host/include_cal" -I"/home/zlstudio/workspace/LePlasma_Visual_Host/LeFrame/include" -I"/home/zlstudio/workspace/LePlasma_Visual_Host/Socket" -I"/home/zlstudio/workspace/LePlasma_Visual_Host" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


