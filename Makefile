CXX = g++
CXXFLAGS = -g -Wall

TARGET = myshell
OBJECTS = myshell.o parse.o param.o

.PHONY: all test clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

myshell.o: myshell.cpp parse.hpp param.hpp
	$(CXX) $(CXXFLAGS) -c myshell.cpp

parse.o: parse.cpp parse.hpp param.hpp
	$(CXX) $(CXXFLAGS) -c parse.cpp

param.o: param.cpp param.hpp
	$(CXX) $(CXXFLAGS) -c param.cpp

test: test_part1

test_part1: test_part1.cpp parse.o param.o
	$(CXX) $(CXXFLAGS) -o test_part1 test_part1.cpp parse.o param.o

clean:
	rm -f $(OBJECTS) $(TARGET) test_part1
