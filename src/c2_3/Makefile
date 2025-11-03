CC :=
ASM := nasm
LD := ld

ifeq ($(CC),)
	CC := gcc
endif

OBJ_DIR := obj
ROOT_BIN_DIR = ../../bin

SRC_C := c2_3_misc
SRC_S := c2_3_fasm
TARGET := $(ROOT_BIN_DIR)/c2_3

OBJ_C := $(patsubst %, $(OBJ_DIR)/%.o, $(SRC_C))
OBJ_S := $(patsubst %, $(OBJ_DIR)/%.o, $(SRC_S))


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
