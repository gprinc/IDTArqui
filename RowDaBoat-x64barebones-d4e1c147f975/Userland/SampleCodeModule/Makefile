include ../Makefile.inc

MODULE=0000-sampleCodeModule.bin
SOURCES=$(wildcard [^_]*.c)
SOURCES_ASM=$(wildcard asm/*.asm)

OBJECTS=$(SOURCES:.c=.o)
OBJECTS_ASM=$(SOURCES_ASM:.asm=.o)



all: $(MODULE)

$(MODULE): $(SOURCES)
	$(GCC) $(GCCFLAGS) -T sampleCodeModule.ld _loader.c $(SOURCES) $(OBJECTS_ASM) -o ../$(MODULE) -I./include -I./asm

clean:
	rm -rf *.o

.PHONY: all clean print
