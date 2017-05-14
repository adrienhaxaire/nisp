#include ../Makefile.in

SRCS := $(wildcard *.c)
OBJS := ${SRCS:c=o}

CFLAGS := -W -Wall -g -std=c11

nisp: $(OBJS)
	$(CC) $(OBJS) -o nisp

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o nisp
