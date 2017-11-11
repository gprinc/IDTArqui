#include <stdint.h>
#include <string.h>
#include <lib.h>
#include <idtLoader.h>
#include <moduleLoader.h>
#include <naiveConsole.h>
#include <videoDriver.h>
#include <stdio.h>

extern uint8_t text;
extern uint8_t rodata;
extern uint8_t data;
extern uint8_t bss;
extern uint8_t endOfKernelBinary;
extern uint8_t endOfKernel;

static const uint64_t PageSize = 0x1000;

static void * const sampleCodeModuleAddress = (void*)0x400000;
static void * const sampleDataModuleAddress = (void*)0x500000;

typedef int (*EntryPoint)();


void clearBSS(void * bssAddress, uint64_t bssSize)
{
	memset(bssAddress, 0, bssSize);
}

void * getStackBase()
{
	return (void*)(
		(uint64_t)&endOfKernel
		+ PageSize * 8				//The size of the stack itself, 32KiB
		- sizeof(uint64_t)			//Begin at the top of the stack
	);
}

void * initializeKernelBinary()
{
	char buffer[10];
	initVideoDriver();

	ncPrint("[Initializing kernel...]");
	void * moduleAddresses[] = {
		sampleCodeModuleAddress,
		sampleDataModuleAddress
	};

	loadModules(&endOfKernelBinary, moduleAddresses);

	clearBSS(&bss, &endOfKernel - &bss);

	initIDT();

	return getStackBase();
}

int main() {
	initVideoDriver();

	printf("[Kernel initialized, starting first module...]\n");

	//clearScreen();
	//fillScreen();
	//paintPixel(600, 600, 255, 0, 255);
	//paintPixel(639, 3, 255, 0, 255);
	//fillScreen();
	ncPrintChar('H');
		ncPrintChar('o');

	ncPrintChar('l');

	ncPrintChar('a');

	char * string = " wtf";
	ncPrint(string);
	//ncPrint("Holiis");

	// for (int i = 0; i < 475; i++){
	// 	paintPixel(50, i, 0, 255, 0);
	// }
	// fillScreen(255, 0, 255);
	// ncClear();
	((EntryPoint)sampleCodeModuleAddress)();


	return 0;
}
// ncPrint("Veamos si llega a los 80 caracteres y ver que pasa. Solo me quedan 30 caracteres.");


