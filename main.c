/*
    Noah Arwine                                     COP4020_Project_1                                           02/09/2022

    Main.c is the heart of the application. It ties in lex and parse and requests an input for a filename from the user.
    Once the file has successfully opened, it reads until it finds the word "BEGIN", at which point it will read one word into
    into lex. Once lex returns a value, it places said value into parse. It repeats these steps until it finds the word "END". At
    which point it returns the resulting text.
*/




#include "lex.h"
#include <stdlib.h>


int main(){
    FILE * file;
    char string[100];
    char lexVal[20];
    char c;
    printf("Please enter the filename to be checked: ");
    scanf("%s", string);
    file = fopen(string, "r");
    c = fgetc(file);
    int i;
    bool isBegin = false;
    bool start = false;
    while(c != EOF){ //This loop runs through the entire file
        if(c == '~')
            while( c != '\n')
                c = fgetc(file);
            while(!isspace(c)){
                // printf("%c", c);
                readVal(c);
                c = fgetc(file);
            }
            // printf("%c", lexeme[0],lexeme[1],lexeme[2],lexeme[3],lexeme[4]);
            if(!start)
                start = checkForHeaders();
            if(lexeme[0] == 'e' && lexeme[1] == 'n' && lexeme[2] == 'd')
                start = false;
            if(start && lexeme[0] != NULL)
                returnLex();
            // sendVal();
            // strcpy(lexVal, readVal(c)); //This while loop pulls a single word in for lex analysis
            
            c = fgetc(file);
    };
        
    fclose(file);
}