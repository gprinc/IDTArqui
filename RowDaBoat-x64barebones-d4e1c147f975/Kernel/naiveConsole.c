#include <naiveConsole.h>
#include <font.h>

static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base);

static char buffer[64] = { '0' };
static const uint32_t columns = 60;
static const uint32_t rows = 25 ;

//int * currentVideo = 0;
//int * video = 0;

uint8_t currentRow = 0;
uint8_t currentCol = 0;

void ncPrintChar(char character)
{
	if (character == '\n'){
		ncNewline();
	} else if (character == '\b'){
		ncReturn();
	} else {
		char * pixelMap = pixel_map(character);
		for (int i = 0; i < CHAR_HEIGHT; i++){
			char current = pixelMap[i];
			char mask[] = {128, 64, 32, 16, 8, 4, 2, 1};
			for (int j = 0; j < CHAR_WIDTH; j++){
				char aux = mask[j] & current;
				if (aux != 0)
					paintPixel(currentCol * CHAR_WIDTH + j, currentRow * CHAR_HEIGHT + i, 255, 255, 255);
			}
		}
	}

	currentCol++;
	if (currentCol > columns){
		currentRow++;
		currentCol = 0;
	}
	if (currentRow > rows){
		currentCol = 0;
		//moveCharsUp();
	}
		
}

void ncPrint(const char * string)
{
	int i;

	for (i = 0; string[i] != 0; i++)
		ncPrintChar(string[i]);
}

void ncReturn(){
	currentCol--;
	if (currentCol < 0)
		currentCol = 0;
	ncPrintChar(' ');
}



void ncNewline()
{
	currentRow++;
	currentCol = 0;
}

void ncPrintDec(uint64_t value)
{
	ncPrintBase(value, 10);
}

void ncPrintHex(uint64_t value)
{
	ncPrintBase(value, 16);
}

void ncPrintBin(uint64_t value)
{
	ncPrintBase(value, 2);
}

void ncPrintBase(uint64_t value, uint32_t base)
{
    uintToBase(value, buffer, base);
    ncPrint(buffer);
}

void ncClear()
{
	currentRow = 0;
	currentCol = 0;
	fillScreen(0, 0, 0);
}

static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base)
{
	char *p = buffer;
	char *p1, *p2;
	uint32_t digits = 0;

	//Calculate characters for each digit
	do
	{
		uint32_t remainder = value % base;
		*p++ = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
		digits++;
	}
	while (value /= base);

	// Terminate string in buffer.
	*p = 0;

	//Reverse string in buffer.
	p1 = buffer;
	p2 = p - 1;
	while (p1 < p2)
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2--;
	}

	return digits;
}

void moveCharsUp(){
	scrollScreen(CHAR_HEIGHT);
	// currentVideo = video;
	// uint8_t * auxVideo = video + columns * 2;
	// int i;
	// for(i = 0; i < columns*(rows-1); i++){
	//     *currentVideo=*auxVideo;
	//     currentVideo+=2;
	//     auxVideo+=2;
	// }
	// int j;
 //  	for(j=0; j < 2 * columns; j++)
 //      currentVideo[j++]= ' ';
	// currentVideo[j]= 0;
}
