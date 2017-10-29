
void endOfInterrupt();

//Syscalls interrupt handler
void int_syscall(int id){
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
	endOfInterrupt();
}

