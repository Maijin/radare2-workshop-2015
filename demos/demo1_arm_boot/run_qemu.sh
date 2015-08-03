#!/bin/sh
qemu-system-arm -s -S -M milestone -m 256 -L . -bios omap_3430.bin -mtdblock mbmloader-1.raw -d in_asm,cpu,exec -nographic
