# Get all the files required for compilation
OBJS = $(wildcard ./src/*.c)

# Specify compiler
CC = gcc

# Compiler flags
COMPILER_FLAGS =-Wall -Werror -Wextra -pedantic

# Linker flags
LINKER_FLAGS = -lSDL2 -lSDL_image

# Name of executable
OBJ_NAME = "6uττεrδ09 by iMjN"

# Compile executable
all: $(OBJS)
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(OBJS) -o $(OBJ_NAME)
