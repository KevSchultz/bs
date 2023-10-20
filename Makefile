# Makefile for ncurses learning/bs code 

CC = clang
CFLAGS = 

all : bs

bs : bs.o
	$(CC) bs.o -o bs -lncurses

bs.o : bs.c
	$(CC) $(CFLAGS) -c bs.c 

clean: 
	rm -f bs.o bs

install: all
	cp -f bs ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/bs

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/bs
