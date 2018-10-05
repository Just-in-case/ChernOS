# ChernOS

## From VSCode
### Building
If you run the `Debug` or `Run` tasks they will automatically run the `Build` task.

If you wish to run the `Build` task without running you can do it quickly using `CTRL` + `SHIFT` + `B`

### Running
To run it in qemu simply run the `Run` task. It will automatically build and set `DISPLAY=0:0` if you are using WSL.
Also it will use i386 qemu by default but can fall back to x86_64.

### Debugging
To debug from VSCode you can simply run the `Debug` task. It will automatically build and set `DISPLAY=0:0` if you are using WSL.
Note that you can not debug if you are using x86_64 QEMU.

It will also make sure to launch the VSCode debugger and connect to the GDB server opened by QEMU.

## From Console
### Building
To build run the `build.sh` file.

### Running
To run run the `qemu.sh` file. It will automatically set `DISPLAY=0:0` if you are using WSL.
Also it will use i386 qemu by default but can fall back to x86_64.

### Debugging
To debug run the `qemu.gdb.sh` file. It will automatically set `DISPLAY=0:0` if you are using WSL.
Note that you can not debug if you are using x86_64 QEMU.

Then you will need to connect to the GDB server opened by QEMU using a GDB client.

## Installs
+ gcc -> C
+ nasm -> intel assembly
+ qemu -> lauching the os on your os
+ gdb -> debugging
+ vs-code -> IDE
    * [Native Debug extionson for VSCode](https://marketplace.visualstudio.com/items?itemName=webfreak.debug) -> proper gdb integraton

## Troubleshooting
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
