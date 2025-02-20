%option noyywrap
%{
    #include <stdio.h>
    #include <string.h>
    extern FILE *yyin;
%}

%%

[ \t\n]+                 ;
"//".*                   { printf("This is a single-line comment: %s\n", yytext); }
"/*"([^*]|\*+[^*/])*\*+"/" { printf("This is a multi-line comment: %s\n", yytext); }

(auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while) { 
    printf("Keyword: %s\n", yytext); 
}

[a-zA-Z_][a-zA-Z0-9_]*  { printf("Identifier: %s\n", yytext); }

(==|!=|<=|>=|&&|\|\||\+\+|--|[-+*/%=<>&|!]) { printf("Operator: %s\n", yytext); }

[0-9]+\.[0-9]+ | [0-9]+ { printf("Constant: %s\n", yytext); }  

'([^'\\]|\\.)' { printf("Character: %s\n", yytext); }  
\"([^\"\\]|\\.)*\" { printf("String: %s\n", yytext); }

[{}()\[\],;] { printf("Punctuation: %s\n", yytext); }

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
