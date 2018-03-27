all: tests

tests: simple compcertsfi

simple:
	$(MAKE) -C simple_tests

compcertsfi:
	$(MAKE) -C compcertsfi_tests

clean:
	$(MAKE) -C simple_tests clean
	$(MAKE) -C compcertsfi_tests clean
