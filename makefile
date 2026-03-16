firmware.elf : startup.o main.o isr.o helper.o
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -g -O0   startup.o main.o helper.o isr.o  -T stm32f446xx_linker.ld   -nostartfiles -Wl,-Map=output.map   -o firmware.elf
helper.o : stm32f446xx_helper.c
	arm-none-eabi-gcc -g -mcpu=cortex-m4 -mthumb -c stm32f446xx_helper.c -o helper.o
isr.o : stm32f446xx_isr.c
	arm-none-eabi-gcc -g -mcpu=cortex-m4 -mthumb -c stm32f446xx_isr.c -o isr.o
startup.o : stm32f446xx_startup.c stm32f446xx_isr.c stm32f446xx_helper.c
	arm-none-eabi-gcc -g -mcpu=cortex-m4 -mthumb -c stm32f446xx_startup.c -o startup.o
main.o : dummy.c stm32f446xx_isr.c stm32f446xx_helper.c
	arm-none-eabi-gcc -g -mcpu=cortex-m4 -mthumb -c dummy.c -o main.o
clean:
	rm -f *.o firmware.elf output.map