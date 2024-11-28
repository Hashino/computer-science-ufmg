.DEFAULT_GOAL := all

TARGET := tp1.out

SRC := src
BIN := bin
OBJ := obj

# create directories if needed
$(shell mkdir -p $(BIN))
$(shell mkdir -p $(OBJ))

EXE = $(BIN)/$(TARGET)

# lists all c files in SRC directory
SOURCES := $(wildcard $(SRC)**/*.c)
# lists all object files in OBJ directory
OBJECTS := $(patsubst $(SRC)%,$(OBJ)%, $(patsubst %.c,%.o,$(SOURCES)))

INCLUDE := -I.
FLAGS := -g -lm -Wall

CC := gcc

### TARGETS ###

TEST_FILE := ./cad/test.xcsv
MINI_FILE := ./cad/cad.r100.p100.xcsv
REAL_FILE := ./cad/cad.r1000.p1000.xcsv
BIG_FILE := ./cad/cad.r5000.p5000.xcsv

ALG := 'sc'

run: all
	$(EXE) -d -f $(TEST_FILE) -a $(ALG) -o a

memlog: all
	$(EXE) -d -f $(TEST_FILE) -a $(ALG) -o a -m './memlog'

VALGRIND_ARGS := --leak-check=full --show-leak-kinds=all --log-file=res	

valgrind: all
	valgrind $(VALGRIND_ARGS) $(EXE) -f $(BIG_FILE) -a $(ALG)

# TODO: make automatic tests

### general targets

all: $(OBJECTS)
	@$(CC) $(FLAGS) $(INCLUDE) $(OBJECTS) $(LIBS) -o $(EXE) 

%.o: ../$(SRC)/%.c
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rfv $(OBJ)/*
	@rm -rfv $(BIN)/*
	@rm -fv memlog
	@rm -fv res
	@rm -fv out
