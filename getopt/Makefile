BIN := getopt
SRC := $(BIN).c
CY := '\e[33m'
CE := '\e[0m'

all:
	@echo 'usage:'
	@echo '  make build'
	@echo '  make run'
	@echo '  make clean'

build: $(BIN)

$(BIN): $(SRC)
	$(CC) $^ -o $@

run:
	@echo -e $(CY)'./$(BIN) -a -b ball -c cat'$(CE)
	@./$(BIN) -a -b ball -c cat
	@echo -e $(CY)'./$(BIN) -a -b ball -c'$(CE)
	@./$(BIN) -a -b ball -c
	@echo -e $(CY)'./$(BIN) -a x y z -b ball'$(CE)
	@./$(BIN) -a x y z -b ball

clean:
	-rm $(BIN)
