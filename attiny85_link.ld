MEMORY
{
  FLASH (rx)      : ORIGIN = 0x00000000, LENGTH = 8K
  SRAM (xrw)      : ORIGIN = 0x00800060, LENGTH = 512
}

SECTIONS
{
    .data : 
    {
        __data_start = .;
        *(.data)
        *(.data*)
        __data_end = .;
    } > FLASH
    __data_load_start = LOADADDR(.data);

    .text :
    {
        *(.text)
        *(.text*)
    } > FLASH

    .bss :
    {
        __bss_start = .;
        *(.bss)
        *(.bss*)
        __bss_end = .;
    } > FLASH
}