# ChernOS

## Building
For now there is some basic `build.sh` file just to get it working.

Just click on the Debug configuration and it will compile and start Qemu. 

**Note:** If you are using WSL, also make sure you have Xlaunch/Xming running otherwise Qemu will fail to start. It will automatically make sure to set `DISPLAY` to `0:0`

## Project setup
This repo includes a Visual Studio Code project configuration for building and debugging the OS.

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