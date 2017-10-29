GLOBAL endOfInterrupt
section .text
endOfInterrupt:
	mov al, 20h
	out 20h, al
	iretq