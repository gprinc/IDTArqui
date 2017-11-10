#include <naiveConsole.h>

uint16_t width;
uint16_t height;
uint8_t* videoBasePtr;

uint8_t getModeInfo();

typedef struct __attribute__((packed)) ModeInfoBlock {
  uint16_t attributes;
  uint8_t winA,winB;
  uint16_t granularity;
  uint16_t winsize;
  uint16_t segmentA, segmentB;
  uint32_t FARWindowPositioning;
  uint16_t pitch; // bytes per scanline
 
  uint16_t Xres, Yres;
  uint8_t Wchar, Ychar, planes, bpp, banks;
  uint8_t memory_model, bank_size, image_pages;
  uint8_t reserved0;
 
  uint8_t red_mask, red_position;
  uint8_t green_mask, green_position;
  uint8_t blue_mask, blue_position;
  uint8_t rsv_mask, rsv_position;
  uint8_t directcolor_attributes;
 
  uint32_t physbase;  // your LFB (Linear Framebuffer) address ;)
  uint32_t reserved1;
  uint16_t reserved2;
} ModeInfoBlock_t;

void initVideoDriver(){
	ModeInfoBlock_t* infoBlock = 0x5C00;
	videoBasePtr = infoBlock->physbase;
	width = infoBlock->Xres;
	height = infoBlock->Yres;
}

uint16_t getScreenWidth(){
	return width;
}

uint16_t getScreenHeight(){
	return height;
}

uint8_t* getVideoBasePtr(){
	ModeInfoBlock_t* infoBlock = 0x5C00;
	return (uint8_t*) infoBlock->physbase;
}

void paintPixel(int x, int y, int r, int g, int b){
		uint8_t * currentVideo = videoBasePtr;

		currentVideo += 3 * (x + width * y);

		*currentVideo = b;
		currentVideo++;
		*currentVideo = g;
		currentVideo++;
		*currentVideo = r;
}

void fillScreen(){
	uint8_t * currentVideo = videoBasePtr;
	for (int i = 0; i < width * 1 * height ; i++){
		*currentVideo = 255;
		currentVideo++;
	}
}

