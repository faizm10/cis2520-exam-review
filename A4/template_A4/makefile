# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -std=c99 -pedantic

# Target executables for question 1 
TARGET_Q1 = a4

# Source files for question 1
SRC_Q1 = main.c graph_functions.c

# Header files for both questions
HEADERS_Q1 = graph.h

# Default target to build both projects
all: $(TARGET_Q1) 

# Compile question 1
$(TARGET_Q1): $(SRC_Q1) $(HEADERS_Q1)
	$(CC) $(CFLAGS) -o $(TARGET_Q1) $(SRC_Q1)

# Clean up the compiled files
clean:
	rm -f $(TARGET_Q1) $(TARGET_Q2)ß
