#include <stdint.h>
#include <string.h>
#include <lib.h>
#include <idtLoader.h>
#include <moduleLoader.h>
#include <naiveConsole.h>
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

	ncPrint("[x64BareBones]");
	ncNewline();

	ncPrint("CPU Vendor:");
	ncPrint(cpuVendor(buffer));
	ncNewline();

	ncPrint("[Loading modules]");
	ncNewline();
	void * moduleAddresses[] = {
		sampleCodeModuleAddress,
		sampleDataModuleAddress
	};

	loadModules(&endOfKernelBinary, moduleAddresses);
	ncPrint("[Done]");
	ncNewline();
	ncNewline();

	ncPrint("[Initializing kernel's binary]");
	ncNewline();

	clearBSS(&bss, &endOfKernel - &bss);

	ncPrint("  text: 0x");
	ncPrintHex((uint64_t)&text);
	ncNewline();
	ncPrint("  rodata: 0x");
	ncPrintHex((uint64_t)&rodata);
	ncNewline();
	ncPrint("  data: 0x");
	ncPrintHex((uint64_t)&data);
	ncNewline();
	ncPrint("  bss: 0x");
	ncPrintHex((uint64_t)&bss);
	ncNewline();

	initIDT();
	ncNewline();

	ncPrint("[Done]");
	ncNewline();
	ncNewline();
	return getStackBase();
}

void write_a();
int main() {

	ncPrint("[Finished]");
	write_a();
	//printf("Hello");
	ncPrint("SUCCESS!");

	return 0;
}
// ncPrint("Veamos si llega a los 80 caracteres y ver que pasa. Solo me quedan 30 caracteres.");

// void enterTextMode(){
//     int _exit = 0;
//     char keyboardStatus;
//     char input;
//     while (!_exit){
//     	input = 0;
//     	if (getKeyboardStatus() == 1){
//     		input = getKeyboardData();
//     	}
//     	if (input >= 0 && input < 57 && input != '\0'){
//     		ncPrintChar(keyCodes[input]);
//     	}
//        if (input == 0x01){
//           ncPrintChar('Exiting console.');
//            _exit = 1;
//        }
//     }
// }
