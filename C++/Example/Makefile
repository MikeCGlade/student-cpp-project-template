CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20 -Isrc
TARGET = app.exe
BUILD_DIR = build

SRCS = main.cpp $(wildcard src/*.cpp)

# Convert:
# main.cpp      -> build/main.o
# src/foo.cpp   -> build/foo.o
OBJS = $(BUILD_DIR)/main.o \
       $(patsubst src/%.cpp,$(BUILD_DIR)/%.o,$(wildcard src/*.cpp))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Ensure build directory exists
$(BUILD_DIR):
	if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)

# main.cpp -> build/main.o
$(BUILD_DIR)/main.o: main.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# src/foo.cpp -> build/foo.o
$(BUILD_DIR)/%.o: src/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# phony prevents a file named clean from confusing make
.PHONY : clean
clean:
	del /Q $(BUILD_DIR)\*.o $(TARGET)

