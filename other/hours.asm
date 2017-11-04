section .text
global gethours

gethours:
    push ebp
    mov ebp, esp


    mov al, 4
    out 70h, al
    in ax, 71h
    movzx eax, ax

    mov esp, ebp
    pop ebp
    ret
