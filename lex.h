#ifndef LEX_H
#define LEX_H
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

    
char* readVal(char nextVal);
char* lexeme;

bool isNum();
bool isLetter();





#endif