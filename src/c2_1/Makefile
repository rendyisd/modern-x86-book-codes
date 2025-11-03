CC :=
ASM := nasm
LD := ld

ifeq ($(CC),)
	CC := gcc
endif


SRC_C := c2_1_misc
SRC_S := c2_1_fasm

OBJ_DIR := obj/
ROOT_BIN_DIR = ../../bin

OBJ_C := $(patsubst %, $(OBJ_DIR)/%.o, $(SRC_C))
OBJ_S := $(patsubst %, $(OBJ_DIR)/%.o, $(SRC_S))

TARGET := $(ROOT_BIN_DIR)/c2_1

all: $(TARGET)

$(TARGET): $(OBJ_C) $(OBJ_S)
	$(CC) $^ -o $@

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) -c $< -o $@

$(OBJ_DIR)/%.o: %.s | $(OBJ_DIR)
	$(ASM) -f elf64 $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

.PHONY: all clean
