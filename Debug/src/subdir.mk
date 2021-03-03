################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Board.cpp \
../src/Case.cpp \
../src/Players.cpp \
../src/backgammonGame.cpp 

OBJS += \
./src/Board.o \
./src/Case.o \
./src/Players.o \
./src/backgammonGame.o 

CPP_DEPS += \
./src/Board.d \
./src/Case.d \
./src/Players.d \
./src/backgammonGame.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


