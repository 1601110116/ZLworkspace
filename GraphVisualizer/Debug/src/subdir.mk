################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GraphReader.cpp \
../src/Mathx.cpp \
../src/Plot.cpp 

OBJS += \
./src/GraphReader.o \
./src/Mathx.o \
./src/Plot.o 

CPP_DEPS += \
./src/GraphReader.d \
./src/Mathx.d \
./src/Plot.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/zlstudio/workspace/GraphVisualizer/LeFrame/include" -I"/home/zlstudio/workspace/GraphVisualizer/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


