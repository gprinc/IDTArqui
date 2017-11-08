EXTERN handle_syscall
EXTERN handle_keyboard_input
EXTERN handle_exc_divide_by_0
EXTERN handle_exc_overflow
EXTERN handle_exc_invalid_opcode
GLOBAL int_keyboard
GLOBAL int_syscall
GLOBAL exc_divide_by_0
GLOBAL exc_overflow
GLOBAL exc_invalid_opcode
GLOBAL _cli
GLOBAL _sti
GLOBAL picMasterMask
GLOBAL picSlaveMask

section .text

%macro pushState 0
	push rax
	push rbx
	push rcx
	push rdx
	push rbp
	push rdi
	push rsi
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15
%endmacro

%macro popState 0
	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	pop r8
	pop rsi
	pop rdi
	pop rbp
	pop rdx
	pop rcx
	pop rbx
	pop rax
%endmacro


int_syscall:

	call handle_syscall

	iretq

int_keyboard:
	pushState

	mov rax, 0x0
	mov rdi, 0x0
	in al, 60h
	movzx rdi, al
	call handle_keyboard_input

	mov al, 20h
	out 20h, al

	popState
	iretq


exc_divide_by_0:
	pushState

	call handle_exc_divide_by_0

	popState
	iretq

exc_overflow:
	pushState

	call handle_exc_overflow

	popState
	iretq

exc_invalid_opcode:
	pushState

	call handle_exc_invalid_opcode

	popState
	iretq


_cli:
	cli
	ret

_sti:
	sti
	ret

picMasterMask:
	push rbp
    mov rbp, rsp
    mov ax, di
    out	21h,al
    pop rbp
    retn

picSlaveMask:
	push    rbp
    mov     rbp, rsp
    mov     ax, di  ; ax = mascara de 16 bits
    out	0A1h,al
    pop     rbp
    retn

section .data
a db "INT 21h lauched BIATCH"