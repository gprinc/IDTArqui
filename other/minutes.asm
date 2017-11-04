section .text
global getminutes

getminutes:
    push ebp
    mov ebp, esp

    mov al, 2
    out 70h, al
    in ax, 71h
    movzx eax, ax

    mov esp, ebp
    pop ebp
    ret
