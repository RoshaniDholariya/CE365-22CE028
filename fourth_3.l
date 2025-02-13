%option noyywrap
%{
    #include<stdio.h>
    int l=0,c=0,w=0;
%}
%%
[\n] {l++;}
[ \t] {c+=yyleng;}
[^\t\n ]+ {w++; c+=yyleng;}
<<EOF>> {yyterminate();}
%%
int main()
{
  printf("enter String ");
  yylex();
  printf(" line %d char %d word %d",l,c,w);

  return 0;
}

