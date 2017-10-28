/*
* syscalls.c
*/
#include <naiveConsole.h>

//Defined in asm/intelUtils.asm
int get_register_ebx();

//Defined in asm/keyboard.asm
int getKeyboardStatus();
int getKeyboardData();

static const char keyCodes[] = {27, '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
								'\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '{', ']', '\n',
								'\0', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '\'', 13,
								'\0', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', '\0', '\0', ' ', '\0'};

void exit(){

}

int readChar(){
	signed char input = -1;
	if (getKeyboardStatus() == 1)
		input = keyCodes[getKeyboardData()];
	return input;
}

void writeChar(){
	char input = get_register_ebx();
	ncPrintChar(input);
}