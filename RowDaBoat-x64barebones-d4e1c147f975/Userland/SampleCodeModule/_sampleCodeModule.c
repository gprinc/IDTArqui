#include "standardio.h"
#include "strings.h"
#include "system.h"
/* _sampleCodeModule.c */

void startShell();
void startGraphicMode();
void printTime();
void graphicCuadraticFunction();
void colorCrossAxis();


int main() {
    printf("Welcome to JuguluOS!");


    startShell();
    return 0;
}

void displayHelp(){
    printf("These are the possible commands you can use:\n");
    printf( "-$ help \n     Prints message to shell console, describing the programs available to the user.\n");
    printf("\n-$ time \n     Prints the current system time to the screen.\n");
    printf("\n-$ graphicmode [M VALUE] [B VALUE] [POWER]\n     Draws a representation of a linear function, given through the shell,to the screen. \n");
    printf("\n-$ zerodivision\n     Executes a program created to test the handling of Zero Division exceptions on the system.\n");
    printf("\n-$ overflow\n     Executes a program created to test the handling of Overflow exceptions on the system.\n");
    printf(" \n-$ invalidopcode\n     Executes a program created to test the handling of Invalid Operation Code exceptions on the system.\n");
    //printf("That's it.\n");
}

void startShell(){
        printf("\nPlease enter a command. For a list of commands, enter \"help\".\n");
    int _exit = 0;
    char input[100];
    while(!_exit){
        int result = scanf(input);
        if (result != 0){

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
            } else if (strContains("graphicmode", input) && input[length-1] == '\n'){
                startGraphicMode(input);
            } else if (!strCmp(input, "time\n")){
                printTime();
            } else if (input[length-1] == '\n'){
                printf("Command not recognized. For a list of commands, enter \"help\".\n");
            }
        }
    }
    printf("Exiting shell. Goodbye!\n");
    return;
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

void startGraphicMode(char* input){
    int a = 0, b = 0, c = 0;
    char buffer[100];
    char current;
    int i = 0, j = 0;
    int nextNum = 0;
    //putChar(input[j]);
    printf("Hola");
    for (int k = 0; k < 3; k++){
        nextNum = 0;
        while ((current = input[j++]) != 0 && !nextNum){
            if (current >= '0' && current <= '9'){
                buffer[i++] = current;
                if (input[j] < '0' || input[j] > '9'){
                    buffer[i] = 0;
                    switch(k){
                        case 0:
                            a = parseInt(buffer);
                            break;
                        case 1:
                            b = parseInt(buffer);
                            break;
                        case 2:
                            c = parseInt(buffer);
                            break;
                    }
                    i = 0;
                    nextNum = 1;
                }
                    
            }
        }
    }
    printNum(a);
    putChar('\n');
    printNum(b);
        putChar('\n');

    printNum(c);
    graphicCuadraticFunction(0, -1, 10);
    return;
}

void graphicCuadraticFunction(int a, int b, int c){
  int aux = a + b + c;
  int defaultSpace = 1;
  colorCrossAxis();
  int x;
  int y;
  while(aux > (getScreenHeight()/2)*defaultSpace) {
    defaultSpace *= 10;
  }
  for(x=0; x < getScreenWidth() ; x++) {
    //x = getScreenWidth()/2 - x;
    y = (a*(x^2) + b*x + c)*defaultSpace;
    y = getScreenHeight()/2 - y;
    paintPixel(x, y, 255, 0, 0);
  }
}

// void graphicCuadraticFunction(int a, int b, int c){
//     int unitWidth = 10, unitHeight = 10;
//     int xUnitsPerScreen = getScreenWidth() / unitWidth;
//     int yUnitsPerScreen = getScreenHeight() / unitHeight;
// }

// void screenToWorldCoordinates(int* x, int* y, int defaultSpace){
//     *x = (*x -getScreenWidth/2)/defaultSpace;
//     *y = (getScreenHeight/2 - *y)/defaultSpace;
// }

void colorCrossAxis() {
  int x = getScreenWidth() / 2;
  int y;
  for(y=0; y < getScreenHeight(); y++) {
    paintPixel(x, y, 255, 255, 255);
  }
  y=getScreenHeight()/2;
  for(x=0; x < getScreenWidth(); x++){
    paintPixel(x, y, 255, 255, 255);
  }
}