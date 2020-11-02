include Makefile.in

.PHONY: all clean new distclean config Makefile.env
OBJS = main/start.o system/system.o lib/lib.a

.PHONY: distclean load new clean all

all: Makefile.in
	make -C main
	make -C system
	make -C lib
	$(LD) $(LDFLAGS) -o tkernel $(OBJS)

config Makefile.in:
	sed '/### Environment ###/q' Makefile.in > Makefile.tmp
	echo "TOPLEVEL := `pwd`" >> Makefile.tmp
	echo -e 'INCLUDEDIR := \044(TOPLEVEL)/include' >> Makefile.tmp
	echo -e 'CFLAGS := \044(CFLAGS) -I \044(INCLUDEDIR)' >> Makefile.tmp
	mv Makefile.tmp Makefile.in

clean:
	make -C system clean
	make -C main clean
	make -C lib clean

new: distclean all load

load: tkernel
	su -c "cp tkernel /boot"
	-sync

distclean:
	make -C system distclean
	make -C main distclean
	make -C lib distclean
