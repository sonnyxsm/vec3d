#
# Main Config
#

CC = cc
CFLAGS = -std=gnu99 
LDFLAGS = -lraylib

SRC = main.c engine.c render.c scene.c entity.c
OBJ = ${SRC:.c=.o}
TARGET = a.out

all: ${TARGET}

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)

clean:
	rm -f ${OBJ} ${TARGET}

.DEFAULT_GOAL: all

.PHONY: clean
