#include "standardio.h"
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

    		}
    	}
    }
}

