#include <syscalls.h>

//Syscalls interrupt handler
void handle_syscall(int id, int param1, int param2, int param3){
	switch (id){
		//Exit
		case 0:
			break;
		//GetKeyboardBuffer
		case 1:
			//getKeyboardBuffer();
			break;
		//WriteChar (to screen)
		case 2:
			write(param1);
			break;
	}
	return;
}

static const char keyCodes[] = {27, '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
								'\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '{', ']', '\n',
								'\0', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '\'', 13,
								'\0', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', '\0', '\0', ' ', '\0'};

// void handle_keyboard_input(int input){
// 	static char* buffer;
// 	static int bufferLength = 0;

// 	buffer[bufferLength++] = keyCodes[input];
// }

