
.DEFAULT_GOAL := all

TARGET := pa1.out
SOURCES := $(wildcard src/*.c src/*.cpp)
OBJECTS := $(patsubst src%,obj%, $(patsubst %.c,%.o, $(patsubst %.cpp,%.o,$(SOURCES))))

INCLUDE := -I.
LIBPATH :=
LIBS :=

FLAGS := -g
CCFLAGS := $(FLAGS)
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
	./bin/$(TARGET) -z 81 -s 17 -a q3i

clean:
	rm -rf obj/*
	rm -rf bin/*
