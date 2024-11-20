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

run: all
	@$(EXE) -f /home/hashino/Documents/cs-ufmg/3-ED/TP1/cad/test.xcsv -d

tests: all
	valgrind --leak-check=full $(EXE) -d -f /home/hashino/Documents/cs-ufmg/3-ED/TP1/cad/test.xcsv

### general targets

all: $(OBJECTS)
	@$(CC) $(FLAGS) $(INCLUDE) $(OBJECTS) $(LIBS) -o $(EXE) 

%.o: ../$(SRC)/%.c
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rfv $(OBJ)/*
	@rm -rfv $(BIN)/*
