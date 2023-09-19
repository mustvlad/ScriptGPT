%{
#include <stdio.h>
int yylex(void);
int yyerror(const char *s);
%}

%{
#include <stdio.h>
%}

%token NUMBER IDENTIFIER ASSIGN PLUS MINUS MULTIPLY DIVIDE

%%

program: statements
       ;

statements: statement
          | statements statement
          ;

statement: assignment
         | /* other types of statements */
         ;

assignment: IDENTIFIER ASSIGN expression
          ;

expression: term
          | expression PLUS term
          | expression MINUS term
          ;

term: factor
    | term MULTIPLY factor
    | term DIVIDE factor
    ;

factor: NUMBER
      | IDENTIFIER
      ;

%%

int main() {
    yyparse();
    return 0;
}

int yyerror(const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
    return 0;
}
