/*
    Noah Arwine                                     COP4020_Project_1                                           02/09/2022

    Lex.c is the source code for the Lex portion...
*/

#include "lex.h"


char* readVal(char nextVal){
    if(counter == NULL)
        counter = 0;
    if(nextVal != " "){
        lexeme[counter] = nextVal;
        counter++;
    }
    return "a";
}

void sendVal(){
    // counter = 0;
    for(int i = 0; i < counter; i++){
        // printf("%i ", i);
        printf("%s", &lexeme[i]);
    }
    counter = 0;
    printf(" ");
}