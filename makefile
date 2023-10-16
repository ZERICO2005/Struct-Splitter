# Compiler
CC = gcc
# Directories
SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin
# Output
EXE = ./bin/Split.exe
# FLags
CFLAGS = -Wall

# Sources
SRC_FILES = ./src/main.c
HDR_FILES = ./src/Split_Def.h ./src/input.h

OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRC_FILES))

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ): $(SRC_FILES) $(HDR_FILES)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(BIN_DIR)/*.exe $(OBJ_DIR)/*.o

.PHONY: all clean