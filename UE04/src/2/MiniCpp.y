/*MiniCpp.y:                                              
  ------
  Attributed grammar for MiniCpp.
====================================================================*/

%{
    #include <stdio.h>
%}

%token NUMBER
%token STRING
%token IDENT
%token CONST
%token FALSE
%token TRUE
%token NULLPTR
%token VOID
%token BOOL
%token INT
%token IF
%token ELSE
%token WHILE
%token BREAK
%token CIN
%token COUT
%token ENDL
%token DELETE
%token RETURN
%token NEW

%token LOGICALAND
%token LOGICALOR
%token ADDASSIGN
%token SUBTRACTASSIGN
%token MULTIPLYASSIGN
%token DIVIDEASSIGN
%token MODULOASSIGN
%token OPINCREMENT
%token OPDECREMENT
%token OPSHIFTLEFT
%token OPSHIFTRIGHT
%token OPEQUAL
%token OPNOTEQUAL
%token OPLESS
%token OPLESSEQUAL
%token OPGREATER
%token OPGREATEREQUAL

%%

MiniCpp: MiniCppList
  ;

MiniCppList: /* eps */
  | MiniCppList ConstDef 
  | MiniCppList VarDef
  | MiniCppList FuncDecl
  | MiniCppList FuncDef
  | MiniCppList ';'
  ;

ConstDef: CONST Type IDENT Init IdentList ';'
  ;
  
IdentList: /* eps */
  | IdentList ',' IDENT Init
  ;

Init: '=' FALSE
  | '=' TRUE
  | '=' NULLPTR
  | '=' '+' NUMBER
  | '=' '-' NUMBER
  ;

VarDef: Type VarDefIdent VarDefIdentList ';'
  ;

VarDefIdentList: /* eps */ 
  | VarDefIdentList ',' VarDefIdent
  ;

VarDefIdent: '*' IDENT Init
  | IDENT
  | '*' IDENT
  | IDENT Init
  ;

FuncDecl: FuncHead ';'
  ;

FuncDef: FuncHead Block
  ;

FuncHead: Type '*' IDENT '(' ')'
  | Type IDENT '(' ')'
  | Type IDENT '(' FormParList ')'
  | Type '*' IDENT '(' FormParList ')'
  ;

FormParList: VOID
  | TypeIdent TypeIdentList
  ;

TypeIdentList: /* eps */
  | TypeIdentList ',' TypeIdent
  ;

TypeIdent: Type '*' IDENT '[' ']'
  | Type '*' IDENT
  | Type IDENT '[' ']'
  ;

Type: VOID
  | BOOL
  | INT
  ;

Block: '{' BlockList '}'
  ;

BlockList: /* eps */
  | BlockList ConstDef
  | BlockList VarDef
  | BlockList Stat
  ;

Stat: EmptyStat 
  | BlockStat
  | ExprStat
  | IfStat
  | WhileStat
  | BreakStat
  | InputStat
  | OutputStat
  | DeleteStat
  | ReturnStat
  ; 

EmptyStat: ';'
  ;

BlockStat: Block
  ;

ExprStat: Expr
  ;

IfStat: IF '(' Expr ')' Stat StatList
  ;

StatList: /* eps */
  | StatList ELSE Stat
  ;

WhileStat: WHILE '(' Expr ')'
  ;

BreakStat: BREAK ';'
  ;

InputStat: CIN OPSHIFTRIGHT IDENT ';'
  ;

OutputStat: COUT CoutRight CoutRightList ';'
  ;

CoutRightList: /* eps */
  | CoutRightList CoutRight
  ;

CoutRight: OPSHIFTLEFT Expr
  | OPSHIFTLEFT STRING
  | OPSHIFTLEFT ENDL
  ;

DeleteStat: DELETE '[' ']' IDENT ';'
  ;

ReturnStat: RETURN ';'
  | RETURN Expr ';'
  ;

Expr: OrExpr OrExprList
  ;

OrExprList: /* eps */
  | OrExprList '=' OrExpr
  | OrExprList ADDASSIGN OrExpr
  | OrExprList SUBTRACTASSIGN OrExpr
  | OrExprList MULTIPLYASSIGN OrExpr
  | OrExprList DIVIDEASSIGN OrExpr
  | OrExprList MODULOASSIGN OrExpr
  ;

OrExpr: AndExpr AndExprList
  ;

AndExprList: /* eps */
  | AndExprList LOGICALOR AndExpr
  ;

AndExpr: RelExpr RelExprList
  ;

RelExprList: /* eps */
  | RelExprList LOGICALAND RelExpr
  ;

RelExpr: SimpleExpr SimpleExprList
  ;

SimpleExprList: /* eps */
  | SimpleExprList OPEQUAL SimpleExpr
  | SimpleExprList OPNOTEQUAL SimpleExpr
  | SimpleExprList OPLESS SimpleExpr
  | SimpleExprList OPLESSEQUAL SimpleExpr
  | SimpleExprList OPGREATER SimpleExpr
  | SimpleExprList OPGREATEREQUAL SimpleExpr
  ;

SimpleExpr: '+' TermList
  | '-' TermList
  | TermList
  ;

TermList: Term
  | TermList '+' Term
  | TermList '-' Term
  ;

Term: NotFact NotFactList
  ;

NotFactList: /* eps */
  | NotFactList '*' NotFact
  | NotFactList '/' NotFact
  | NotFactList '%' NotFact
  ;

NotFact: Fact
  | '!' Fact
  ;

Fact: FALSE
  | TRUE
  | NULLPTR
  | NUMBER
  | DudeWtf
  | NEW Type '[' Expr ']'
  | '(' Expr ')'
  ;

DudeWtf: OptDecrOrIncr IDENT WeirdIdentShit OptDecrOrIncr
  ;

WeirdIdentShit: /* eps */
  | '[' Expr ']'
  | '(' ActParList ')'
  | '(' ')'
  ;

OptDecrOrIncr: /* eps */
  | OPINCREMENT
  | OPDECREMENT
  ;

ActParList: Expr ExprList
  ;

ExprList: /* eps */
  | ExprList ',' Expr
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


/* End of MiniCpp.y
====================================================================*/