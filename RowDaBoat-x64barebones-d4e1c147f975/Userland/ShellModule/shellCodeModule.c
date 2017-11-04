/* sampleCodeModule.c */
#include <stdio.h>

char * v = (char*)0xB8000 + 79 * 2;

static int var1 = 0;
static int var2 = 0;


int main() {
	//All the following code may be removed 
	*v = 'X';
	*(v+1) = 0x74;

	//Test if BSS is properly set up
	if (var1 == 0 && var2 == 0)
		return 0xDEADC0DE;

	return 0xDEADBEEF;
}

void enterConsoleMode(){
    int _exit = 0;
    char keyboardStatus;
    char input;
    while (!_exit){
    	input = 0;
    	if (getKeyboardStatus() == 1){
    		input = getKeyboardData();
    	}
    	if (input >= 0 && input < 57 && input != '\0'){
    		ncPrintChar(keyCodes[input]);
    	}
       if (input == 0x01){
          ncPrintChar('Exiting console.');
           _exit = 1;
       }
    }
}