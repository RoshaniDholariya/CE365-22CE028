%option noyywrap
%{
    #include<stdio.h>
    int v=0,c=0;
%}
%%
[aeiouAEIOU] {v++;}
[a-zA-Z] {c++;}
[ \t\n] ;
. ;
%%
int main()
{
  printf("enter String");
  yylex();
  printf("No of Vowels %d",v);
  printf("No of contenets %d",c);
  return 0;
}

