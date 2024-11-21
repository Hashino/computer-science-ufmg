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
FLAGS := -g -lm -Wall
# -fsso-struct=big-endian

CC := gcc

### TARGETS ###

TEST_FILE := /home/hashino/Documents/cs-ufmg/3-ED/TP1/cad/test.xcsv
MINI_FILE := /home/hashino/Documents/cs-ufmg/3-ED/TP1/cad/cad.r100.p100.xcsv
REAL_FILE := /home/hashino/Documents/cs-ufmg/3-ED/TP1/cad/cad.r1000.p1000.xcsv

ALG := 'qn'

REAL_FILE0 := /home/hashino/Documents/cs-ufmg/3-ED/TP1/cad/perf_reversed/reverse.1000.xcsv
REAL_FILE1 := /home/hashino/Documents/cs-ufmg/3-ED/TP1/cad/perf_reversed/reverse.2000.xcsv
REAL_FILE2 := /home/hashino/Documents/cs-ufmg/3-ED/TP1/cad/perf_reversed/reverse.3000.xcsv
REAL_FILE3 := /home/hashino/Documents/cs-ufmg/3-ED/TP1/cad/perf_reversed/reverse.4000.xcsv
REAL_FILE4 := /home/hashino/Documents/cs-ufmg/3-ED/TP1/cad/perf_reversed/reverse.5000.xcsv

memlog: all
	$(EXE) -f $(REAL_FILE0) -a $(ALG) -o a
	$(EXE) -f $(REAL_FILE1) -a $(ALG) -o a
	$(EXE) -f $(REAL_FILE2) -a $(ALG) -o a
	$(EXE) -f $(REAL_FILE3) -a $(ALG) -o a
	$(EXE) -f $(REAL_FILE4) -a $(ALG) -o a

run: all
	$(EXE) -f $(MINI_FILE) -a $(ALG) -o a

real: all
	@$(EXE) -d -f $(REAL_FILE) -a $(ALG) -o a > out


VALGRIND_ARGS := --leak-check=full --show-leak-kinds=all --log-file=res	

tests: all
	$(EXE) -f $(REAL_FILE) -a 'qn' -o a
	$(EXE) -f $(REAL_FILE) -a 'qc' -o a
	$(EXE) -f $(REAL_FILE) -a 'bn' -o a
	$(EXE) -f $(REAL_FILE) -a 'bc' -o a
	$(EXE) -f $(REAL_FILE) -a 'rn' -o a
	$(EXE) -f $(REAL_FILE) -a 'rc' -o a

valgrind: all
	valgrind $(VALGRIND_ARGS) $(EXE) -d -f $(REAL_FILE) -a $(ALG)

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
