include ../Makefile.in

DIRS := stdio stdlib
ARCHIVE := lib.a

.PHONY: all clean distclean

all: $(ARCHIVE)

$(ARCHIVE): $(DIRS)
	-rm -f $(ARCHIVE)
	for i in $(DIRS) ; do make -C $$i && $(AR) $(ARFLAGS) $(ARCHIVE) $$i/*.o; done

clean:
	for i in $(DIRS) ; do make -C $$i clean ; done

distclean:
	for i in $(DIRS) ; do make -C $$i distclean ; done
	-rm -f $(ARCHIVE)
