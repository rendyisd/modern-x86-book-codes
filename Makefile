SRC_DIR := src
BIN := c2_1 c2_2 c2_3 c2_4 c2_5 \
	   c3_1 c3_2 c3_3

SUBDIR := $(addprefix $(SRC_DIR)/, $(BIN))
ROOT_BIN := bin

all: $(SUBDIR)

$(SUBDIR): $(ROOT_BIN)
	@echo "[ Building $@... ]"
	@make -C $@

$(ROOT_BIN):
	mkdir -p $(ROOT_BIN)

clean:
	@for dir in $(SUBDIR); do \
		echo "[ Cleaning $$dir... ]"; \
		make -C $$dir clean; \
	done
	@echo "[ Cleaning bin ]";
	rm -rf $(ROOT_BIN)

.PHONY: all clean $(SUBDIR)
