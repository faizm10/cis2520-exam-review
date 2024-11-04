# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -std=c99 -pedantic

# Target executables for both question 1 and question 2
TARGET_Q1 = a3q1
TARGET_Q2 = a3q2

# Source files for question 1
SRC_Q1 = a3q1_main.c a3q1_functions.c

# Source files for question 2
SRC_Q2 = a3q2_main.c a3q2_functions.c

# Header files for both questions
HEADERS_Q1 = a3q1_header.h
HEADERS_Q2 = a3q2_header.h

# All is the default target that builds both projects
all: $(TARGET_Q1) $(TARGET_Q2)

# Compile q1
$(TARGET_Q1): $(SRC_Q1) $(HEADERS_Q1)
	$(CC) $(CFLAGS) -o $(TARGET_Q1) $(SRC_Q1)

# Compile q2
$(TARGET_Q2): $(SRC_Q2) $(HEADERS_Q2)
	$(CC) $(CFLAGS) -o $(TARGET_Q2) $(SRC_Q2)

# Clean up the compiled files
clean:
	rm -f $(TARGET_Q1) $(TARGET_Q2)
