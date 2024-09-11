# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -g -Wall -std=c++17

# Ouput file
TARGET = myshell

# Source files
SOURCES = *.cpp

# Object files
OBJECTS = $(SOURCES:.cpp = .o)

# Compile rule (make)
all: $(TARGET)

# Compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link object files and make binary
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Clean rule
clean:
	rm -f *.o $(TARGET)