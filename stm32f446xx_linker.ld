MEMORY
{
    RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 112K
    CCRAM (rwx) : ORIGIN = 0x2001C000, LENGTH = 16K
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 512K
}

_eram = ORIGIN(RAM) + LENGTH(RAM);
_stack = _eram;

SECTIONS
{
    .text : ALIGN(4) 
    {
        KEEP(*(.isr_vector))
        *(.text*)
        *(.rodata*)
        . = ALIGN(4);
        _etext = .;
    } > FLASH

    .data : ALIGN(4)
    {
        _sdata = .;
        *(.data*)
        . = ALIGN(4);
        _edata = .;
    } > RAM AT > FLASH

    _sidata = LOADADDR(.data);

    .bss : ALIGN(4)
    {
        _sbss = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
    } > RAM
}