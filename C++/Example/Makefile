CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20 -Isrc -I../include -MMD -MP
TARGET = app.exe
BUILD_DIR = build

SRCS = main.cpp $(wildcard src/*.cpp)

# Object files
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

# src/*.cpp -> build/*.o
$(BUILD_DIR)/%.o: src/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Include dependencies (headers in ../include or src/)
-include $(OBJS:.o=.d)

.PHONY: clean
clean:
	del /Q $(BUILD_DIR)\*.o $(BUILD_DIR)\*.d $(TARGET)
