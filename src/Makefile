#include ../Makefile.in

SRCS := $(wildcard *.c)
OBJS := ${SRCS:c=o}

nisp: $(OBJS)
	$(CC) $(OBJS) -o nisp

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o nisp
