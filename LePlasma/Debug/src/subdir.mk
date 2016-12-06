################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CSPIC.cpp \
../src/Case.cpp \
../src/CaseLauncher.cpp \
../src/Cell.cpp \
../src/DispersionRelation.cpp \
../src/Distributer.cpp \
../src/Electron.cpp \
../src/Engine.cpp \
../src/Eular.cpp \
../src/ExternalField.cpp \
../src/Grid.cpp \
../src/HostGrid.cpp \
../src/MPIGrid.cpp \
../src/Particle.cpp \
../src/ParticleDistributer.cpp \
../src/PlateWave.cpp \
../src/Range.cpp \
../src/RunManager.cpp \
../src/Tensor3D.cpp \
../src/TestFor.cpp \
../src/UniformB.cpp \
../src/UniformBFalse.cpp \
../src/UniformE.cpp \
../src/Vector3D.cpp \
../src/Vertex.cpp 

OBJS += \
./src/CSPIC.o \
./src/Case.o \
./src/CaseLauncher.o \
./src/Cell.o \
./src/DispersionRelation.o \
./src/Distributer.o \
./src/Electron.o \
./src/Engine.o \
./src/Eular.o \
./src/ExternalField.o \
./src/Grid.o \
./src/HostGrid.o \
./src/MPIGrid.o \
./src/Particle.o \
./src/ParticleDistributer.o \
./src/PlateWave.o \
./src/Range.o \
./src/RunManager.o \
./src/Tensor3D.o \
./src/TestFor.o \
./src/UniformB.o \
./src/UniformBFalse.o \
./src/UniformE.o \
./src/Vector3D.o \
./src/Vertex.o 

CPP_DEPS += \
./src/CSPIC.d \
./src/Case.d \
./src/CaseLauncher.d \
./src/Cell.d \
./src/DispersionRelation.d \
./src/Distributer.d \
./src/Electron.d \
./src/Engine.d \
./src/Eular.d \
./src/ExternalField.d \
./src/Grid.d \
./src/HostGrid.d \
./src/MPIGrid.d \
./src/Particle.d \
./src/ParticleDistributer.d \
./src/PlateWave.d \
./src/Range.d \
./src/RunManager.d \
./src/Tensor3D.d \
./src/TestFor.d \
./src/UniformB.d \
./src/UniformBFalse.d \
./src/UniformE.d \
./src/Vector3D.d \
./src/Vertex.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	mpic++ -I"/home/ylang/workspace/LePlasma/include" -I"/home/ylang/workspace/LePlasma/Socket" -I"/home/ylang/workspace/LePlasma" -O0 -g3 -Wall -c -fmessage-length=0 -fopenmp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


