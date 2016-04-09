## Simple SDL mini code

CC=clang

CPPFLAGS= 'pkg-config --cflags sdl'
CFLAGS= -Wall -Wextra -Werror -std=c99 -03
LDFLAGS=
LDLIBS= 'pkg-config --libs sdl' -lSDL_image

SRC= pixel_operations.c main.c
OBJ= ${SRC:.c=.o}

all: main

main: ${OBJ}

clean:
	rm -f *~ *.o
	rm -f main
# END