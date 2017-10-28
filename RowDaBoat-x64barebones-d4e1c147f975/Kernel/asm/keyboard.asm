GLOBAL getKeyboardStatus
GLOBAL getKeyboardData

section .text
getKeyboardStatus:
in al, 64h
and eax, 0x1h
ret

getKeyboardData:
mov eax, 0x0h
in al, 60h
ret