GITVERSION=0.1

PACKAGES = bitstring.syntax,bitstring
SYNTAX   = camlp4o,bitstring.syntax 

ML=\
utils/exceptions.ml \
data-struct/register.ml \
data-struct/types.ml \
utils/config.ml \
data-struct/data.ml \
data-struct/asm.ml \
data-struct/code.ml \
loader/elf_info.ml \
utils/log.ml \
utils/mapOpt.ml \
domains/vector.ml \
domains/symbdom.ml \
domains/envDom.ml \
disassembly/cfa.ml \
disassembly/decoder.ml \
fixpoint/interpreter.ml \
vsfi_ver.ml \
main.ml

MLI=\
data-struct/code.mli \
data-struct/data.mli \
data-struct/register.mli \
domains/domain.mli \
domains/numericaldomain.mli \
domains/envdomain.mli

LIBDIR=$(DESTDIR)/$(PREFIX)/lib/
BINDIR=$(DESTDIR)/$(PREFIX)/bin/

CAMLLIBDIR:=$(shell ocamlc -where)

CMX = $(ML:.ml=.cmx)
CMI = $(MLI:.mli=.cmi)

DIROPT = -I `ocamlfind query newspeak` -I `ocamlfind query ocamlgraph` \
         -I `ocamlfind query zarith` -I `ocamlfind query bitstring` \
         -I data-struct -I utils -I domains -I loader -I fixpoint \
		 -I disassembly

CAMLC   =ocamlfind ocamlc -g $(DIROPT)
CAMLOPT =ocamlfind ocamlopt -g -w Ael -warn-error +a-7-3-52-50-42 $(DIROPT) \
                   -w -26-27-32-33 -package $(PACKAGES) -syntax $(SYNTAX)
CAMLLEX =ocamlfind ocamllex
CAMLDEP =ocamlfind ocamldep $(DIROPT)
CAMLDOC =ocamlfind ocamldoc $(DIROPT)

LIBX=unix.cmxa graph.cmxa nums.cmxa str.cmxa zarith.cmxa newspeak.cmxa bigarray.cmxa typedC.cmx bitstring.cmxa

ifeq ($(OS),Windows_NT)
    detected_OS := Windows
else
    detected_OS := $(shell uname)
endif

ifeq ($(detected_OS), Windows)
    shared=-ccopt -dynamiclib
    ldconfig=true
    LIBNAME=libvsfi.dll
endif
ifeq ($(detected_OS), Darwin)
    LIBNAME=libvsfi.so
    SHARED=-ccopt -dynamiclib
    LDCONFIG=true
endif
ifeq ($(detected_OS), Linux)
    LIBNAME=libvsfi.so
    SHARED=-output-obj -runtime-variant _pic
    LDCONFIG=ldconfig
endif

CFLAGS=-ccopt -L$(CAMLLIBDIR) -ccopt -L`ocamlfind query newspeak` -ccopt -lasmrun
all: $(LIBNAME) vsfi loader_test

loader_test: $(CMX) loader_test.cmx
	$(CAMLOPT)  $(CFLAGS) -o $@ $(LIBX) $(OCAMLOPT) $+

$(LIBNAME): $(CMX) 
	rm -f vsfi.cmx
	$(CAMLOPT) $(SHARED) $(CFLAGS) -o $(LIBNAME) $(LIBX) $(OCAMLOPT) $+

vsfi: $(CMX) vsfi.cmx
	$(CAMLOPT)  $(CFLAGS) -o vsfi $(LIBX) $(OCAMLOPT) $+

vsfi_ver.ml: vsfi_ver.ml.tmpl
	sed s/XXX/$(GITVERSION)/ vsfi_ver.ml.tmpl > $@

%.cmx: %.ml %.mli
	$(CAMLOPT) -c $(LIBX) $*.ml

%.cmi: %.mli
	$(CAMLOPT) -c $*.mli

%.cmx: %.ml
	$(CAMLOPT) -c $(LIBX) $*.ml

clean:
	-rm -f .depend
	-rm -f `find . -name "*.cm[ix]"`
	-rm -f `find . -name  "*.o"`
	-rm -f `find . -name "*~"`
	-rm -f `find . -name "*.annot"`
	-rm -f `find . -name "*.cmt"`
	-rm -f `find . -name "*.cmxa"`
	-rm -f `find . -name "*.a"`
	-rm -f ocamldoc.sty ocamldoc.out
	-rm -f disassembly/*.so
	-rm -f $(LIBNAME)
	-rm -f loader_test vsfi
	-rm -f vsfi_ver.ml
	-rm -f frontend/lexer.ml frontend/lexer.mli frontend/parser.ml frontend/parser.mli frontend/*.conflicts frontend/*.automaton
	-rm -f parser.ml parser.mli lexer.ml

install: $(LIBNAME) vsfi
	install $(LIBNAME) $(LIBDIR)
	install vsfi $(BINDIR)
	$(LDCONFIG) $(LIBDIR)

.depend: $(ML) $(MLI)
	rm -f .depend
	-$(CAMLDEP) -slash -native $+ > .depend

doc: $(ML) $(MLI)
	@mkdir -p $(DOCPATH)/html
	@mkdir -p $(DOCPATH)/latex
	@$(CAMLDOC) -html $^ -d $(DOCPATH)/html $(DIROPT) 
	@$(CAMLDOC) -latex $^ -d $(DOCPATH)/latex $(DIROPT)

.PHONY: depend all clean install update_gitver

include .depend
