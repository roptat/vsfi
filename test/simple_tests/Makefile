VSFI = ../../src/vsfi
# Expected failure
FAILTESTS=overflow controlflow bad reg bts movxor
# Expected success
PASSTESTS=test pointer nooverflow

CC=gcc

NOWARN=-Wno-incompatible-pointer-types \
 -Wno-int-conversion \
 -Wno-aggressive-loop-optimizations

TESTS=$(PASSTESTS) $(FAILTESTS)

RESET=\e[0m
RED=\e[31m
YELLOW=\e[33m
GREEN=\e[32m
BLUE=\e[34m

tests: $(addsuffix .o,$(TESTS))
	@echo
	@failed=""; \
	for t in $^; do \
		test=$$(echo $$t | sed 's|.o$$||') ;\
		if ($(VSFI) $$t --debug > $${test}.test); then \
			if (echo $(FAILTESTS) | grep "$$test[ $$]") >/dev/null 2>&1; then \
				printf "  $(YELLOW)XPASS$(RESET) $$test\n" ;\
			else \
				printf "  $(GREEN)PASS$(RESET)  $$test\n" ;\
			fi ;\
		else \
			if (echo $(FAILTESTS) | grep $$test) >/dev/null 2>&1; then \
				printf "  $(BLUE)XFAIL$(RESET) $$test\n" ;\
			else \
				printf "  $(RED)FAIL$(RESET)  $$test\n" ;\
			fi ;\
		fi ;\
	done; \
	echo; \
	echo "Test summary"; \
	echo "============"; \
	number=$$(echo $(TESTS) | sed 's| |\n|g' | wc -l); \
	numberf=$$(echo $(FAILTESTS) | sed 's| |\n|g' | wc -l); \
	numbers=$$(echo $(PASSTESTS) | sed 's| |\n|g' | wc -l); \
	printf "Total tests: $${number}.\n"; \
	printf "Expecting $${numbers} accepted programs and $${numberf} rejected programs.\n"; \
	printf "Failed tests: $${failed}.\n"; \
	[ -z "$${failed}" ]

%.o: %.c Makefile
	$(CC) -m32 -O1 -fstrict-aliasing $(NOWARN) -fno-builtin -c $< -o $@

$(TESTS): $(addsuffix .o,$(TESTS))
	$(CC) -m32 -O1 -fstrict-aliasing $(NOWARN) -fno-builtin $@.o -o $@

clean:
	rm -f *.test
	rm -f *.o
	rm -f $(TESTS)
