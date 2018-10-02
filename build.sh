#/bin/bash

# Create build directory
mkdir build 2> /dev/null

nasm src/main.asm -g -f bin -o build/main.bin
