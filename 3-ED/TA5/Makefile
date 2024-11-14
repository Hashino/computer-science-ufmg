.DEFAULT_GOAL := all
SHELL := /bin/bash

TARGET := matop

BIN := bin
SRC := src
OBJ := obj

# directory for test results
RES := res

EXE = $(BIN)/$(TARGET)

# lists all c files in SRC directory
SOURCES := $(wildcard $(SRC)/*.c)
# lists all object files in OBJ directory
OBJECTS := $(patsubst $(SRC)%,$(OBJ)%, $(patsubst %.c,%.o,$(SOURCES)))

INCLUDE := -I.
# needed for memlog
LIBS := -lm

# -pg needed for gprof
FLAGS := -g -Wall

CC := gcc

all: $(OBJECTS)
	@$(CC) $(FLAGS) $(INCLUDE) $(OBJECTS) $(LIBS) -o $(EXE) 

%.o: ../src/%.c
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJ)/*
	rm -rf $(BIN)/*
	rm -rf $(RES)/*

SIZE:= 500

cachegrind: all
	valgrind --tool=cachegrind --cache-sim=yes --cachegrind-out-file=$(RES)/cachegrind.out $(EXE) -s -x $(SIZE) -y $(SIZE) 
	cg_annotate $(RES)/cachegrind.out > $(RES)/soma.cachegrind.annotate
	valgrind --tool=cachegrind --cache-sim=yes --cachegrind-out-file=$(RES)/cachegrind.out $(EXE) -m -x $(SIZE) -y $(SIZE)
	cg_annotate $(RES)/cachegrind.out > $(RES)/mult.cachegrind.annotate
	valgrind --tool=cachegrind --cache-sim=yes --cachegrind-out-file=$(RES)/cachegrind.out $(EXE) -t -x $(SIZE) -y $(SIZE) 
	cg_annotate $(RES)/cachegrind.out > $(RES)/tran.cachegrind.annotate
	rm $(RES)/cachegrind.out

callgrind: all
	valgrind --tool=callgrind --cache-sim=yes --callgrind-out-file=$(RES)/callgrind.out $(EXE) -s -x $(SIZE) -y $(SIZE) 
	callgrind_annotate $(RES)/callgrind.out > $(RES)/soma.callgrind.annotate
	valgrind --tool=callgrind --cache-sim=yes --callgrind-out-file=$(RES)/callgrind.out $(EXE) -m -x $(SIZE) -y $(SIZE)
	callgrind_annotate $(RES)/callgrind.out > $(RES)/mult.callgrind.annotate
	valgrind --tool=callgrind --cache-sim=yes --callgrind-out-file=$(RES)/callgrind.out $(EXE) -t -x $(SIZE) -y $(SIZE) 
	callgrind_annotate $(RES)/callgrind.out > $(RES)/tran.callgrind.annotate
	rm $(RES)/callgrind.out

tests: mem perf gprof

mem: all
	$(EXE) -s -x 4 -y 5 -p $(RES)/somalog.out 
	$(EXE) -m -x 5 -y 5 -p $(RES)/multlog.out 
	$(EXE) -t -x 5 -y 4 -p $(RES)/transplog.out 
	$(EXE) -c $(RES)/somalog.txt -p $(RES)/somalog.out -l -x 5 -y 4
	$(EXE) -c $(RES)/multlog.txt -p $(RES)/multlog.out -l -x 5 -y 4
	$(EXE) -c $(RES)/transplog.txt -p $(RES)/transplog.out -l -x 5 -y 4

perf: all
	$(EXE) -s -x 100 -y 100 -p $(RES)/soma100.out 
	$(EXE) -m -x 100 -y 100 -p $(RES)/mult100.out 
	$(EXE) -t -x 100 -y 100 -p $(RES)/transp100.out 
	$(EXE) -s -x 200 -y 200 -p $(RES)/soma200.out 
	$(EXE) -m -x 200 -y 200 -p $(RES)/mult200.out 
	$(EXE) -t -x 200 -y 200 -p $(RES)/transp200.out 
	$(EXE) -s -x 300 -y 300 -p $(RES)/soma300.out 
	$(EXE) -m -x 300 -y 300 -p $(RES)/mult300.out 
	$(EXE) -t -x 300 -y 300 -p $(RES)/transp300.out 
	$(EXE) -s -x 400 -y 400 -p $(RES)/soma400.out 
	$(EXE) -m -x 400 -y 400 -p $(RES)/mult400.out 
	$(EXE) -t -x 400 -y 400 -p $(RES)/transp400.out 
	$(EXE) -s -x 500 -y 500 -p $(RES)/soma500.out 
	$(EXE) -m -x 500 -y 500 -p $(RES)/mult500.out 
	$(EXE) -t -x 500 -y 500 -p $(RES)/transp500.out 

gprof: all
	$(EXE) -s -x 500 -y 500 -p $(RES)/soma500gprof.out 
	gprof $(EXE) gmon.out > $(RES)/soma500gprof.txt
	$(EXE) -m -x 500 -y 500 -p $(RES)/mult500gprof.out 
	gprof $(EXE) gmon.out > $(RES)/mult500gprof.txt
	$(EXE) -t -x 500 -y 500 -p $(RES)/transp500gprof.out 
	gprof $(EXE) gmon.out > $(RES)/transp500gprof.txt
	rm gmon.out
