# Compiler settings
CC := gcc
CXX := g++
CLANGXX := clang++

# Flags and globals
IncDIR := ./include
LibDIR := ./lib
ObjDIR := ./obj
CXXFLAGS := -O3 -Wall -Wextra -pedantic -mwindows
LibFLAGS := -lmingw32 -lSDL2main -lSDL2 -L$(addprefix $(LibDIR)/,SDL2/lib)
IncFLAGS := $(addprefix -I,$(IncDIR))

# Call it whatever you like
NAME := 6utt3r

# Separate source files
SRC := $(wildcard ./src/*.c)
OBJ := $(addprefix $(ObjDIR)/, $(notdir $(SRC:.c=.o)))

.PHONY: all clean oclean fclean

all: target

target: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(LibFLAGS) -o $(NAME)

$(ObjDIR)/%.o: ./src/%.c
	$(CXX) $(CXXFLAGS) $(IncFLAGS) -c $< -o $@

clean:
	rm -f target $(OBJ)

oclean: clean

fclean: clean
	rm -f $(NAME)
