.DEFAULT_GOAL := all

TARGET := matop
SOURCES := $(wildcard src/*.c src/*.cpp)
OBJECTS := $(patsubst src%,obj%, $(patsubst %.c,%.o, $(patsubst %.cpp,%.o,$(SOURCES))))

INCLUDE := -I.
LIBPATH :=
LIBS :=

FLAGS := 
CCFLAGS := $(FLAGS) -std=c99
CXXFLAGS := $(FLAGS)

CC := gcc
Cxx := g++

all: $(OBJECTS)
	$(CC) $(CCFLAGS) $(INCLUDE) $(OBJECTS) -o bin/$(TARGET) $(LIBPATH) $(LIBS)

%.o: ../src/%.c
	$(CC) $(CCFLAGS) $(INCLUDE) -c $< -o $@

%.o: ../src/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

run: all
	./bin/matop -s -x 5 -y 5
	./bin/matop -m -x 5 -y 5
	./bin/matop -t -x 5 -y 5

clean:
	rm -rf obj/*
	rm -rf bin/*
