run: parse lex main.c
	gcc -o letsagoitsameamario lex.o parse.o main.c
	./letsagoitsameamario
parse: lex parse.c
	gcc -c parse.h parse.c
lex: lex.c
	gcc -c lex.h lex.c