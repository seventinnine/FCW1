/*MiniC.l:                                            
  ------
  Description of the lexical structure for MiniCw.
====================================================================*/

%{

  #include "MiniC.tab.h" /*generated by yacc/bison from MiniC.y
                          if option -d is used, defines NUMBER      */


%}

%x IN_COMMENT

%%

<INITIAL>{
"/*" BEGIN(IN_COMMENT);
}
<IN_COMMENT>{
"*/" BEGIN(INITIAL);
[^*\n]+ // eat comment in chunks
"*" // eat the lone star
\n yylineno++;
}

"//".*\n                  { ; } /* ignore comments */
[ \t\r\n]+              { ; } /*ignore white space: blanks, tabs and new line */
[0-9]+                  { return NUMBER; }              
void                    { return VOID; }
main                    { return MAIN; }
int                     { return INT; }
scanf                   { return SCANF; }
printf                  { return PRINTF; }
[A-Za-z_][A-Za-z0-9\_]* { return IDENT; }
.                       { return yytext[0]; } /*return all other chars 
                                 as tokens: '+', '-', ...           */
%%

int yywrap() {
  return 1; /*on end of input: no further files to scan             */
} /*yywrap*/

/* End of MiniC.l
====================================================================*/