/*
    Noah Arwine                                     COP4020_Project_1                                           02/09/2022

    ...
*/

#include "parse.h"


void checkParse(char* str){
    for(int i = 0; i < 20; i++){
        if (str[i] == NULL)
            break;
        printf("%c", str[i]);
    }
    printf(" ");
}