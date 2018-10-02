read_disk:
    pusha
    mov ah, 0x02 ; read sector from drive
    mov dl, 0x80 ; drive: 0x80 harddisk ; 0x00 floppy/flash
    mov ch, 0 ; starting cylinder
    mov dh, 0 ; first head
    ;mov al, 1 ; num sectors
    ;mov cl, 2 ; sector to start reading first one is boot loader
    
    push bx
    mov bx, 0
    mov es, bx
    pop bx
    mov bx, 0x7c00 + 512

    int 0x13

    jc disk_err
    popa
    ret

disk_err:
    mov si, DISK_ERR_MSG
    call print_string    
    jmp $ 


DISK_ERR_MSG: db "Error Loading Disk.", 0x0a, 0x0d, 0