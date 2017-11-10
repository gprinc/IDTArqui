#include "standardio.h"
#include "system.h"
#include "exceptionTriggers.h"

/* sampleCodeModule.c */
//void print(const char * string);

int main() {
	printf("Welcom to GuinsaOS!");
	putChar(1);
	printf("\nPlease enter a command. For a list of commands, enter \"help\".\n");
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

            int length = 0;
            while(input[length++] != 0);
            length--;

    		if (!strCmp(input, "help\n")){
    			displayHelp();
    		} else if (!strCmp(input, "exit\n")){
    			_exit = 1;
    		} else if (!strCmp(input, "zerodivision\n")){
    			triggerDivideByZero();
    		} else if (!strCmp(input, "overflow\n")){
    			triggerOverflow();
    		} else if (!strCmp(input, "invalidopcode\n")){
    			triggerInvalidOpcode();
    		} else if (!strCmp(input, "time\n")){
                printTime();
            } else if (input[length-1] == '\n'){
                printf("Command not recognized. For a list of commands, enter \"help\".\n");
            }
    	}
    }
    printf("Exiting shell. Goodbye!\n");
}

void printTime() {
    int h = getSystemHours();
    int m = getSystemMinutes();
    int s = getSystemSeconds();

    char timeString[10] = {
        h / 10 + '0',
        h % 10 + '0',
        ':',
        m / 10 + '0',
        m % 10 + '0',
        ':',
        s / 10 + '0',
        s % 10 + '0',
        '\n',
        0
    };
    printf("Current time:\n");
    printf(timeString);
}