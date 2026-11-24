BIN = main
CC  = gcc
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

$(BIN): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJ) $(BIN)
