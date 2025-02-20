%option noyywrap
%{
    #include <stdio.h>
    #include <string.h>
    extern FILE *yyin;
%}

%%

"//".*                   { printf("This is a single-line comment: %s\n", yytext); }

"/*"[^*]*"*/" { printf("This is a multi-line comment: %s\n", yytext); }
[ \t\n]+                 ;


(auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while) { 
    printf("Keyword: %s\n", yytext); 
}

[a-zA-Z_][a-zA-Z0-9_]*  { printf("Identifier: %s\n", yytext); }

(==|!=|<=|>=|&&|\|\||\+\+|--|[-+*/%=<>&|!]) { printf("Operator: %s\n", yytext); }

[0-9]+\.[0-9]+ | [0-9]+ { printf("Constant: %s\n", yytext); }  

'[a-zA-Z0-9\_]' { printf("Character literal: %s\n", yytext); } 
 
"\"".*"\"" {printf("String literal: %s\n",yytext);}

[{}()\[\],;] { printf("Punctuation: %s\n", yytext); }

. {printf("unknown token %s\n",yytext);}

%%

int main() {
    yyin = fopen("input3.c", "r");
    if (!yyin) {
        printf("Error: Could not open file\n");
        return 1;
    }
    yylex();
    fclose(yyin);
    return 0;
}
