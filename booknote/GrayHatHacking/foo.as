section .data	;section
	msg db "Hello, GNU Assembler!", 0xa	;string and \n
	len equ $ - msg	;length of string

section .text
global _start;
_start:
	mov edx, len	;arg3, len of string
	mov ecx, msg	;arg2, pointer to string
	mov ebx, 1	;arg1, handle stdout
	mov eax, 4	;syscall number, 4 == sys_write
	int 0x80	;trigger syscall interrupt, and return
	mov ebx, 0	;load syscall arg 0(exit code)
	mov eax, 1	;load syscall number, 1 == sys_exit
	int 0x80	;trigger interrupt and return

;nasm -f elt hello.asm
;ld -s -o hello hello.o

