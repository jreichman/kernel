include ../../Makefile.in

SOURCE := asprintf.c printf.c snprintf.c sscanf.c vasprintf.c \
				vsnprintf.c scanf.c sprintf.c vprintf.c vsprintf.c \
				printf_parse.c
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
