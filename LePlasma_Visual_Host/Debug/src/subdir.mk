################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Figure.cpp \
../src/GridViewer.cpp \
../src/Mathx.cpp \
../src/Plot.cpp \
../src/Visualize.cpp \
../src/XYZIndicator.cpp 

OBJS += \
./src/Figure.o \
./src/GridViewer.o \
./src/Mathx.o \
./src/Plot.o \
./src/Visualize.o \
./src/XYZIndicator.o 

CPP_DEPS += \
./src/Figure.d \
./src/GridViewer.d \
./src/Mathx.d \
./src/Plot.d \
./src/Visualize.d \
./src/XYZIndicator.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	mpic++ -I"/home/zlstudio/workspace/LePlasma_Visual_Host/include" -I"/home/zlstudio/workspace/LePlasma_Visual_Host/include_cal" -I"/home/zlstudio/workspace/LePlasma_Visual_Host/LeFrame/include" -I"/home/zlstudio/workspace/LePlasma_Visual_Host/Socket" -I"/home/zlstudio/workspace/LePlasma_Visual_Host" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


