################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/laschweinski/git/cocos2d-x/tests/tests/ClickAndMoveTest/ClickAndMoveTest.cpp 

OBJS += \
./tests/ClickAndMoveTest/ClickAndMoveTest.o 

CPP_DEPS += \
./tests/ClickAndMoveTest/ClickAndMoveTest.d 


# Each subdirectory must supply rules for building sources it contributes
tests/ClickAndMoveTest/ClickAndMoveTest.o: /home/laschweinski/git/cocos2d-x/tests/tests/ClickAndMoveTest/ClickAndMoveTest.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DLINUX -I../../ -I../../../cocos2dx/platform/third_party/linux -I../../../cocos2dx/include -I../../../cocos2dx -I../../../cocos2dx/platform -I../../../CocosDenshion/include -I../../..//chipmunk/include/chipmunk -I../../../Box2D -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

