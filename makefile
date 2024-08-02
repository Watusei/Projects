CC=gcc
CFLAGS=-Wall -g
LDFLAGS=-pthread

# Define the objects
OBJECTS=main.o sudoku.o thread_functions.o utils.o

# Define the executable output
EXEC=mssv

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

# Each .o file depends on its corresponding .c file and all .h files
%.o: %.c $(wildcard *.h)
	$(CC) $(CFLAGS) -c $<

# Clean up
clean:
	rm -f $(OBJECTS) $(EXEC)

.PHONY: all clean

