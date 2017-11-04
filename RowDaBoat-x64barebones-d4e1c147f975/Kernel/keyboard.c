static char* buffer;
static int bufferLength = 0;

static const char keyCodes[] = {27, '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
								'\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '{', ']', '\n',
								'\0', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '\'', 13,
								'\0', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', '\0', '\0', ' ', '\0'};

void handle_keyboard_interruption(int input){
	buffer[bufferLength++] = keyCodes[input];
}

char getChar(){
	return buffer[(bufferLength--)-1];
}

void resetBuffer(){
	
}