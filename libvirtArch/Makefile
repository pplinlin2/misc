BIN := libvirtArch
SRC := $(BIN).c

$(BIN): $(SRC)
	$(CC) $^ -o $@
	./$(BIN)

clean:
	-rm $(BIN)
