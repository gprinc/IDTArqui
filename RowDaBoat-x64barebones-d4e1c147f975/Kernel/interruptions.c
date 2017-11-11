#include <syscalls.h>
#include "keyboard.h"
#include "time.h"

static void* currentMemPtr = (void*)0x1000000;


//Syscalls interrupt handler
int handle_syscall(int id, int param1, int param2, int param3, int param4, int param5){
	void* aux = (void*)currentMemPtr;
	switch (id){
		//Malloc
		case 0:
			currentMemPtr += param1;
			return aux;
			break;

		//Read
		case 1:
			if (getKeyboardBufferLength() > 0)
				return getKeyboardBuffer();
			else
				return -1;
			break;

		//Write
		case 2:
			ncPrint(param1);
			break;

		//Clear screen
		case 3:
			ncClear();
			break;

		//System Time
		case 4:
			switch(param1){
				case 0:
					return getSeconds();
					break;
				case 1:
					return getMinutes();
					break;
				case 2:
					return getHours();
					break;
			}
			break;

		//PaintPixel
		case 5:
			break;

	}
	return;
}