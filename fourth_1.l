%option noyywrap
%{
    #include<stdio.h>
%}
%%
[0-9]+ {printf("%s \n",yytext);
        printf("length %d",yyleng);}
. ;
%%
int main()
{
  printf("enter String ");
  yylex();
  return 0;
}

