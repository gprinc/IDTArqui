GLOBAL write_a

section .text
write_a:
	mov eax, 0x2
	mov ebx, 97
	int 0h
	ret
