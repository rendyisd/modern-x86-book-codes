SUBDIR := src/c2_1
ROOT_BIN := bin/

all: $(SUBDIR) | $(ROOT_BIN)
	make -C $<

$(ROOT_BIN):
	mkdir -p $(ROOT_BIN)

clean-all: $(SUBDIR)
	make -C $< clean

.PHONY: all clean-all
