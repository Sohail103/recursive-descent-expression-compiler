#define EOI 0           // end of input
#define SEMI 1          // ;
#define PLUS 2          // +
#define TIMES 3         // *
#define LP 4            // (
#define RP 5            // )
#define NUM_OR_ID 6     // decimal number or identifier

extern char *yytext; // pointer to the current token text
extern int yyleng;    // length of the current token text
extern int yylineno;  // current line number