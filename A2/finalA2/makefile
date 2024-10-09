# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -std=c99 -pedantic

# Target executable for question 2
TARGET = q2

# Source files for question 2
SRC = q2.c q2_functions.c

# Header files
HEADERS = q2.h

# All is the default target that builds the project
all: $(TARGET)

# Compile q2
$(TARGET): $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean up the compiled files
clean:
	rm -f $(TARGET)
