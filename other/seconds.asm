section .text
global getseconds

getseconds:
    push ebp
    mov ebp, esp

    mov al, 0
    out 70h, al
    in ax, 71h
    movzx eax, ax

    mov esp, ebp
    pop ebp
    ret
