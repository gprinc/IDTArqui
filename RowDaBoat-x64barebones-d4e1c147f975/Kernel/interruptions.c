#include <syscalls.h>
#include <keyboard.h>

//Syscalls interrupt handler
void handle_syscall(int id, int param1, int param2, int param3){
	switch (id){
		//Exit
		case 0:
			break;
		//Read
		case 1:
			if (getKeyboardBuffer() > 0)
				return getKeyboardBuffer();
			break;
		//Write
		case 2:
			write(param1);
			break;
	}
	return;
}