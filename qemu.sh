if grep -qE "(Microsoft|WSL)" /proc/version &> /dev/null ; then
    echo "Running under Windows 10 Bash"
    echo "export DISPLAY=0:0"
    export DISPLAY=0:0
else
    if grep -qE "MINGW" /proc/version &> /dev/null; then
        echo "Could not start under Git Bash"
    else
        echo "Running under Linux"
    fi
fi

if hash qemu-system-i386 2>/dev/null; then
    echo "Found qemu-system-i386, using it"
    qemu-system-i386 -kernel chernos.elf
else
    echo "qemu-system-i386 not found"
    if hash qemu-system-x86_64 2>/dev/null; then
        echo "Found qemu-system-x86_64, using it"
        qemu-system-x86_64 -kernel chernos.elf
    else
        echo "Could not find a compatible qemu system (options: i386, x86_64)"
    fi
fi