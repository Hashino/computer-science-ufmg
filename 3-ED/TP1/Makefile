.DEFAULT_GOAL := all

TARGET := order

SRC := src
BIN := bin
OBJ := obj

# create directories if needed
$(shell mkdir -p $(BIN))
$(shell mkdir -p $(OBJ))

EXE = $(BIN)/$(TARGET)

# lists all c files in SRC directory
SOURCES := $(wildcard $(SRC)/*.c)
# lists all object files in OBJ directory
OBJECTS := $(patsubst $(SRC)%,$(OBJ)%, $(patsubst %.c,%.o,$(SOURCES)))

INCLUDE := -I.
FLAGS := -g -lm 
# -Wall
# -fsso-struct=big-endian

CC := gcc

### TARGETS ###

TEST_FILE := /home/hashino/Documents/cs-ufmg/3-ED/TP1/cad/test.xcsv
ALG := 'rn'

run: all
	# @$(EXE) -d -f $(REAL_FILE) -a $(ALG) -o a
	@$(EXE) -d -f $(TEST_FILE) -a $(ALG) -o d

REAL_FILE := /home/hashino/Documents/cs-ufmg/3-ED/TP1/cad/cad.r1000.p1000.xcsv
real: all
	@$(EXE) -d -f $(REAL_FILE) -a $(ALG) -o a > out


VALGRIND_ARGS := --leak-check=full --show-leak-kinds=all --log-file=res	

tests: all
	valgrind $(VALGRIND_ARGS) $(EXE) -d -f $(REAL_FILE) -a $(ALG)

### general targets

all: $(OBJECTS)
	@$(CC) $(FLAGS) $(INCLUDE) $(OBJECTS) $(LIBS) -o $(EXE) 

%.o: ../$(SRC)/%.c
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rfv $(OBJ)/*
	@rm -rfv $(BIN)/*
