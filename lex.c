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
                return EOI;
            }
            yylineno++;

            while(isspace(*current)) current++; // skip leading spaces
        }

        for (; *current; ++current)
        {
            // Get the next token

            yytext = current;
            yyleng = 1;

            switch (*current)
            {
                case EOF: return EOI;
                case ';': return SEMI;
                case '+': return PLUS;
                case '*': return TIMES;
                case '(': return LP;
                case ')': return RP;
                case '\n':
                case '\t':
                case ' ': break;

                default:
                {
                    if(!isalnum(*current))
                        fprintf(stderr, "Ignoring illegal input <%c>\n", *current);
                    else
                    {
                        while (isalnum(*current)) ++current;
                        yyleng = current - yytext;
                        return NUM_OR_ID;
                    }
                    break;
                }
            }
        }
    }
}