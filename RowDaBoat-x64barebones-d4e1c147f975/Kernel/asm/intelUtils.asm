GLOBAL get_register_eax
GLOBAL get_register_ebx
GLOBAL get_register_ecx

section .text
get_register_eax:
	ret

get_register_ebx:
	mov eax, ebx
	ret

get_register_ecx:
	mov eax, ecx
	ret