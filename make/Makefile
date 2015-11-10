CY := '\e[33m'
CB := '\e[34m'
CP := '\e[35m'
CE := '\e[0m'
demarcation := $(CB)'======================='$(CE)

target.c: prerequest1 prerequest2 prerequest3
	@echo -e $(CP)'target.c: prerequest1 prerequest2 prerequest3'$(CE)
	@echo -e $(CY)'$$@: '$(CE)$@
	@echo -e $(CY)'$$*: '$(CE)$*
	@echo -e $(CY)'$$<: '$(CE)$<
	@echo -e $(CY)'$$^: '$(CE)$^
	@echo -ne $(CY)'$$(patsubst prerequest%, prq%, $$^): '$(CE)
	@echo $(patsubst prerequest%, prq%, $^)
	@echo -ne $(CY)'$$(wildcard *.md): '$(CE)
	@echo $(wildcard *.md)
	@LANG=en_US ls -l $(foreach file, $(wildcard *.md), $(shell readlink -f $(file)))
	@echo -ne $(CY)'$$(origin H): '$(CE)
	@echo $(origin H)

exp:
	@echo -e $(demarcation)
	make H=1
	@echo -e $(demarcation)
	export H=1 && make
	@echo -e $(demarcation)

prerequest1:
prerequest2:
prerequest3:
