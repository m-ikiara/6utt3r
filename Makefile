# Let's build 6uττεrδ09! \('O')/
#
# This builds our Game executable. Feel free to comment
# out or uncomment what you need.
#
# Note: Make sure you've added g++ to mingw64 for ease
# of compilation and linking.

# Get all the files required for compilation
SRCS := $(wildcard ./src/*.cpp ./src/ECS/*.cpp ./*.cpp)
OBJS := $(SRCS:.cpp=.o)

# Specify compiler and the various flags
CXX := g++ -Wall -Werror -Wextra -pedantic -std=c++17

# Specify the path to the libraries and header files
HEADER_PATH := src/include
LIB_PATH := src/lib

# Linker flags
# Linux
LINUX_FLAGS := $(shell sdl2-config --cflags --libs)
# Windows
WINDOWS_FLAGS := -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lLerc -ljxl -ljxl_threads -w -W -isystem windows

# Name of executable
TARGET := 6utt3rd09

# Compile executable
all: $(TARGET)

# For Linux
$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(LINUX_FLAGS)

# For Windows
windows: $(OBJS)
	$(CXX) -I$(HEADER_PATH) -L$(LIB_PATH) -o $(TARGET).exe $(OBJS) $(WINDOWS_FLAGS)

# Clean-up
clean:
	rm $(OBJS) $(TARGET) $(TARGET).exe

.DEFAULT_GOAL := windows

test:
	echo "Hello, World!"

.PHONY: clean all test
