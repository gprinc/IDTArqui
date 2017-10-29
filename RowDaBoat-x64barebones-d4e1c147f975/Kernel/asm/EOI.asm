EXTERN handle_syscall

section .text

int_syscall:
	pushState

	call handle_syscall

	mov al, 20h
	out 20h, al

	popState
	iretq