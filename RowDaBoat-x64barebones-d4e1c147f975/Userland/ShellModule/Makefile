include ../Makefile.inc

MODULE=0000-shellCodeModule.bin
SOURCES=$(wildcard [^_]*.c)

all: $(MODULE)

$(MODULE): $(SOURCES)
	$(GCC) $(GCCFLAGS) -T shellModule.ld _loader.c $(SOURCES) -o ../$(MODULE)

clean:
	rm -rf *.o

.PHONY: all clean print
