# Makefile simple pour le compilateur SIMPL

all:
	flex lexer.l
	bison -d parser.y
	gcc -Wall -g -c symbol_table.c
	gcc -Wall -g -c quadruplet.c
	gcc -Wall -g -c stack.c
	gcc -Wall -g -c parser.tab.c
	gcc -Wall -g -c lex.yy.c
	gcc -Wall -g -o simpl_compiler parser.tab.c lex.yy.c symbol_table.c quadruplet.c stack.c -lm
	@echo "Compilation terminee! Executable: simpl_compiler"

test: all
	./simpl_compiler test.simpl

clean:
	rm -f *.o parser.tab.c parser.tab.h lex.yy.c simpl_compiler

.PHONY: all test clean