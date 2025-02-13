%option noyywrap
%{
    #include<stdio.h>
%}
%%
charusat {printf("university");}
. {printf("%c",yytext[0]);}
%%
int main()
{
  printf("enter String ");
  yylex();
  return 0;
}

