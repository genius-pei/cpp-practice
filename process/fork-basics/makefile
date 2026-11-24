CC   = gcc
BINS = process myprocess

all: $(BINS)

process: process.c
	$(CC) -o $@ $<

myprocess: myprocess.c
	$(CC) -o $@ $<

.PHONY: all clean
clean:
	rm -f $(BINS)
