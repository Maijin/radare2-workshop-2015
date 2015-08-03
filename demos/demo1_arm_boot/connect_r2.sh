#!/bin/sh
r2 -a arm.gnu -b 32 -d -D gdb -e io.va=true gdb://127.0.0.1:1234
