/*
    Noah Arwine                                     COP4020_Project_1                                           02/09/2022

    Parse.h is the header file for the Parse section. It takes the lexeme catagory from Lex and checks if
    it is what is expected. If correct, it then assigns a next expected entry. If incorrect, it runs an
    error code for the user.
    
    PLEASE NOTE: I was not able to finish this portion. At the time all it does is accept what Lex has given and dump it onto the screen.
*/

#ifndef PARSE
#define PARSE
#include <stdio.h>

void checkParse(char *str);

#endif