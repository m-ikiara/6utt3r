# Let's build 6uττεrδ09! \('O')/
#
# This builds our Game executable. Feel free to comment
# out or uncomment what you need.
#
# Note: Make sure you've added g++ to mingw64 for ease
# of compilation and linking.

# Get all the files required for compilation
OBJS = $(wildcard ./src/*.cpp)

# Specify compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Werror -Wextra -pedantic

# Specify the path to the libraries
# For Linux
# LIBSDL2_PATH = /usr/lib
LIBSDL2_PATH = /usr/lib/x86_64-linux-gnu

# For Windows
# (using mingw64):
# LIBSDL2_PATH = C:\\mingw64\\lib
# (using msys64):
#LIBSDL2_PATH = C:\\msys64\\mingw64\\lib

# Linker flags
LDFLAGS = -L$(LIBSDL2_PATH) -lSDL2 -lSDL2_image

# Name of executable
TARGET = 6uττεrδ09

# Compile executable
all: $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) $(LDFLAGS) -o $(TARGET)
