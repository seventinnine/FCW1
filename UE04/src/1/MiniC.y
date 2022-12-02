/*MiniC.y:                                              
  ------
  Attributed grammar for MiniC.
====================================================================*/

%{
    #include <stdio.h>

    extern
%}

%token NUMBER
%token IDENT
%token VOID
%token MAIN
%token INT
%token SCANF
%token PRINTF

%%

MiniC: VOID MAIN '(' ')' '{' 
                    OptVarDecl 
                    StatSeq 
                    '}' 
  ;

OptVarDecl: /* eps */
  | VarDecl
  ;

VarDecl: INT IdList ';' 
  ;

IdList: IDENT
  | IdList ',' IDENT
  ;

StatSeq: Stat
  | StatSeq Stat
  ;

Stat: ';'
  | IDENT '=' Expr ';'
  | SCANF '(' IDENT ')' ';'
  | PRINTF '(' Expr ')' ';'
  ;

Expr: Term         
  | Expr '+' Term  
  | Expr '-' Term 
  ;

Term: Fact        
  | Term '*' Fact
  | Term '/' Fact 
  ;
  
Fact: IDENT 
  | NUMBER
  | '(' Expr ')'
  ;
 
%%
extern int yylineno;

int yyerror(char *msg) {
  printf("error: %s in line %d\n", msg, yylineno);
  return 0;
} /*yyerror*/

int main(int argc, char *argv[]) {
  yyparse();
  return 0;
} /*main*/


/* End of Calc.y
====================================================================*/