/*
    Noah Arwine                                     COP4020_Project_1                                           02/09/2022

    Lex.c is the source code for the Lex portion...
*/

#include "lex.h"
#include "parse.h"


void readVal(char nextVal){
    if(counter == NULL)
        counter = 0;
    if(nextVal != " "){
        lexeme[counter] = nextVal;
        counter++;
    }
}

void returnLex(){
    checkParse(lexeme);
    for(int i = 0; i < counter; i++){
        lexeme[i] = NULL;
        analyzed[i] = NULL;
    }
    counter = 0;
}

bool checkForHeaders(){
    if(lexeme[0] == 'b' && lexeme[1] == 'e' && lexeme[2] == 'g' && lexeme[3] == 'i' && lexeme[4] == 'n'){
        for(int i = 0; i < counter; i++){
            lexeme[i] = NULL;
            analyzed[i] = NULL;
        }
        counter = 0;
        return true;
    }
    return false;
}

void sendVal(){
    // counter = 0;
    for(int i = 0; i < counter; i++){
        // printf("%i ", i);
        // printf("%s", &lexeme[i]);
    }
    counter = 0;
    // printf(" ");
}