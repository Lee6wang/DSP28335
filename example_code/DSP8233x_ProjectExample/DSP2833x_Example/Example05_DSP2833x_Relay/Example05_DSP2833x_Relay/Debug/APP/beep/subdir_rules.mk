################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
APP/beep/beep.obj: ../APP/beep/beep.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="E:/DSP8233x_ProjectExample/DSP2833x_Example/Example05_DSP2833x_Relay/APP/relay" --include_path="E:/DSP8233x_ProjectExample/DSP2833x_Libraries/DSP2833x_common/include" --include_path="E:/DSP8233x_ProjectExample/DSP2833x_Example/Example04_DSP2833x_BEEP/APP/beep" --include_path="E:/DSP8233x_ProjectExample/DSP2833x_Example/Example02_DSP2833x_LED/APP/leds" --include_path="E:/DSP8233x_ProjectExample/DSP2833x_Libraries/DSP2833x_headers/include" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="APP/beep/beep.d" --obj_directory="APP/beep" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


