section .text
global gethours

gethours:
    mov al, 4
    out 70h, al
    in ax, 71h
    movzx eax, ax
    ret
