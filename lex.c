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
    // determineAnalyze();
    // printf("TEST: %s", determineAnalyze());
    checkParse(determineAnalyze());
    for(int i = 0; i < counter; i++){
        lexeme[i] = NULL;
        analyzed[i] = NULL;
    }
    counter = 0;
}

char* determineAnalyze(){
    char* analasis;
    char* identifier = "<identifier>";
    bool hasSemi = false;

    if(lexeme[counter - 1] == ';')
        hasSemi = true;
    if(isalpha(lexeme[0])){
        for(int i = 1; i < counter; i++){
            if(isOperator(lexeme[i])){
                checkParse("<identifier>");
                analasis = "<operator>";
            }
            if(lexeme[i] == '_')
                if(lexeme[i+1] == '_'){
                    analasis = "<double_under>";
                }
            if(isdigit(lexeme[counter-1]) || (hasSemi && isdigit(lexeme[counter - 2])))
                analasis = "<ends_with_num>";
        }
    }
    else if(isOperator(lexeme[0])){
        if(counter = 1)
            return "<operator>";
        else
            checkParse("<operator>");
    }
    else
        analasis = "<unknown>";
    if(hasSemi){
        checkParse(analasis);
        return "<semicolon>";
    }
    else
        return analasis;
}

bool isOperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '=')
        return true;
    return false;
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

