#include <syscalls.h>

//Defined in asm/intelUtils.asm
int get_register_eax();

//Syscalls interrupt handler
void handle_syscall(){
	int id = get_register_eax();
	switch (id){
		//Exit
		case 0:
			break;
		//ReadChar (from keyboard)
		case 1:
			readChar();
			break;
		//WriteChar (to screen)
		case 2:
			writeChar();
			break;
	}
	return;
	// asm("mov al, 20h
	// out 20h, al
	// iretq");
}

