# Let's build 6uττεrδ09! \('O')/
#
# This builds our Game executable. Feel free to comment
# out or uncomment what you need.
#
# Note: Make sure you've added g++ to mingw64 for ease
# of compilation and linking.

# Get all the files required for compilation
SRCS := $(wildcard ./src/*.cpp)
OBJS := $(SRCS:.cpp=.o)

# Specify compiler and the various flags
CXX := g++
CXXFLAGS := -Wall -Werror -Wextra -pedantic

# Specify the path to the libraries
# For Linux
# LIBSDL2_PATH = /usr/lib
LIBSDL2_PATH := /usr/lib/x86_64-linux-gnu

# For Windows
# (using mingw64):
# LIBSDL2_PATH = C:\\mingw64\\lib
# (using msys64):
WINDOWS_PATH := C:\msys64\mingw64\lib

# Linker flags
LDFLAGS := -L$(LIBSDL2_PATH) -lSDL2 -lSDL2main -lSDL2_image
WINDOWS_FLAGS := -L$(WINDOWS_PATH) -lmingw32 -lSDL2 -lSDL2main -lSDL2_image -mwindows

# Name of executable
TARGET := 6utt3rd09

# Compile executable
all: $(TARGET)

# For Linux
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) $(LDFLAGS) -o $(TARGET)

# For Windows
windows: $(OBJS)
	$(CXX) $(OBJS) $(CFLAGS) $(WINDOWS_FLAGS) -o $(TARGET).exe

# Clean-up
clean:
	rm -f $(OBJS) $(TARGET) $(TARGET).exe

.DEFAULT_GOAL := windows

.PHONY: clean
