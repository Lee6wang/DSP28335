################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
DSP2833x_Libraries/DSP2833x_headers/source/DSP2833x_GlobalVariableDefs.obj: ../DSP2833x_Libraries/DSP2833x_headers/source/DSP2833x_GlobalVariableDefs.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" --include_path="D:/Code/DSP28335/example_demo/DSP2833x_Libraries/DSP2833x_common/include" --include_path="D:/Code/DSP28335/example_demo/DSP2833x_Libraries/DSP2833x_headers/include" -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="DSP2833x_Libraries/DSP2833x_headers/source/DSP2833x_GlobalVariableDefs.d" --obj_directory="DSP2833x_Libraries/DSP2833x_headers/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


