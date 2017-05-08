#include ../Makefile.in

nisp: main.o
	$(CC) main.o -o nisp

%.o: %.c
	$(CC) -c $<

clean:
	rm *.o nisp
