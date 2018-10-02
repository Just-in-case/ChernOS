[org 0x7c00]

mov si, STR_LOADED
call print_string

mov al, 1
mov cl, 2
call read_disk

jmp second_sector 

%include "src/printing.asm"
%include "src/read_disk.asm"

STR_LOADED: db "Loaded in 16-bit Real Mode to memory location 0x7c00.", 0x0a, 0x0d, 0 ; -> "str\n\r\0"
TEST_STR: db "msg from second sector", 0x0a, 0x0d, 0

times 510-($-$$) db 0 ; fill boot sector with 0's
dw 0xaa55; magic number to identevy boot sector

second_sector:
    mov si, TEST_STR 
    call print_string

times 512 db 0
