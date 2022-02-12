/*
    Noah Arwine                                     COP4020_Project_1                                           02/09/2022

    Main.c is the start of the application, it filters out the input from the file. It pulls one word out at a time
    and sends it to lex for analasis. Once analyzed, Lex should send results to Parse to be printed to the screen where the errors are.

    PLEASE NOTE: The program does not work as intended. It is simply unfinished. Lex (although rough) works more or less correctly. It 
    successfully identifies a word/letter and send the result to parse. However, Parse is unfinished and therfore only prints out the
    recieved text from lex.

    HOW TO RUN: Please type ./script.sh. This will run the program 8 times, each with a different file. You can ignore the prompt to enter filename

    Reading Results: The output will be the results from Lex: a '<text>' surrounding the text is the name of the type of text it found. It sends
    parentheses, identifier(vairables), operator, semicolon, and constants. It also sends various "~text~". These are errors found such as double
    underscores. THE VALUES ARE READ AS ~Errorname~ <Value> EVEN IF THERE IS AN ERROR. It will guess what it is supposed to be.
*/



#include "lex.h"

int main()
{
    printf("-------------------------------\n");
    FILE *file;
    char string[100];
    char lexVal[20];
    char c;
    printf("Please enter the filename to be checked: ");
    scanf("%s", string);
    file = fopen(string, "r");

    printf("\nOpening File: \n\n");
    c = fgetc(file);
    int i;
    bool isBegin = false;
    bool start = false;

    while (c != EOF)
    { // This loop runs through the entire file
        if (c == '~')
            while (c != '\n')
                c = fgetc(file);
        while (!isspace(c))
        {
            // printf("%c", c);
            readVal(c);
            c = fgetc(file);
        }
        // printf("%c", lexeme[0],lexeme[1],lexeme[2],lexeme[3],lexeme[4]);
        if (!start)
            start = checkForHeaders();
        if (lexeme[0] == 'e' && lexeme[1] == 'n' && lexeme[2] == 'd' && lexeme[3] == '.')
            start = false;
        if (start && lexeme[0] != NULL)
            returnLex();
        // sendVal();
        // strcpy(lexVal, readVal(c)); //This while loop pulls a single word in for lex analysis

        c = fgetc(file);
    };
    printf("\n_______________________________________________________________________________________________________________\n\n\n");
    fclose(file);
}