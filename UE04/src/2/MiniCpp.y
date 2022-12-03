/*MiniCpp.y:                                              
  ------
  Attributed grammar for MiniCpp.
====================================================================*/

%{
  #include <stdio.h>
  #include <stdbool.h>
  #include <string.h>
  #include <stdlib.h>
  
  // continously concat already processed function calls
  char* currGraphBody;

  // list of function names
  // no stack needed as grammar does not 
  // support nested function definitions
  char* calledFuncs[100]; // max 100 called funcs per func
  
  // creates an edge from node to all nodes in calledFuncs
  // and clears calledFuncs
  void addEdges(char* node);

  // adds node to calledFuncs
  void addCalledFunc(char* node);

%}

%union {
  char* iIdent;
} /* union */

%token <iIdent> IDENT

%type <iIdent> WeirdIdentStuff FuncHead

%token NUMBER
%token STRING
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

// print graph def + edges
MiniCpp: MiniCppList { printf("digraph program {\n\tfontname=\"Helvetica,Arial,sans-serif\"\n\tnode [fontname=\"Helvetica,Arial,sans-serif\"]\n\tedge [fontname=\"Helvetica,Arial,sans-serif\"]\n\trankdir=LR;\n\tnode [shape = box];\n%s\n}", currGraphBody); }
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

// add all edges from FuncHead (ident name) to saved func names
FuncDef: FuncHead Block { addEdges($1); }
  ;

// retrieve ident name for node
FuncHead: Type '*' IDENT '(' ')'        { $$ = $3; }
  | Type IDENT '(' ')'                  { $$ = $2; }
  | Type IDENT '(' FormParList ')'      { $$ = $2; }
  | Type '*' IDENT '(' FormParList ')'  { $$ = $3; }
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
  | Type IDENT
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

ExprStat: Expr ';'
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

SimpleExpr: '+' Term TermList
  | '-' Term TermList
  | Term TermList
  ;

TermList: /* eps */
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

DudeWtf: OptDecrOrIncr WeirdIdentStuff OptDecrOrIncr
  ;

// save func name (ident) to list of called funcs
WeirdIdentStuff: IDENT
  | IDENT '[' Expr ']'
  | IDENT '(' ActParList ')' { addCalledFunc($1); }
  | IDENT '(' ')'            { addCalledFunc($1); }
  ;

OptDecrOrIncr: /* eps */
  | OPINCREMENT
  | OPDECREMENT
  ;

ActParList: ExprList
  ;

ExprList: Expr
  | ExprList ',' Expr
  ;
 
%%
extern int yylineno;

int yyerror(char *msg) {
  printf("error: %s in line %d\n", msg, yylineno);
  return 0;
} /*yyerror*/

// concats 2 malloc'd strings
char* myconcat(char *s1, char *s2) {
  // s1 (currGraphBody) is null at first => just take s2
  if (s1 == NULL) return s2;
  char *result = malloc(strlen(s1) + strlen(s2) + 1);
  // assume malloc worked
  strcpy(result, s1);
  strcat(result, s2);
  free(s1);
  free(s2);
  return result;
}

void appendEdge(char* node, char* func) {
  // create buffer with enough space for formatted printing
  // +6 for " -> " and "\n\t"
  char* buf = malloc(strlen(node) + strlen(func) + 1 + 6); 

  sprintf(buf, "\n\t%s -> %s", node, func);

  currGraphBody = myconcat(currGraphBody, buf);

  // free buf
  free(buf);
}

int funcCount = 0;

void addCalledFunc(char* node) {
  calledFuncs[funcCount] = node;
  funcCount++;
}

void addEdges(char* node) {
  for (int i = 0; i < funcCount; i++) {
    //printf("%s -> %s\n\t", node, calledFuncs[i]);
    appendEdge(node, calledFuncs[i]);
    free(calledFuncs[i]);
  }
  funcCount = 0;
}

int main(int argc, char *argv[]) {
  yyparse();
  free(currGraphBody);
  return 0;
} /*main*/


/* End of MiniCpp.y
====================================================================*/