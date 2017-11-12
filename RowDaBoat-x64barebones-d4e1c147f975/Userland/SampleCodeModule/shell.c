#include "shell.h"
#include "standardio.h"
#include "strings.h"
#include "system.h"
#include "math.h"
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
                //printNum(parseInt("3"));
                startGraphicMode(input, length);
                //plotQuadraticFunction(0, 32, -20);
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

void startGraphicMode(const char* input, int length){
    int a = 0, b = 0, c = 0;
    char numBuffer[30];
    char current;
    int bufferInfex = 0, letterIndex = 0;
    int nextNum = 0;
    for (int i = 0; i < length; i++){
        if (input[i] > '9' || input[i] < '0'){
            printf("*");
        }
        else{
            numBuffer[bufferInfex++] = input[i];
            //putChar(numBuffer[bufferInfex -1]);

            if (input[i+1] > '9' || input[i+1] < '0'){
                numBuffer[bufferInfex] = 0;
                switch(letterIndex){
                    case 0:
                        a = parseInt(numBuffer);
                        printNum(a);
                        break;
                    case 1:
                        b = parseInt(numBuffer);
                        break;
                    case 2:
                        c = parseInt(numBuffer);
                        break;
                }
                putChar('-');
                bufferInfex = 0;
                letterIndex++;
            }
                
        }
    }
    printNum(a);
    printNum(a);
    printNum(a);
    putChar('\n');
    printNum(a);
    //printNum(a);
    // printNum(b);
    // putChar('\n');
    // printNum(c);
    //clearScreen();
    plotQuadraticFunction(0, -1, 10);
    return;
}

void graphicCuadraticFunction(int a, int b, int c){
  int aux = a + b + c;
  int defaultSpace = 1;
  colorCrossAxis(2, 3);
  int x;
  int y;
  while(aux > (getScreenHeight()/2)*defaultSpace) {
    defaultSpace *= 10;
  }
  for(x=0; x < getScreenWidth() ; x++) {
    y = (a*(pow(x, 2)) + b*x + c)*defaultSpace;
    y = getScreenHeight()/2 - y;
    paintPixel(x, y, 255, 0, 0);
  }
}

void plotQuadraticFunction(int a, int b, int c){
    int unitWidth = 10, unitHeight = 10;
    int xUnitsPerScreen = getScreenWidth() / unitWidth;
    int yUnitsPerScreen = getScreenHeight() / unitHeight;
    int difY = mod(a*(2*2) + b*2 + c) + mod(a*(-2)*2 + b*(-2) + c);
    while (yUnitsPerScreen < difY + 4 ){
        unitHeight--;
        unitWidth--;
        yUnitsPerScreen = getScreenHeight()/unitHeight;
    }
    if (unitHeight < 1) unitHeight = 1;
    if (unitWidth < 1) unitWidth = 1;
    colorCrossAxis(unitWidth, unitHeight);
    float x, y;

    for (x = 0; x < getScreenWidth(); x++){
        screenToWorldCoordinates(&x, &y, unitWidth, unitHeight);
        y = a*(pow(x, 2)) + b*x + c;
        worldToScreenCoordinates(&x, &y, unitWidth, unitHeight);
        paintPixel((int)x, (int)y, 255, 0, 0);
    }
}

void screenToWorldCoordinates(float* x, float* y, int unitWidth, int unitHeight){
    *x = (*x -getScreenWidth()/2)/unitWidth;
    *y = (getScreenHeight()/2 - *y)/unitHeight;
}

void worldToScreenCoordinates(float* x, float* y, int unitWidth, int unitHeight){
    *x = *x * unitWidth + getScreenWidth()/2;
    *y = getScreenHeight()/2 - *y * unitHeight;
}

void colorCrossAxis(int unitWidth, int unitHeight) {
  int x = getScreenWidth() / 2;
  int y;
  for(y= unitHeight; y < getScreenHeight() - unitHeight; y++) {
    paintPixel(x, y, 255, 255, 255);
    if (y % unitHeight == 0){
        paintPixel(x + 1, y, 255, 255, 255);
        paintPixel(x - 1, y, 255, 255, 255);
    }
  }
  y=getScreenHeight()/2;
  for(x=unitWidth; x < getScreenWidth() - unitWidth; x++){
    paintPixel(x, y, 255, 255, 255);
    if (x % unitWidth == 0){
        paintPixel(x, y+1, 255, 255, 255);
        paintPixel(x, y-1, 255, 255, 255);
    }
  }
}