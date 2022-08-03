################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Toglling_Led_STM32F103C6.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Toglling_Led_STM32F103C6.list \

OBJCOPY_HEX += \
Toglling_Led_STM32F103C6.hex \

OBJCOPY_BIN += \
Toglling_Led_STM32F103C6.bin \


# All Target
all: Toglling_Led_STM32F103C6.elf secondary-outputs

# Tool invocations
Toglling_Led_STM32F103C6.elf: $(OBJS) $(USER_OBJS) F:\Kyrillos\ Shenouda\ EMbedded\Unit\ 3\ -\ Embedded\ C\Lession\ 1\project\Toglling_Led_STM32F103C6\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "Toglling_Led_STM32F103C6.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"F:\Kyrillos Shenouda EMbedded\Unit 3 - Embedded C\Lession 1\project\Toglling_Led_STM32F103C6\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Toglling_Led_STM32F103C6.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Toglling_Led_STM32F103C6.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Toglling_Led_STM32F103C6.list"
	@echo 'Finished building: $@'
	@echo ' '

Toglling_Led_STM32F103C6.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "Toglling_Led_STM32F103C6.hex"
	@echo 'Finished building: $@'
	@echo ' '

Toglling_Led_STM32F103C6.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Toglling_Led_STM32F103C6.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
