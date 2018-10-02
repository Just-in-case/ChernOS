# ChernOS

## Building
Run
"`build.sh`" or press inside of vs-code ctr+b.

## Execution
Run
"`qemu.x86_64.sh`"
or
"`qemu.x86_64_wsl.sh`" for wsl.

## Debugging
Run
`qemu.gdb.x86_64.sh`
or
`qemu.gdb.x86_64_wsl.sh`" for wsl.\
Than lauche the vs-code debugger.

## Installs
+ gcc -> C
+ nasm -> intel assembly
+ qemu -> lauching the os on your os
+ gdb -> debugging
+ vs-code -> ide
+ vs-code Native Debug extionson -> proper gdb integraton

## Setup
If you can't run the shell scripts make shure they have execution right:
"`chmod 777 file.sh`"

If you have problems with the InteliSense you might need to change your compiler location in the `c_cpp_properties.json` file:
```json
{
    "configurations": [
        {
            ...
            "compilerPath": "<path to gcc>\\gcc.exe -fdiagnostics-color=always -Wall -Wextra -std=gnu99 -nostdinc -fno-builtin -fno-stack-protector -march=i386 -m32",
            ...
        }
    ],
}
```
*Note: This configuration is only needed for InteliSense to work, everything else is going to be handled by make or whatever we end up using*