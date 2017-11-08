#include <standardio.h>
#include <naiveConsole.h>
#define BUFFER_SIZE 100
char buffer[BUFFER_SIZE];
int bufferLength = 0;

static const char keyCodes[] = {27, '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
								'\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '{', ']', '\n',
								' ', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', ' ', ' ', '\n',
								' ', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', ' ', ' ', ' ', ' '};

void handle_keyboard_input(int input){
	//Sprintf("We have entered the keyboard handler...Fascinating");
	if (input >= 128)
		return;
	putChar(keyCodes[input]);
	buffer[bufferLength++] = keyCodes[input];
	buffer[bufferLength] = 0;
}

char* getKeyboardBuffer(){
	char aux[100];
	for (int i = 0; i < bufferLength; i++){
		aux[i] = buffer[i];
	}
	if (buffer[bufferLength-1] == '\n')
		bufferLength = 0;
	return aux;
}

int getKeyboardBufferLength(){
	return bufferLength;
}

void clearBuffer(){
	for (int i = 0; i < BUFFER_SIZE; i++)
		buffer[i] = 0;
	bufferLength = 0;
}