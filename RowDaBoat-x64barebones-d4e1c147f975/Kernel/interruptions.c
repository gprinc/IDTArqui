#include <syscalls.h>
#include "keyboard.h"

//Syscalls interrupt handler
int handle_syscall(int id, int param1, int param2, int param3){
	switch (id){
		//Exit
		case 0:
			break;
		//Read
		case 1:
			//putChar(getKeyboardBufferLength() + 48);
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
	}
	return;
}