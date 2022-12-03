/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_MINICPP_TAB_H_INCLUDED
# define YY_YY_MINICPP_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENT = 258,
     NUMBER = 259,
     STRING = 260,
     CONST = 261,
     FALSE = 262,
     TRUE = 263,
     NULLPTR = 264,
     VOID = 265,
     BOOL = 266,
     INT = 267,
     IF = 268,
     ELSE = 269,
     WHILE = 270,
     BREAK = 271,
     CIN = 272,
     COUT = 273,
     ENDL = 274,
     DELETE = 275,
     RETURN = 276,
     NEW = 277,
     LOGICALAND = 278,
     LOGICALOR = 279,
     ADDASSIGN = 280,
     SUBTRACTASSIGN = 281,
     MULTIPLYASSIGN = 282,
     DIVIDEASSIGN = 283,
     MODULOASSIGN = 284,
     OPINCREMENT = 285,
     OPDECREMENT = 286,
     OPSHIFTLEFT = 287,
     OPSHIFTRIGHT = 288,
     OPEQUAL = 289,
     OPNOTEQUAL = 290,
     OPLESS = 291,
     OPLESSEQUAL = 292,
     OPGREATER = 293,
     OPGREATEREQUAL = 294
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 29 "MiniCpp.y"

  char* iIdent;


/* Line 2058 of yacc.c  */
#line 101 "MiniCpp.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_MINICPP_TAB_H_INCLUDED  */
