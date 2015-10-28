CY := '\e[33m'
CB := '\e[34m'
CP := '\e[35m'
CE := '\e[0m'

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
	@echo -e $(CB)'ref: http://www.gnu.org/software/make/manual/make.html'$(CE)

prerequest1:
prerequest2:
prerequest3:
