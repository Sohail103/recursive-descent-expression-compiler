// Simple lexical analyzer

#include "lex.h"
#include <stdio.h>
#include <ctype.h>

char *yytext = "";  // lexeme (not '\0' terminated)
int yyleng = 0;     // lexeme length
int yylineno = 0;   // input line number

lex()
{
    static char input_buffer[128];
    char * current;

    current = yytext + yyleng;

    while(1)
    {
        while(!*current)
        {
            // while current is empty, get new line (skip leading spaces)

            current = input_buffer;
            if(!gets(input_buffer))
            {
                *current = '\0'; // end of input
                return EOI;;
            }
        }
    }
}