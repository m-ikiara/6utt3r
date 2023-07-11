# Let's build 6utt3r09! \('O')/
#
# This builds our Game executable. Feel free to comment
# out or uncomment what you need.
#
# Note: Make sure you've added g++ to mingw64 for ease
# of compilation and linking.

# Get all the files required for compilation
SRCS := src/AssetManager.cpp src/Butt3r.cpp src/Collision.cpp src/Map.cpp src/TextureManager.cpp src/Vector2D.cpp src/ECS/ECS.cpp
OBJS := $(SRCS:.cpp=.o)

# Specify compiler and the various flags
CXX := g++ -Wall -Werror -Wextra -pedantic -std=c++17

# Specify the path to the libraries and header files
HEADER_PATH := src/include
LIB_PATH := src/lib

# Linker flags
# Windows
WINDOWS_FLAGS := -lmingw32 -lSDL2 -lSDL2_image -lSDL2_ttf -lLerc -ljxl -ljxl_threads -w -W -isystem windows

# Name of executable
TARGET := 6utt3rd09

# Compile executable
windows: $(OBJS)
	$(CXX) $(OBJS) -I$(HEADER_PATH) -L$(LIB_PATH) $(WINDOWS_FLAGS) -o $(TARGET).exe

# Wipe down
clean:
	rm $(OBJS)
	rm $(TARGET)
	rm $(TARGET).exe

.PHONY: clean windows