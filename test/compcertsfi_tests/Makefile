PASSTESTS=aes chomp fannkuch fib lists nsieve nsievebits sha1 sha3 qsort
FAILTESTS=almabench binarytrees bisect fft fftsp fftw integr knucleotide \
	mandelbrot nbody perlin siphash24 spectral vmach
TESTS=$(PASSTESTS) $(FAILTESTS)
CCOMP=compcert
CC=gcc

SANDBOX_RANGE=24
SANDBOX_START=0x2000000

DEBUG_ASM=-dasm
DEBUG_CMINOR=-dcminor
CCOMPFLAGS:=$(CCOMPOPTS) -falign-functions 4 -falign-branch-targets 4 -falign-cond-branches 4\
	-dall -fno-mask-load -stdlib ../../runtime\
	    $(DEBUG_ASM) $(DEBUG_CMINOR)
SBCONFIG = -sfi-range $(SANDBOX_RANGE) -sfi-start $(SANDBOX_START)
CFLAGS=-O1 -Wall
SFI_HEADER=sfi.h

RUN_IN_ENV=guix environment --ad-hoc gcc binutils glibc --system=i686-linux --
VSFI=../../src/vsfi

RESET=\e[0m
RED=\e[31m
YELLOW=\e[33m
GREEN=\e[32m
BLUE=\e[34m

tests:
	@if ($(RUN_IN_ENV) $(CCOMP) --version >/dev/null 2>&1); then \
		$(MAKE) real-tests ;\
	else \
		printf "$(BLUE)SKIP ALL$(RESET) compcert tests\n" ;\
	fi

real-tests: $(addsuffix .o,$(TESTS))
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
	done ;\
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

%.o: %.c
	$(RUN_IN_ENV) $(CCOMP) $(CCOMPFLAGS) $(SBCONFIG) -include $(SFI_HEADER) -c $^ -g

clean:
	rm -f *.test *.o
