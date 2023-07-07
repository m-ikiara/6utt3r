# Let's build 6uττεrδ09! \('O')/
#
# This builds our Game executable. Feel free to comment
# out or uncomment what you need.
#
# Note: Make sure you've added g++ to mingw64 for ease
# of compilation and linking.

# Get all the files required for compilation
SRCS := $(wildcard ./src/*.cpp ./src/ECS/*.cpp)
OBJS := $(SRCS:.cpp=.o)

# Specify compiler and the various flags
CXX := g++ -Wall -Werror -Wextra -pedantic

# Specify the path to the libraries and header files
SDL2_PATH := SDL2/lib/x64
SDL2_IMAGE_PATH := SDL2/lib/x64
HEADER_PATH := SDL2/include
# Linker flags
# Linux
LINUX_FLAGS := $(shell sdl2-config --cflags --libs)
# Windows
WINDOWS_FLAGS := -I$(HEADER_PATH) -L$(SDL2_PATH) -lmingw32 -lSDL2main -lSDL2 -mwindows -L$(SDL2_IMAGE_PATH) -LSDL2_image -ljxl -ljpeg -lSDL2_ttf -lpng16 -lzlib1 -lfreetype -w -W -isystem windows 

# Name of executable
TARGET := 6utt3rd09

# Compile executable
all: $(TARGET)

# For Linux
$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(LINUX_FLAGS)

# For Windows
windows: $(OBJS)
	$(CXX) $(OBJS) $(WINDOWS_FLAGS) -o $(TARGET).exe

# Clean-up
clean:
	rm $(OBJS) $(TARGET) $(TARGET).exe

.DEFAULT_GOAL := windows

test:
	echo "Hello, World!"

.PHONY: clean all test
