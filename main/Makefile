include ../Makefile.in

CFLAGS := $(CFLAGS) -I ../include
SOURCE := main.c
OBJS = loader.o idt.o gdt.o main.o
ARCHIVE := start.o

.PHONY: all clean distclean

.EXPORT_ALL_VARIABLES:

all: $(OBJS)
	$(LD) -r -o $(ARCHIVE) $(OBJS)

loader.o: loader.asm
	nasm -f elf loader.asm -o loader.o

gdt.o: gdt.asm
	nasm -f elf gdt.asm -o gdt.o

idt.o: idt.asm
	nasm -f elf idt.asm -o idt.o

main.o: dep.mak
	make -f dep.mak main.o

dep.mak: $(SOURCE)
	$(CC) $(CFLAGS) -M $(SOURCE) > dep.mak

clean:
	-rm -f *.o dep.mak

distclean: clean
