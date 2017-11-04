GLOBAL write_a

section .text
write_a:
	mov rdi, 0x2
	mov rsi, a
	int 80h
	ret

section .data
a db "a a", 0