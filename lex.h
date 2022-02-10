/*
    Noah Arwine                                     COP4020_Project_1                                           02/09/2022

    Lex.h is the header file for the Lexical analysis portion. It recieves a word from the read file. 
    Once recieved, it will compare to a list of possibilities to find and assign a correct catagory for the word. 
    This catagory is then turned over to Parse for later processes
*/

#ifndef LEX_H
#define LEX_H
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* readVal(char nextVal);
char* lexeme[20];
int counter;

void sendVal();

bool isNum();
bool isLetter();





#endif