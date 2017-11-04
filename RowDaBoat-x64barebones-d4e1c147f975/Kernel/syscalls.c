/*
* syscalls.c
*/
#include <naiveConsole.h>

//Defined in asm/intelUtils.asm
int get_register_ebx();

//Defined in asm/keyboard.asm
int getKeyboardStatus();
int getKeyboardData();



void exit(){

}

// int readChar(){
// 	signed char input = -1;
// 	if (getKeyboardStatus() == 1)
// 		input = keyCodes[getKeyboardData()];
// 	return input;
// }

void write(char * string){
	//ncPrint("Hello darkess my old friendo :^)");
	ncPrint(string);
}