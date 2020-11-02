include ../Makefile.in

CFLAGS := $(CFLAGS) -I ../include
SOURCE := console.c kfunc.c interrupts.c
OBJS = $(patsubst %.c, %.o, $(SOURCE))
ARCHIVE := system.o

.PHONY: all clean distclean

.EXPORT_ALL_VARIABLES:

all: $(OBJS)
	$(LD) -r -o $(ARCHIVE) $(OBJS)

$(OBJS): dep.mak
	make -f dep.mak $@

dep.mak: $(SOURCE)
	$(CC) $(CFLAGS) -M $(SOURCE) > dep.mak

clean:
	-rm -f *.o dep.mak

distclean: clean
