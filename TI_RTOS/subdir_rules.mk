################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
CThread.obj: ../CThread.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=fpalib -me --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/include/" --include_path="C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/mqtt_client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/inc" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/driverlib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/oslib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/portable/CCS/ARM_CM3" -g --gcc --define=ccs --define=USE_TIRTOS --define=SL_PLATFORM_MULTI_THREADED --define=cc3200 --diag_wrap=off --diag_warning=225 --display_error_number --gen_func_subsections=off --abi=eabi --preproc_with_compile --preproc_dependency="CThread.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

CThreadDefinitions.obj: ../CThreadDefinitions.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=fpalib -me --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/include/" --include_path="C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/mqtt_client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/inc" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/driverlib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/oslib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/portable/CCS/ARM_CM3" -g --gcc --define=ccs --define=USE_TIRTOS --define=SL_PLATFORM_MULTI_THREADED --define=cc3200 --diag_wrap=off --diag_warning=225 --display_error_number --gen_func_subsections=off --abi=eabi --preproc_with_compile --preproc_dependency="CThreadDefinitions.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

CThreadIO.obj: ../CThreadIO.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=fpalib -me --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/include/" --include_path="C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/mqtt_client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/inc" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/driverlib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/oslib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/portable/CCS/ARM_CM3" -g --gcc --define=ccs --define=USE_TIRTOS --define=SL_PLATFORM_MULTI_THREADED --define=cc3200 --diag_wrap=off --diag_warning=225 --display_error_number --gen_func_subsections=off --abi=eabi --preproc_with_compile --preproc_dependency="CThreadIO.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

CThreadMqttClient.obj: ../CThreadMqttClient.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=fpalib -me --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/include/" --include_path="C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/mqtt_client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/inc" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/driverlib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/oslib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/portable/CCS/ARM_CM3" -g --gcc --define=ccs --define=USE_TIRTOS --define=SL_PLATFORM_MULTI_THREADED --define=cc3200 --diag_wrap=off --diag_warning=225 --display_error_number --gen_func_subsections=off --abi=eabi --preproc_with_compile --preproc_dependency="CThreadMqttClient.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

CThreadTCPClient.obj: ../CThreadTCPClient.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=fpalib -me --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/include/" --include_path="C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/mqtt_client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/inc" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/driverlib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/oslib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/portable/CCS/ARM_CM3" -g --gcc --define=ccs --define=USE_TIRTOS --define=SL_PLATFORM_MULTI_THREADED --define=cc3200 --diag_wrap=off --diag_warning=225 --display_error_number --gen_func_subsections=off --abi=eabi --preproc_with_compile --preproc_dependency="CThreadTCPClient.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

CThreadTCPServer.obj: ../CThreadTCPServer.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=fpalib -me --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/include/" --include_path="C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/mqtt_client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/inc" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/driverlib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/oslib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/portable/CCS/ARM_CM3" -g --gcc --define=ccs --define=USE_TIRTOS --define=SL_PLATFORM_MULTI_THREADED --define=cc3200 --diag_wrap=off --diag_warning=225 --display_error_number --gen_func_subsections=off --abi=eabi --preproc_with_compile --preproc_dependency="CThreadTCPServer.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

CThreadUDP.obj: ../CThreadUDP.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=fpalib -me --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/include/" --include_path="C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/mqtt_client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/inc" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/driverlib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/oslib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/portable/CCS/ARM_CM3" -g --gcc --define=ccs --define=USE_TIRTOS --define=SL_PLATFORM_MULTI_THREADED --define=cc3200 --diag_wrap=off --diag_warning=225 --display_error_number --gen_func_subsections=off --abi=eabi --preproc_with_compile --preproc_dependency="CThreadUDP.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

button_if.obj: C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/common/button_if.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=fpalib -me --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/include/" --include_path="C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/mqtt_client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/inc" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/driverlib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/oslib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/portable/CCS/ARM_CM3" -g --gcc --define=ccs --define=USE_TIRTOS --define=SL_PLATFORM_MULTI_THREADED --define=cc3200 --diag_wrap=off --diag_warning=225 --display_error_number --gen_func_subsections=off --abi=eabi --preproc_with_compile --preproc_dependency="button_if.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

gpio_if.obj: C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/common/gpio_if.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=fpalib -me --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/include/" --include_path="C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/mqtt_client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/inc" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/driverlib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/oslib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/portable/CCS/ARM_CM3" -g --gcc --define=ccs --define=USE_TIRTOS --define=SL_PLATFORM_MULTI_THREADED --define=cc3200 --diag_wrap=off --diag_warning=225 --display_error_number --gen_func_subsections=off --abi=eabi --preproc_with_compile --preproc_dependency="gpio_if.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=fpalib -me --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/include/" --include_path="C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/mqtt_client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/inc" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/driverlib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/oslib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/portable/CCS/ARM_CM3" -g --gcc --define=ccs --define=USE_TIRTOS --define=SL_PLATFORM_MULTI_THREADED --define=cc3200 --diag_wrap=off --diag_warning=225 --display_error_number --gen_func_subsections=off --abi=eabi --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

network_if.obj: C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/common/network_if.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=fpalib -me --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/include/" --include_path="C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/mqtt_client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/inc" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/driverlib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/oslib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/portable/CCS/ARM_CM3" -g --gcc --define=ccs --define=USE_TIRTOS --define=SL_PLATFORM_MULTI_THREADED --define=cc3200 --diag_wrap=off --diag_warning=225 --display_error_number --gen_func_subsections=off --abi=eabi --preproc_with_compile --preproc_dependency="network_if.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

pinmux.obj: ../pinmux.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=fpalib -me --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/include/" --include_path="C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/mqtt_client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/inc" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/driverlib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/oslib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/portable/CCS/ARM_CM3" -g --gcc --define=ccs --define=USE_TIRTOS --define=SL_PLATFORM_MULTI_THREADED --define=cc3200 --diag_wrap=off --diag_warning=225 --display_error_number --gen_func_subsections=off --abi=eabi --preproc_with_compile --preproc_dependency="pinmux.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

spawner.obj: ../spawner.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=fpalib -me --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/include/" --include_path="C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/mqtt_client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/inc" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/driverlib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/oslib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/portable/CCS/ARM_CM3" -g --gcc --define=ccs --define=USE_TIRTOS --define=SL_PLATFORM_MULTI_THREADED --define=cc3200 --diag_wrap=off --diag_warning=225 --display_error_number --gen_func_subsections=off --abi=eabi --preproc_with_compile --preproc_dependency="spawner.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

timer_if.obj: C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/common/timer_if.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=fpalib -me --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/include/" --include_path="C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/mqtt_client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/inc" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/driverlib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/oslib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/portable/CCS/ARM_CM3" -g --gcc --define=ccs --define=USE_TIRTOS --define=SL_PLATFORM_MULTI_THREADED --define=cc3200 --diag_wrap=off --diag_warning=225 --display_error_number --gen_func_subsections=off --abi=eabi --preproc_with_compile --preproc_dependency="timer_if.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

uart_if.obj: C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/common/uart_if.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=fpalib -me --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/netapps/mqtt/include/" --include_path="C:/TI/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/mqtt_client/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/example/common/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/inc" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/simplelink/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/driverlib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/oslib/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/include/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/" --include_path="C:/TI/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/portable/CCS/ARM_CM3" -g --gcc --define=ccs --define=USE_TIRTOS --define=SL_PLATFORM_MULTI_THREADED --define=cc3200 --diag_wrap=off --diag_warning=225 --display_error_number --gen_func_subsections=off --abi=eabi --preproc_with_compile --preproc_dependency="uart_if.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

