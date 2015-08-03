# Workshop2015

TOC

Part 0. Intro to the radare world (45 min + 15 min practice)
=================================

0.0   - Generality on radare2 framework
1.1   - Utility toolsuit
2.1   - Radare2 - Generalities
2.2   - Radare2 - Printing
2.3   - Radare2 - Info Commands
2.4   - Radare2 - Search
2.5   - Analysis
2.6   - Visual Mode(s)
2.7   - Student Practices - IOLI Set - Questions/Answers

Part I. Static analysis (1 hour 30 minutes)
=======================

Chapter 1. Malware (45 minutes)
------------------
1.1 Windows malware example
1.2 Linux malware example

Chapter 2. Firmware (45 minutes)
-------------------
2.1. General MIPS router firmware unpacking (15 minutes)
Showing low-hanging vulnerabilities in a classic SOHO router.

2.2 General ARM firmware analysis - bootloaders and android
executables (15 minutes)
  - Texas Instruments bootrom analysis
  - Qualcomm TrustZone analysis
  - One of Android executables

2.3 HDD firmware analysis (15 minutes)
  - Seagate firmware unpacking and disassembling

Chapter 3. Practice (30 minutes)
-------------------

Part II Debugging - (40 minutes)
=================

Chapter 1. General techniques (30 minutes)
-----------------------------
1.1 gdb (10 minutes)
Since the current native debugger is not perfect (it will be the focus
for the next release),
Radare2 can use gdb as a backend to debug processes.

1.2 native (10 minutes)
We'll show basic on-host debugging case, when you are brave enough
to debug executable (or even malware) directly on your machine.
Also:
  - rarun2 - setup execution environment for a program (chroot,
parameters, env, etc.)
  - remote r2 debugging r2 -c=h && r2 -C http://.../cmd/

1.3 WinDbg and PDB (10 minutes)
Essential part for the windows debuggind is loading PDB files,
especially for Windows drivers.

Chapter 2. Firmware (10 minutes)
-------------------
2.1 qemu (10 minutes)
Using embedded gdbserver to debug x86 bootloader/bios/uefi,
and arm bootloader (see Part II, 2.2 section)

Part III Scripting (1 hour)
==================

Chapter 1. Radare2 script (15 minutes)
-------------------------
Basic scripting, pipelining radare2 commands, without any external plugins.
Using python plugins, high-level analysis using python bindings

Chapter 2. Scripting with r2pipe (30 minutes)
--------------------------------
Using r2pipe for scripting with python, javascript.

Chapter 3. Python bindings (15 minutes)
--------------------------
Using 'classic' and 'ctypes' python bindings for the radare2 library

Part IV ESIL (1 hour)
============

ESIL is an Evaluateable String Intermediate Language

Chapter 1. Small ESIL introduction
----------------------------------
ESIL syntax, opcodes, sources of the ESIL analysis

Chapter 2. ESIL emulation
-------------------------
Using ESIL for the emulation, without qemu/bochs/vbox needed

Chapter 3. ESIL to REIL conversion
----------------------------------
To be able to use already existing tools based on REIL

THE END
