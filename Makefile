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
LIB_PATH := assets/lib
HEADER_PATH := assets/incl

# Linker flags
# Linux
LINUX_FLAGS := -I$(HEADER_PATH) -L$(LIB_PATH) -lSDL2 -lSDL2main -lSDL2_image
# Windows
WINDOWS_FLAGS := $(LINUX_FLAGS) -lmingw32 -w -W -isystem windows

# Name of executable
TARGET := 6utt3rd09

# Compile executable
all: $(TARGET)

# For Linux
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) $(LINUX_FLAGS) -o $(TARGET)

# For Windows
windows: $(OBJS)
	$(CXX) $(OBJS) $(CFLAGS) $(WINDOWS_FLAGS) -o $(TARGET).exe

# Clean-up
clean:
	rm $(OBJS) $(TARGET) $(TARGET).exe

.DEFAULT_GOAL := windows

.PHONY: clean
