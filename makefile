run: parse.o
	gcc main.c
	./a.out
parse.o: lex.o
	gcc parse.h parse.c
lex.o:
	gcc lex.h lex.c