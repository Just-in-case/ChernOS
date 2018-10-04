[BITS 32]

MAGIC equ 0x1badb002
FLAGS equ (1 << 0 | 1 << 1)
CHECKSUM equ -(MAGIC + FLAGS)

[section .multiboot]
    dd MAGIC
    dd FLAGS
    dd CHECKSUM

[section .text]

    [global chernos_start]
    [extern kmain]
    chernos_start:
        mov esp, chernos_stack
        mov ebp, chernos_stack
        call kmain

    chernos_exit:
        hlt
        jmp chernos_exit
        

[section .bss]
    resb 1024 * 1024 * 2
    chernos_stack:
