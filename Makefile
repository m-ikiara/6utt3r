# Compiler settings
CC := gcc
CXX := g++

# Flags and globals
IncDIR := ./include
LibDIR := ./lib
ObjDIR := ./obj
CXXFLAGS := -g -O3 -Wall -Wextra -pedantic -mwindows
LibFLAGS := -lmingw32 -lraylib -L$(addprefix $(LibDIR)/,SDL2/lib)
IncFLAGS := $(addprefix -I,$(IncDIR))

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

$(ObjDIR)/%.o: $(SRC) $(CPPSRC) $(CXXSRC)
	$(CXX) $(CXXFLAGS) $(IncFLAGS) -c $< -o $@

clean:
	rm -f target $(OBJ)

fclean: clean
	rm -f $(NAME)

strip:
	strip --strip-all $(NAME)
