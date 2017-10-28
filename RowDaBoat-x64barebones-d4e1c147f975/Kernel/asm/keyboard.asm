GLOBAL getKeyboardStatus
GLOBAL getKeyboardData

section .text
getKeyboardStatus:
in al, 64h
and eax, 0x1
ret

getKeyboardData:
mov eax, 0x0
in al, 60h
ret
