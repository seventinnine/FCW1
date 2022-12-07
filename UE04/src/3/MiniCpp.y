/*MiniCpp.y:                                             HDO, 2006-2015
  ------
  Attributed grammar for MiniCpp.
====================================================================*/
%define parse.lac full
%error-verbose

%{
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>

  char* funcName = NULL;

  char* setFuncName();
%}

%union {
  int iNum;
  char* iIdent;
} /* union */

%type <iNum> OptFactOpt


%token NUMBER
%token CONST 
%token FALSE 
%token TRUE
%token NULLPTR
%token BOOL
%token IF
%token ELSE
%token WHILE 
%token BREAK 
%token CIN
%token COUT
%token STRING
%token ENDL
%token RETURN
%token NEW
%token VOID
%token INT
%token <iIdent> IDENT
%token DELETE

%token SMALLEREQUALS
%token GREATEREQUALS
%token CINSY
%token COUTSY
%token PLUSASG
%token MINUSASG
%token TIMESASG
%token DIVIDEASG
%token MODASG
%token EQUALS
%token NOTEQUALS
%token PLUSPLUS
%token MINUSMINUS
%token OR
%token AND

%%
MiniCpp: /* eps */ { printf("MiniCpp eps") ;}
  | MiniCpp ConstDef { printf("MiniCpp const") ;}
  | MiniCpp VarDef { printf("MiniCpp vardef") ;}
  | MiniCpp Func { printf("MiniCpp func") ;}
  | MiniCpp ';' { printf("MiniCpp ;") ;}
  ;

ConstDef: CONST Type IDENT Init OptIdentInit ';' ;

OptIdentInit: /* eps */
  | OptIdentInit ',' IDENT Init
  ;

Init: '=' InitValue ;

InitValue: FALSE
  | TRUE
  | NULLPTR
  | '+' NUMBER
  | '-' NUMBER
  ;

VarDef: Type VarDefContentVariable VarDefContent ';' ;

VarDefContent: /* eps */
  | VarDefContent ',' VarDefContentVariable
  ;

VarDefContentVariable: OptStar IDENT OptInit
  ;  

OptStar: /* eps */
  | '*'
  ;

OptInit: /* eps */
  | Init
  ;

Func: FuncHead WhatFunc { printf("Func");}
  ;

WhatFunc: FuncDecl
  | FuncDef
  ;

FuncDecl: ';' ;

FuncDef: Block ;

FuncHead: Type OptStar IDENT '(' OptFormParList ')'  { printf("%s", $3); setFuncName($3); }
  ;

OptFormParList: /* eps */
  | FormParList
  ;

FormParList: VOID
  | FormParameter FormParListContent
  ;

FormParListContent: /* eps */
  | FormParListContent ',' FormParameter
  ;

FormParameter: Type OptStar IDENT OptArray
  ;

OptArray: /* eps */
  | '[' ']'
  ;

Type: VOID
  | INT
  | BOOL
  ;

Block: '{' OptBlockContent '}' ;

OptBlockContent: /* eps */
  | OptBlockContent ConstDef
  | OptBlockContent VarDef
  | OptBlockContent Stat
  ;

Stat: EmptyStat
  | Block
  | ExprStat
  | IfStat
  | WhileStat
  | BreakStat
  | InputStat
  | OutputStat
  | DeleteStat
  | ReturnStat
  ;

EmptyStat: ';' ;

ExprStat: Expr ';' ;

IfStat: IF '(' Expr ')' Stat ElseOptStat ;

ElseOptStat: /* eps */
  | ELSE Stat
  ;

WhileStat: WHILE '(' Expr ')' Stat ;

BreakStat: BREAK ';' ;

InputStat: CIN CINSY IDENT ';' ;

OutputStat: COUT COUTSY OutputOptionsDef OutputOptions ';' ;

OutputOptions: /* eps */
  | OutputOptions COUTSY OutputOptionsDef
  ;

OutputOptionsDef: Expr
  | STRING
  | ENDL
  ;

DeleteStat: DELETE '[' ']' IDENT ';' ;

ReturnStat: RETURN OptExpr ';'

OptExpr: /* eps */
  | Expr 
  ;

Expr: OrExpr OptAnotherOrExpr;

OptAnotherOrExpr: /* eps */
  | OptAnotherOrExpr AssignmentOperator OrExpr
  ;

AssignmentOperator: '='
  | PLUSASG
  | MINUSASG
  | TIMESASG
  | DIVIDEASG
  | MODASG
  ;

OrExpr: AndExpr OptAndExpr;

OptAndExpr: /* eps */
  | OptAndExpr OR AndExpr
  ;

AndExpr: RelExpr OptRelExpr ;

OptRelExpr: /* eps */
  | OptRelExpr AND RelExpr
  ;

RelExpr: SimpleExpr AnotherRelExpr ;

AnotherRelExpr: /* eps */
  | AnotherRelExpr CompareSymbol SimpleExpr
  ;

CompareSymbol: EQUALS
  | NOTEQUALS
  | '<'
  | SMALLEREQUALS
  | GREATEREQUALS
  | '>'
  ;

PlusOrMinus: '+'
  | '-'
  ;

OptSign: /* eps */
 | PlusOrMinus
 ;

SimpleExpr: OptSign Term AnotherTerm ;

AnotherTerm: /* eps */
  | AnotherTerm PlusOrMinus Term
  ;

Term: NotFact AnotherNotFact;

AnotherNotFact: /* eps */
  | AnotherNotFact FactSymbol NotFact
  ;

FactSymbol: '*'
  | '/'
  | '%'
  ;

NotFact: '!' Fact
  | Fact
  ;

Fact: FALSE
  | TRUE
  | NULLPTR
  | NUMBER
  | FactOpt
  | NEW Type '[' Expr ']'
  |'(' Expr ')'
  ;

FactOpt: OptPlusPlus IDENT OptFactOpt OptPlusPlus { if ($3 == 1) printf("%s() -> %s()\n", funcName, $2); }
  ;

OptPlusPlus: /* eps */
  | PLUSPLUS
  | MINUSMINUS
  ;

OptFactOpt: /* eps */ { $$ = 0; }
  |'[' Expr ']' { $$ = 0; }
  | '(' OptActParList ')' { $$ = 1; }
  ;

OptActParList: /* eps */
  | Expr ActParList;

ActParList: /* eps */
  | ActParList ',' Expr
  ;
 
%%

extern int yylineno;

int yyerror(char *msg) {
  printf("error: %s in line %d\n", msg, yylineno);
  return 0;
} /*yyerror*/

char* setFuncName(char* tmp) {
  printf("Hello1\n");
  if (funcName != NULL)
    free(funcName);
  printf("Hello2\n");
  if (tmp == NULL)
    printf("IS NULL");
  printf("if");
  printf("%s\n", tmp);
  funcName = malloc(strlen(tmp + 1));
  printf("Hello3\n");
  strcpy(tmp, funcName);
  printf("Hello4\n");
  return funcName;
}

//int yyerror(char *msg) {
//  printf("error: %s\n", msg);
//  return 0;
//} /*yyerror*/

int main(int argc, char *argv[]) {
  yyparse();
  return 0;
} /*main*/


/* End of MiniCpp.y
====================================================================*/