include ../../Makefile.in

SOURCE := abs.c calloc.c clearenv.c free.c getenv.c itoa.c labs.c \
				malloc.c putenv.c realloc.c setenv.c strtod.c strtof.c \
				strtol.c strtold.c strtoul.c unsetenv.c
OBJS = $(patsubst %.c, %.o, $(SOURCE))

.PHONY: all clean distclean

.EXPORT_ALL_VARIABLES:

all: $(OBJS)

$(OBJS): dep.mak
	make -f dep.mak $@

dep.mak: $(SOURCE)
	$(CC) $(CFLAGS) -M $(SOURCE) > dep.mak

clean:
	-rm -f *.o dep.mak

distclean: clean
