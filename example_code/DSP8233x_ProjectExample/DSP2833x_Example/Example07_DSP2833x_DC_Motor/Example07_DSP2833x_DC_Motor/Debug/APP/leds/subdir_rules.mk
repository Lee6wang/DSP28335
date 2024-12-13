################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
APP/leds/leds.obj: ../APP/leds/leds.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="E:/DSP8233x_ProjectExample/DSP2833x_Example/Example07_DSP2833x_DC_Motor/APP/dc_motor" --include_path="E:/DSP8233x_ProjectExample/DSP2833x_Example/Example07_DSP2833x_DC_Motor/APP/key" --include_path="E:/DSP8233x_ProjectExample/DSP2833x_Libraries/DSP2833x_common/include" --include_path="E:/DSP8233x_ProjectExample/DSP2833x_Example/Example07_DSP2833x_DC_Motor/APP/leds" --include_path="E:/DSP8233x_ProjectExample/DSP2833x_Libraries/DSP2833x_headers/include" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="APP/leds/leds.d" --obj_directory="APP/leds" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


