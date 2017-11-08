#include "standardio.h"

/* sampleCodeModule.c */
//void print(const char * string);

int main() {
	//startShell();
	//ncPrintChar('h');
	clearScreen();
	printf("Welcom to GuinsaOS! Please enter a command. For a list of commands, enter \"help\".\n");
	startShell();
	return 0;
}

void displayHelp(){
	printf("These are the possible commands you can use:\n");
	printf("That's it.\n");
}

void startShell(){
    int _exit = 0;
    char* input;
    while(!_exit){
    	input = scanf();
    	if ((int)input != -1){
    		if (!strCmp(input, "help\n")){
    			displayHelp();
    		} else if (!strCmp(input, "time")){

    		} else if (!strCmp(input, "time")){

    		} else if (!strCmp(input, "time")){

    		} else if (!strCmp(input, "time")){

    		}
    	}    	
    }
}

