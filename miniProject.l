%{
#include <stdio.h>
#include <string.h>

void printResult(const char* msg) {
    printf("%s\n", msg);
}
%}

%%

[ \t]function[ \t]+[a-zA-Z_$][a-zA-Z0-9_$][ \t]\(.\)[ \t]\{[^{}]\}[ \t]* { printResult("Valid Function Declaration!"); }
[ \t]const[ \t]+[a-zA-Z_$][a-zA-Z0-9_$][ \t]=[ \t]*function[ \t]\(.\)[ \t]\{[^{}]\}[ \t];?[ \t]* { printResult("Valid Function Expression!"); }
[ \t]const[ \t]+[a-zA-Z_$][a-zA-Z0-9_$][ \t]=[ \t]\(.\)[ \t]=>[ \t]\{[^{}]\}[ \t];?[ \t] { printResult("Valid Arrow Function with Block!"); }
[ \t]const[ \t]+[a-zA-Z_$][a-zA-Z0-9_$][ \t]=[ \t]\(.\)[ \t]=>[ \t][^{}]+[ \t];?[ \t]* { printResult("Valid Arrow Function with Implicit Return!"); }
.* { printResult("Syntax Error: Invalid function definition!"); }

%%

int main() {
    printf("Enter a JavaScript function definition:\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1; 
}
