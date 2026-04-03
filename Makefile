CC = gcc
CFLAGS = -Wall
SRC = src/main.c src/login.c
OBJ = main

all: $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -o $(OBJ) $(SRC)

clean:
	rm -f $(OBJ)
