################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
User/main.obj: ../User/main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" --include_path="D:/Code/DSP28335/example/DSP8233x_Example/example06_motor/HardWare/dc_motor" --include_path="D:/Code/DSP28335/example/DSP8233x_Example/example06_motor/HardWare/key" --include_path="D:/Code/DSP28335/example/DSP8233x_Example/example06_motor/HardWare/leds" --include_path="D:/Code/DSP28335/example/DSP2833x_Libraries/DSP2833x_common/include" --include_path="D:/Code/DSP28335/example/DSP2833x_Libraries/DSP2833x_headers/include" -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="User/main.d" --obj_directory="User" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


