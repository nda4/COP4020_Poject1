/*
    Noah Arwine                                     COP4020_Project_1                                           02/09/2022

    Lex.c is the source code for the Lex portion. It is quite ugly, as I foolishly decided to try hand writing everything. However,
    I believe it is currently working correctly. 
*/

#include "lex.h"
#include "parse.h"

//readVal simply counts the number of char in a word.
void readVal(char nextVal)
{
    if (counter == NULL)
        counter = 0;
    if (nextVal != " ")
    {
        lexeme[counter] = nextVal;
        counter++;
    }
}

//This is the call for main that initilizes the analisis, it will end with a final returned value to Parse.
void returnLex()
{
    // determineAnalyze();
    // printf("TEST: %s", determineAnalyze());
    checkParse(determineAnalyze());
    for (int i = 0; i < counter; i++)
    {
        lexeme[i] = NULL;
        analyzed[i] = NULL;
    }
    counter = 0;
}

//determineAnalyze is the primary power point for Lex. It returns a char to returnLex, but before that, it calls checkParse within itself many times
//to keep values in order. I should have seperated the work more, but it essentially calculates what a word is by breaking down each
//component and comparing them to their surroundings to find what sort of value it is. It also detects id errors.
char *determineAnalyze()
{
    char *analasis;
    char *identifier = "<identifier>";
    bool hasSemi = false;
    bool hasop = false;
    bool isconst = false;

    if (lexeme[counter - 1] == ';')
        hasSemi = true;
    if (isdigit(lexeme[0]))
    {
        for (int j = 0; j < counter; j++)
        {
            if (!isdigit(lexeme[j]) && lexeme[j] != ';' && lexeme[j] != '(' && lexeme[j] != ')')
                isconst = false;
            else
            {
                isconst = true;
            }
            if (isOperator(lexeme[j + 1]) || lexeme[j + 1] == '(' || lexeme[j + 1] == ')')
            {
                break;
            }
        }
    }
    if (isconst)
        checkParse("<constant>");

    if (lexeme[0] == '(')
        checkParse("<open_paren>");
    if (lexeme[0] == ')')
        checkParse("<close_paren>");

    if (isconst && hasSemi && counter < 3)
        return "<semicolon>";

    bool hasparen = false;

    if (isalpha(lexeme[0]) || isconst || lexeme[0] == '(' || lexeme[0] == ')')
    {
        for (int i = 1; i < counter; i++)
        {
            if (isOperator(lexeme[i]) && !isconst)
            {
                checkParse("<identifier>");
                checkParse("<operator>");
                hasop = true;
            }
            if (isOperator(lexeme[i]) && isconst)
            {
                checkParse("<operator>");
                hasop = true;
            }
            if (lexeme[i] == '(' && lexeme[i - 1] != '(' && !isconst)
            {
                checkParse("<identifier>");
                checkParse("<open_paren>");
                hasparen = true;
            }
            if (lexeme[i] == '(' && lexeme[i - 1] == '(')
            {
                checkParse("<open_parn>");
                hasparen = true;
            }
            if (lexeme[i] == ')' && lexeme[i - 1] != ')' && !isconst)
            {
                checkParse("<identifier>");
                identifier = "<close_paren>";
                hasparen = true;
            }
            if (lexeme[i] == ')' && lexeme[i - 1] != ')' && isconst)
            {
                checkParse("<close_paren>");
                hasparen = true;
            }
            if (lexeme[i] == ')' && lexeme[i - 1] == ')')
            {
                checkParse("<close_paren>");
                hasparen = true;
            }
            if (lexeme[i] == '_')
            {
                if (lexeme[i + 1] == '_')
                {
                    checkParse("~double_under~");
                }
                else if (!isalpha(lexeme[i + 1]) && !isdigit(lexeme[i + 1]))
                    checkParse("~ends_with_under~");
            }
            if (isdigit(lexeme[counter - 1]) || (hasSemi && isdigit(lexeme[counter - 2])) && !hasop && !isconst)
                analasis = "~ends_with_num~";
            if (isdigit(lexeme[i]) && hasop)
                if (isOperator(lexeme[i - 1]))
                {
                    isconst = true;
                    analasis = "<constant>";
                }
        }
        if (!isconst && !hasparen)
        {
            analasis = "<identifier>";
        }
        if (lexeme[counter - 1] == '(')
            analasis = "<open_paren>";
        if (lexeme[counter - 1] == ')')
            analasis = "<close_paren>";
        if (lexeme[counter - 2] == '(' && hasSemi)
            analasis = "<open_paren>";
        if (lexeme[counter - 2] == ')' && hasSemi)
            analasis = "<close_paren>";
    }
    else if (isOperator(lexeme[0]))
    {
        if (counter = 1)
            return "<operator>";
        else
            checkParse("<operator>");
    }
    if (hasSemi)
    {
        checkParse(analasis);
        return "<semicolon>";
    }
    else
        return analasis;
}

//This is a simple step for determining if a char is a operator
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=')
        return true;
    return false;
}
//This is used in main to determine when to start reading words into Lex
bool checkForHeaders()
{
    if (lexeme[0] == 'b' && lexeme[1] == 'e' && lexeme[2] == 'g' && lexeme[3] == 'i' && lexeme[4] == 'n')
    {
        for (int i = 0; i < counter; i++)
        {
            lexeme[i] = NULL;
            analyzed[i] = NULL;
        }
        counter = 0;
        return true;
    }
    return false;
}

void sendVal()
{
    // counter = 0;
    for (int i = 0; i < counter; i++)
    {
        // printf("%i ", i);
        // printf("%s", &lexeme[i]);
    }
    counter = 0;
    // printf(" ");
}
