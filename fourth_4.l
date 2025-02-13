%option noyywrap
%{
    #include<stdio.h>
    int l=0,d=0,lc=0,uc=0,ss=0,ec=0;
%}
%%
[0-9] {d++;l++;}
[a-z] {lc++;l++;}
[A-Z] {uc++;l++;}
[@#;&*] {ss++;l;;}
\n {if(d>0 && lc>0 && uc>0 && ss>0 && l>=9 && l<=15 && ec==0){printf("valid\n");}
   else{printf("invalid\n");}}
. {ec++;}
%%
int main()
{
  printf("enter String ");
  yylex();

  return 0;
}

