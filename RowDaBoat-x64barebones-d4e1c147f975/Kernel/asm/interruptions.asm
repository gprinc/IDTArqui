EXTERN handle_syscall
EXTERN handle_keyboard_input
GLOBAL int_keyboard
GLOBAL int_syscall
GLOBAL _sti
GLOBAL picMasterMask
GLOBAL picSlaveMask

section .text

int_syscall:

	call handle_syscall

	iretq


int_keyboard:
	pushState

	mov rax, 0x0
	mov rdi, 0x0
	in al, 60h
	movzx rdi, al
	mov rdi, 0x2
	mov rsi, a
	call handle_syscall

	mov al, 20h
	out 20h, al

	popState
	iretq

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

section .data
a db "INT 21h lauched BIATCH"