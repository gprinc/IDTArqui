#include <stdio.h>
char buffer[100];
int bufferLength = 0;

static const char keyCodes[] = {27, '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
								'\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '{', ']', '\n',
								'\0', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '\'', 13,
								'\0', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', '\0', '\0', ' ', '\0'};

void handle_keyboard_input(int input){
	printf("We have entered the keyboard handler...Fascinating");
	printf(keyCodes[input]);
	buffer[bufferLength++] = keyCodes[input];
}

char* getKeyboardBuffer(){
	char aux[100];
	for (int i = 0; i < bufferLength; i++){
		aux[i] = buffer[i];
	}
	bufferLength = 0;
	return aux;
}

void getKeyboardBufferLength(){
	return bufferLength;
}