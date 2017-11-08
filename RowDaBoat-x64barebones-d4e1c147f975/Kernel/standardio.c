//Defined in stdio.asm
void printf();
char* scanf();

void putChar(char c){
	char printChar[2] = {c, 0};
	printf(printChar);
}

char getChar(){
	char* keyboardBuffer = scanf();
	int i = 0;
	while(keyboardBuffer[i++] != 0);
	return keyboardBuffer[--i];
}

int strCmp(char* a, char* b){
	int i = 0;
	while(a[i] != 0 || b[i] != 0){
		if (a[i] > b[i])
			return 1;
		else if (a[i] < b[i])
			return -1;
		i++;
	}
	return 0;
}