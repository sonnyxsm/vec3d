#
# Main Config
#

CC = cc
CFLAGS = -std=gnu99 -O2 
LDFLAGS = -lm -lraylib

SRC = main.c engine.c world.c
OBJ = ${SRC:.c=.o}
TARGET = a.out

all: ${TARGET}

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)

clean:
	rm -f ${OBJ} ${TARGET}

.DEFAULT_GOAL: all

.PHONY: clean
