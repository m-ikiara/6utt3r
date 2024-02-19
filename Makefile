##################################6utt3r#####################################
#
#	TODO: So much needs to go in this Makefile! Here's a list:
#		1. Implement cross-compilation with clang, gcc and g++
#		2. Implement the Linux recipe
#		3. Use sdl2-config over explicit declaration of CXXFLAGS and LibFLAGS
#		4. Toggle JIT Debugging on or off
#		5. Handle Dev mode!
#
#############################################################################

# Compiler settings
CC := gcc
CXX := g++
CLANGXX := clang++

# Flags and globals
IncDIR := ./include
LibDIR := ./lib
ObjDIR := ./obj
CXXFLAGS := -g -O3 -Wall -Wextra -pedantic -mwindows
LibFLAGS := -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -L$(addprefix $(LibDIR)/,SDL2/lib)
IncFLAGS := $(addprefix -I,$(IncDIR))
# NixFLAGS := $(shell ./lib/sdl2-config --cflags --libs) $(addprefix -I,$(IncDIR))

# Call it whatever you like
NAME := 6utt3r

# Separate source files
SRC := $(wildcard ./src/*.c)
CPPSRC := $(wildcard ./src/*.cpp)
CXXSRC := $(wildcard ./src/*.cxx)
OBJ := $(addprefix $(ObjDIR)/, $(notdir $(SRC:.c=.o) $(CPPSRC:.cpp=.o) $(CXXSRC:.cxx=.o)))

# The Meat and Potatoes...
.PHONY: all clean fclean strip

all: target

target: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(LibFLAGS) -o $(NAME)

# target linux: $(SRC)
# 	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME) $(NixFLAGS)

$(ObjDIR)/%.o: $(SRC) $(CPPSRC) $(CXXSRC)
	$(CXX) $(CXXFLAGS) $(IncFLAGS) -c $< -o $@

clean:
	rm -f target $(OBJ)

fclean: clean
	rm -f $(NAME)

strip:
	strip --strip-all $(NAME)

#############################################################################
# @name 6utt3r
# @version 0.1.3
# @author Brian M'Ikiara
# @copyright 2024
#
# @description This defines the recipes involved in compiling, linking and
# building 6utt3r to an executable.
#############################################################################
