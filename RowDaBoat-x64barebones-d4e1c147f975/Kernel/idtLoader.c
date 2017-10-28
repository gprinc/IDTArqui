/*
* IDT.c
*/
#pragma pack(push)
#pragma pack (1)

typedef struct {
	uint16_t offset_l;
	uint16_t selector;
	uint8_t cero;
	uint8_t access;
	uint16_t offset_m;
	uint32_t offset_h;
	uint32_t other_cero;
} INT_DESCR;

#pragma pack(pop)

INT_DESCR * idt = (INT_DESCR *) 0;

void initIDT(){

	//Access denied exception (cooler name for SegFault)
	setup_IDT_entry(0x0, (uint64_t)&exc_access_denied);

	//Syscalls interruption
	setup_IDT_entry(0x20 + 0x80, (uint64_t)&int_syscall);

	//Syscalls interruption
	setup_IDT_entry(0x80, (uint64_t)&int_syscall);

}

void setup_IDT_entry (int index, uint64_t offset) {
	idt[index].offset_l = offset & 0xFFFF;
	idt[index].selector = 0x08;
	idt[index].cero = 0;
	idt[index].access = ACS_INT;
	idt[index].offset_m = (offset >> 16) & 0xFFFF;
	idt[index].offset_h = (offset >> 32) & 0xFFFFFFFF;
	idt[index].other_cero = 0;
}