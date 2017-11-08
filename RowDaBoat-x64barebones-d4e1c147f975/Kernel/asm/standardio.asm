GLOBAL printf
GLOBAL scanf
GLOBAL clearScreen

section .text
printf:
	mov rax, rdi
	mov rdi, 0x2
	mov rsi, rax
	int 80h
	ret

scanf:
	mov rdi, 0x1
	int 80h
	ret

clearScreen:
	mov rdi, 0x3
	int 80h
	ret