CXX = g++
CXXFLAGS = -Wall -std=c++17 -O2 -fopenmp

SOURCES = init.cpp
OBJECTS = $(SOURCES:.cpp=.o)

TARGET = libinit.a

all: $(TARGET)

$(TARGET): $(OBJECTS)
	ar rcs $@ $^
	ranlib $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)