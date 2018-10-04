#/bin/bash

# Create build directory
mkdir build 2> /dev/null

CCFLAGS="-g -Wall -Wextra -nostdinc -fno-builtin -fno-stack-protector -march=i386 -m32"

nasm src/bootstrap.asm -g -f elf -o build/bootstrap.o
gcc $CCFLAGS -c src/kernel.c -o build/kernel.o

ld -melf_i386 -T src/linker.ld -o chernos.elf build/bootstrap.o build/kernel.o