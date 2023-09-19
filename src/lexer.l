%{
#include <stdio.h>
int yywrap() { return 1; }
%}


%{
#include <stdio.h>
%}

%% 
[0-9]+      { printf("NUMBER: %s\n", yytext); }
[a-zA-Z]+   { printf("IDENTIFIER: %s\n", yytext); }
"="         { printf("ASSIGN: %s\n", yytext); }
"+"         { printf("PLUS: %s\n", yytext); }
"-"         { printf("MINUS: %s\n", yytext); }
"*"         { printf("MULTIPLY: %s\n", yytext); }
"/"         { printf("DIVIDE: %s\n", yytext); }
" "         { /* ignore whitespace */ }
"\n"        { /* ignore newlines */ }
.           { printf("UNKNOWN: %s\n", yytext); }
%%

int main() {
    yylex();
    return 0;
}
