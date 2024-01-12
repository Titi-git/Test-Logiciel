CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -lcunit

all: morpion test_morpion

morpion: morpion.c morpion_funcs.c morpion_funcs.h
	$(CC) $(CFLAGS) -o morpion morpion.c morpion_funcs.c

test_morpion: test_morpion.c morpion_funcs.c morpion_funcs.h
	$(CC) $(CFLAGS) -o test_morpion test_morpion.c morpion_funcs.c $(LDFLAGS)

clean:
	rm -f morpion test_morpion
