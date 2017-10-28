GLOBAL get_register_eax
GLOBAL get_register_ebx
GLOBAL get_register_ecx

section .text
get_register_eax:
	ret

get_register_ebx:
	mov ebx, eax
	ret

get_register_ecx:
	mov ebx, ecx
	ret