/*
    Noah Arwine     COP4020_Project_1
    
*/




#include "lex.h"
#include "parse.h"
#include <stdlib.h>


int main(){
    FILE * file;
    char string[100];
    char lexVal[20];
    char c;
    printf("Please enter the filename to be checked: ");
    gets(string);
    file = fopen(string, "r");
    c = fgetc(file);
    while(c != EOF){ //This loop runs through the entire file
        while(!isspace(c)){
            printf("%c", c);
            strcpy(lexVal, readVal(c)); //This while loop pulls a single word in for lex analysis
            c = fgetc(file);
        }
        
        c = fgetc(file);

    };
        
    fclose(file);
}