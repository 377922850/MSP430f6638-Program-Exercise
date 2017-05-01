################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
l6.obj: ../l6.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/CCS/ccsv5/tools/compiler/msp430_4.2.1/bin/cl430" -vmspx --abi=eabi --include_path="D:/CCS/ccsv5/ccs_base/msp430/include" --include_path="D:/CCS/ccsv5/tools/compiler/msp430_4.2.1/include" --advice:power=all -g --define=__MSP430F6638__ --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="l6.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


