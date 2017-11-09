GLOBAL triggerDivideByZero
GLOBAL triggerOverflow
GLOBAL triggerInvalidOpcode

section .text
triggerDivideByZero:
	mov r14, 28
	mov r8, 47
	mov r12, 13
	mov rax, 42
	mov rcx, 69
	mov rdx, 0
	mov ebx, 0
	div ebx
	ret

triggerOverflow:
	mov rax, 99999999999h
	mov rdx, 99999999999h
	mov ebx, 5
	div ebx
	ret

triggerInvalidOpcode:
	ud2
	ret