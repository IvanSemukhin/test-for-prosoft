CC=gcc
CFLAGS=-c -Wall
LDFLAGS=-lm

all: print_bin

print_bin: print_bin.c
	$(CC) print_bin.c -o print_bin $(LDFLAGS)

clean:
	rm -rf *.o print_bin
