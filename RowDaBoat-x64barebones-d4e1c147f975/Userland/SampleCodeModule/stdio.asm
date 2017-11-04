GLOBAL print

section .text
print:
	mov rax, rdi
	mov rdi, 0x2
	mov rsi, rax
	int 80h
	ret