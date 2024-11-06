.DEFAULT_GOAL := all
SHELL := /bin/bash

TARGET := pa3
BINARY := bin

SOURCES := $(wildcard src/*.c src/*.cpp)
OBJECTS := $(patsubst src%,obj%, $(patsubst %.c,%.o, $(patsubst %.cpp,%.o,$(SOURCES))))

INCLUDE := -I.
LIBPATH :=
LIBS :=

FLAGS := -pg
CCFLAGS := $(FLAGS)
CXXFLAGS := $(FLAGS)

CC := gcc
Cxx := g++

all: $(OBJECTS)
	@$(CC) $(CCFLAGS) $(INCLUDE) $(OBJECTS) -o $(BINARY)/$(TARGET) $(LIBPATH) $(LIBS)

%.o: ../src/%.c
	@$(CC) $(CCFLAGS) $(INCLUDE) -c $< -o $@

%.o: ../src/%.cpp
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

time: all
	@./time_algs.sh

gprof: all
	@$(BINARY)/$(TARGET) -a fib -r -n 40
	@gprof $(BINARY)/$(TARGET) > profiling/fib_r.gprof
	@$(BINARY)/$(TARGET) -a fib -i -n 1500
	@gprof $(BINARY)/$(TARGET) > profiling/fib_i.gprof
	@$(BINARY)/$(TARGET) -a fac -r -n 1500
	@gprof $(BINARY)/$(TARGET) > profiling/fac_r.gprof
	@$(BINARY)/$(TARGET) -a fac -i -n 1500
	@gprof $(BINARY)/$(TARGET) > profiling/fac_i.gprof

clean:
	rm -rf obj/*
	rm -rf bin/*
