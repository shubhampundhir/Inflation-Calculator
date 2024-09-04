# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -std=c++11 -Wall

# Source Files
SRCS = Assignment1_Q2.cpp

# Object Files
OBJS = $(SRCS:.cpp=.o)

# Output Binaries
DEBUG_BIN = tax_calculator_debug
OPT_BIN = tax_calculator_optimized

# Default Target (All)
all: debug optimized

# Debug Build
debug: CXXFLAGS += -g
debug: $(DEBUG_BIN)

$(DEBUG_BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Optimized Build
optimized: CXXFLAGS += -O2
optimized: $(OPT_BIN)

$(OPT_BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Clean Up
clean:
	rm -f $(OBJS) $(DEBUG_BIN) $(OPT_BIN)
