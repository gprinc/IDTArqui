GLOBAL printf

section .text
printf:
	mov rax, rdi
	mov rdi, 0x2
	mov rsi, rax
	int 80h
	ret