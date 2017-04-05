################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.4.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./CThread.obj" \
"./CThreadDefinitions.obj" \
"./CThreadHTTPServer.obj" \
"./CThreadI2C.obj" \
"./CThreadIO.obj" \
"./CThreadMain.obj" \
"./CThreadMqttClient.obj" \
"./CThreadTCPClient.obj" \
"./CThreadTCPServer.obj" \
"./CThreadUDP.obj" \
"./bma222drv.obj" \
"./button_if.obj" \
"./gpio_if.obj" \
"./i2c_if.obj" \
"./ini.obj" \
"./main.obj" \
"./network_common.obj" \
"./network_if.obj" \
"./pinmux.obj" \
"./spawner.obj" \
"./startup_ccs.obj" \
"./timer_if.obj" \
"./tmp006drv.obj" \
"./uart_if.obj" \
"../cc3200v1p32.cmd" \
$(GEN_CMDS__FLAG) \
-l"libc.a" \
-l"C:/ti/CC3200SDK_1.2.0/cc3200-sdk/example/mqtt_client/ccs/../../../oslib/ccs/free_rtos/free_rtos.a" \
-l"C:/ti/CC3200SDK_1.2.0/cc3200-sdk/example/mqtt_client/ccs/../../../simplelink/ccs/OS_debug/simplelink.a" \
-l"C:/ti/CC3200SDK_1.2.0/cc3200-sdk/example/mqtt_client/ccs/../../../netapps/mqtt/ccs/client/mqtt.a" \
-l"C:/ti/CC3200SDK_1.2.0/cc3200-sdk/example/mqtt_client/ccs/../../../driverlib/ccs/Release/driverlib.a" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
DomoticaMqtt.out \

EXE_OUTPUTS__QUOTED += \
"DomoticaMqtt.out" \

BIN_OUTPUTS += \
DomoticaMqtt.bin \

BIN_OUTPUTS__QUOTED += \
"DomoticaMqtt.bin" \


# All Target
all: DomoticaMqtt.out

# Tool invocations
DomoticaMqtt.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Linker'
	"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me -g --gcc --define=ccs --define=USE_FREERTOS --define=SL_PLATFORM_MULTI_THREADED --define=cc3200 --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi -z -m"DomoticaMqtt.map" --stack_size=0x5000 --heap_size=0x8000 -i"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.4.LTS/lib" -i"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.4.LTS/include" --reread_libs --warn_sections --diag_wrap=off --display_error_number --xml_link_info="DomoticaMqtt_linkInfo.xml" --rom_model -o "DomoticaMqtt.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

DomoticaMqtt.bin: $(EXE_OUTPUTS)
	@echo 'Invoking: ARM Hex Utility'
	"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.4.LTS/bin/armhex"  -o "DomoticaMqtt.bin" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "CThread.pp" "CThreadDefinitions.pp" "CThreadHTTPServer.pp" "CThreadI2C.pp" "CThreadIO.pp" "CThreadMain.pp" "CThreadMqttClient.pp" "CThreadTCPClient.pp" "CThreadTCPServer.pp" "CThreadUDP.pp" "spawner.pp" 
	-$(RM) "bma222drv.pp" "button_if.pp" "gpio_if.pp" "i2c_if.pp" "ini.pp" "main.pp" "network_common.pp" "network_if.pp" "pinmux.pp" "startup_ccs.pp" "timer_if.pp" "tmp006drv.pp" "uart_if.pp" 
	-$(RM) "CThread.obj" "CThreadDefinitions.obj" "CThreadHTTPServer.obj" "CThreadI2C.obj" "CThreadIO.obj" "CThreadMain.obj" "CThreadMqttClient.obj" "CThreadTCPClient.obj" "CThreadTCPServer.obj" "CThreadUDP.obj" "bma222drv.obj" "button_if.obj" "gpio_if.obj" "i2c_if.obj" "ini.obj" "main.obj" "network_common.obj" "network_if.obj" "pinmux.obj" "spawner.obj" "startup_ccs.obj" "timer_if.obj" "tmp006drv.obj" "uart_if.obj" 
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-"C:/TI/ccsv6/utils/tiobj2bin/tiobj2bin" "DomoticaMqtt.out" "DomoticaMqtt.bin" "C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.4.LTS/bin/armofd" "C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.4.LTS/bin/armhex" "C:/TI/ccsv6/utils/tiobj2bin/mkhex4bin"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets

