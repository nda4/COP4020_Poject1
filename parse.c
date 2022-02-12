/*
    Noah Arwine                                     COP4020_Project_1                                           02/09/2022

    The source code for parse is rather...sparce (lol). Right now all it does is print to screen.
*/

#include "parse.h"

//Originall supposed to accept arguments from lex and determine whether or not said arguments are acceptable in their locations
//right now it only accepts and then prints those accepted values.
void checkParse(char *str)
{
    for (int i = 0; i < 20; i++)
    {
        if (str[i] == NULL)
            break;
        printf("%c", str[i]);
    }
    printf(" ");
}