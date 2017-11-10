#include <naiveConsole.h>
#include <font.h>

static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base);

static char buffer[64] = { '0' };
static uint8_t * const video = (uint8_t*)0xB0000;
static uint8_t * currentVideo = (uint8_t*)0xB0000;
static const uint32_t width = 80;
static const uint32_t height = 25 ;

void ncPaintPixel(int x, int y, int r, int g, int b){
	int i = 0;
}

void ncPrint(const char * string)
{
	int i;

	for (i = 0; string[i] != 0; i++)
		ncPrintChar(string[i]);
}

void ncReturn(){
	currentVideo -=2;
	*currentVideo = 0;
}

void ncPrintChar(char character)
{
	//char * pixelMap = pixelMap(character);
	if (character == '\n'){
		ncNewline();
	} else if (character == 8){
		ncReturn();
	} else {
		*currentVideo = character;
		currentVideo += 2;
	}
	if (currentVideo > video + 3998)
		moveCharsUp();
}

void ncNewline()
{
	do
	{
		ncPrintChar(' ');
	}
	while((uint64_t)(currentVideo - video) % (width * 2) != 0);
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
	int i;

	for (i = 0; i < height * width; i++)
		video[i * 2] = ' ';
	currentVideo = video;
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
  currentVideo = video;
  uint8_t * auxVideo = video + width*2;
  int i;
  for(i = 0; i < width*(height-1); i++){
    *currentVideo=*auxVideo;
    currentVideo+=2;
    auxVideo+=2;
  }
	int j;
  for(j=0; j < 2 * width; j++)
      currentVideo[j++]= ' ';
			currentVideo[j]= 0;

}
