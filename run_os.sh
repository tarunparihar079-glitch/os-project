#!/bin/bash

make clean

make

if [ -f FirstOS.bin ]; then
    echo "OS build successful! Starting QEMU..."
    qemu-system-i386 -kernel FirstOS.bin
else
    echo "Build failed. Check errors."
fi
