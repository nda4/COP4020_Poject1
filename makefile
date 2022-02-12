run: parse lex main.c
	gcc -w -o letsagoitsameamario lex.o parse.o main.c
	
parse: lex parse.c
	gcc -c -w parse.h parse.c
lex: lex.c
	gcc -c -w lex.h lex.c

clean:
	rm lex.o parse.o parse.h.gch lex.h.gch letsagoitsameamario