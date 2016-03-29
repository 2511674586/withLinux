UEFI: Principles and Programming
---
> 戴正华, UEFI原理与编程
> China machine press

## 1. Introduction

BIOS: basic input output system  

1. self-check program runs on powerup  
1. system initialization code, incl. BIOS interrupt vector  
1. external I/O manipulation code  
1. CMOS configuration program  

CPU jumps to `0x0FFFF0` on powerup.

BIOS disadvantage:

1. low development efficiency  
1. low performance  
1. low extensibility, slow upgrade  
1. security  
1. no support for booting from disk address that `>= 2TB`

UEFI: unified extensible firmware interface

1. platform initialization  
1. firmware-operating system interface  

#### UEFI boot procedure  

* SEC (security verification)  
* PEI (EFI pre-initialization)  
* DXE (driver execution environment)  
* BDS (boot up device selection)  
* TSL (Transient System Load)  
* RT (runtime)  
* AL (dizaster recovering)  

UEFI provides BS (boot services) and RT services for the OS.


#### x
+placeholder, 29 Mar. 2016
