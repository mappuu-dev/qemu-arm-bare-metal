ENTRY(_start)

MEMORY
{
    RAM  : ORIGIN = 0x60010000, LENGTH = 32M
}

SECTIONS
{
    .text : {
        PROVIDE(_text_start = .);
        *(.text .text.*)
        PROVIDE(_text_end = .);
    } > RAM
    
    .rodata : {
        PROVIDE(_rodata_start = .);
        *(.rodata .rodata.*)
        PROVIDE(_rodata_end = .);
    } > RAM
    
    .data : {
        PROVIDE(_data_start = .);
        *(.data .data.*)
        PROVIDE(_data_end = .);
    } > RAM
    
    .bss : {
        PROVIDE(_bss_start = .);
        *(.bss .bss.*)
        PROVIDE(_bss_end = .);
    } > RAM

    PROVIDE(_end = _bss_end);
    
    .stack : {
        . = ALIGN(16);
        PROVIDE(_stack_start = .);
        . += 4096;
        PROVIDE(_stack_end = .);
    } > RAM
}

