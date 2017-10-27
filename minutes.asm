section .text
global getminutes

getminutes:
    mov al, 2
    out 70h, al
    in ax, 71h
    movzx eax, ax
    ret
