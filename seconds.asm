section .text
global getseconds

getseconds:
    mov al, 0
    out 70h, al
    in ax, 71h
    movzx eax, ax
    ret
