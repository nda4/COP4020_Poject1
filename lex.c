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
    if(nextVal == " "){
        sendVal();
        counter = 0;
    }
    return "a";
}

void sendVal(){
    // counter = 0;
    for(int i = 0; i < counter; i++){
        printf("%s", &lexeme[i]);
    }
}