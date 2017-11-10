//Defined in standardio.asm
void printf(char * string);
char* scanf();
void clearScreen();

//Defined in standardio.c
void putChar(char c);
void printNum();
char getChar();
int strCmp(char* a, char* b);
int strContains(char* a, char* b);