# Compiler settings
CXX := g++
CLANGXX := clang++

# Flags and globals
IncDIR := ./src/include
LibDIR := ./src/lib
ObjDIR := ./src/obj
CXXFLAGS := -O3 -Wall -Wextra -pedantic -mwindows
LibFLAGS := -lmingw32 -lSDL2main -lSDL2 -L$(addprefix $(LibDIR)/,SDL2/lib)
IncFLAGS := $(addprefix -I,$(IncDIR)) # Include paths

# Call it whatever you like
NAME := 6utt3r

# Separate source files
SRC := $(wildcard ./src/*.cpp) # All .cpp files in ./src
OBJ := $(addprefix $(ObjDIR)/,$(notdir $(SRC:.cpp=.o))) # Object files

.PHONY: all target clean oclean fclean

all: target

target: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(LibFLAGS) -o $(NAME)

$(ObjDIR)/%.o: ./src/%.cpp
	$(CXX) $(CXXFLAGS) $(IncFLAGS) -c $< -o $@

clean:
	rm -f target $(OBJ)

oclean: clean

fclean: clean
	rm -f $(NAME)
