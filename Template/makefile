# ======================
# Compiler and flags
# ======================
CC = g++
CXXFLAGS = -Wall -Wextra -std=c++20 -Iinclude -MMD -MP
AR = ar
ARFLAGS = rcs

# ======================
# OS detection
# ======================
ifeq ($(OS),Windows_NT)
    EXE_EXT = .exe
    RM = rmdir /S /Q
    RM_FILE = del /Q
else
    EXE_EXT =
    RM = rm -rf
    RM_FILE = rm -f
endif

# ======================
# Directories
# ======================
SRCDIR = src
INCDIR = include
BINDIR = bin
LIBDIR = lib

# ======================
# Output files
# ======================
EXENAME = app$(EXE_EXT)
LIBNAME = libapp.a

# ======================
# Source and object files
# ======================
SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(patsubst $(SRCDIR)/%.cpp,$(BINDIR)/%.o,$(SRC))

# ======================
# Libraries to link against
# ======================
LIBS := $(wildcard $(LIBDIR)/*.a)
LIBFLAGS := $(patsubst $(LIBDIR)/lib%.a,-l%,$(LIBS))
LDFLAGS := -L$(LIBDIR) $(LIBFLAGS)

# ======================
# Default target: build library and executable
# ======================
all: $(LIBNAME) $(EXENAME)
	@echo "Finished building library and executable"

# ======================
# Library target
# ======================
library: $(LIBNAME)

$(LIBNAME): $(OBJ) | $(BINDIR) $(LIBDIR)
	$(AR) $(ARFLAGS) $@ $^

# ======================
# Executable target
# ======================
exe: $(EXENAME)

$(EXENAME): $(OBJ) | $(BINDIR)
ifneq ("$(wildcard $(SRCDIR)/main.cpp)","")
	$(CC) $(CXXFLAGS) $^ $(LDFLAGS) -o $@
else
	@echo "No main.cpp found, skipping executable build"
endif

# ======================
# Compile .cpp -> .o
# ======================
$(BINDIR)/%.o: $(SRCDIR)/%.cpp | $(BINDIR)
	$(CC) $(CXXFLAGS) -c $< -o $@

# ======================
# Ensure directories exist (cross-platform)
# ======================
ifeq ($(OS),Windows_NT)

$(BINDIR):
	@if not exist "$(BINDIR)" mkdir "$(BINDIR)"

$(LIBDIR):
	@if not exist "$(LIBDIR)" mkdir "$(LIBDIR)"

else

$(BINDIR):
	mkdir -p $(BINDIR)

$(LIBDIR):
	mkdir -p $(LIBDIR)

endif

# ======================
# Include header dependencies
# ======================
-include $(OBJ:.o=.d)

# ======================
# Clean up
# ======================
clean:
	$(RM) $(BINDIR)
	$(RM_FILE) $(EXENAME) $(LIBNAME)

# ======================
# Phony targets
# ======================
.PHONY: all exe library clean
