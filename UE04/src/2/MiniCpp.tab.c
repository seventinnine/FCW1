/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 6 "MiniCpp.y"

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


/* Line 371 of yacc.c  */
#line 91 "MiniCpp.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


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
/* Line 387 of yacc.c  */
#line 29 "MiniCpp.y"

  char* iIdent;


/* Line 387 of yacc.c  */
#line 175 "MiniCpp.tab.c"
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



/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 203 "MiniCpp.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   267

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNRULES -- Number of states.  */
#define YYNSTATES  213

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,     2,     2,    53,     2,     2,
      46,    47,    45,    43,    41,    44,     2,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
       2,    42,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,    51,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    12,    15,    18,    21,
      28,    29,    34,    37,    40,    43,    47,    51,    56,    57,
      61,    65,    67,    70,    73,    76,    79,    85,    90,    96,
     103,   105,   108,   109,   113,   119,   123,   128,   131,   133,
     135,   137,   141,   142,   145,   148,   151,   153,   155,   157,
     159,   161,   163,   165,   167,   169,   171,   173,   175,   178,
     185,   186,   190,   195,   198,   203,   208,   209,   212,   215,
     218,   221,   227,   230,   234,   237,   238,   242,   246,   250,
     254,   258,   262,   265,   266,   270,   273,   274,   278,   281,
     282,   286,   290,   294,   298,   302,   306,   310,   314,   317,
     318,   322,   326,   329,   330,   334,   338,   342,   344,   347,
     349,   351,   353,   355,   357,   363,   367,   371,   373,   378,
     383,   387,   388,   390,   392,   394,   396
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      56,     0,    -1,    57,    -1,    -1,    57,    58,    -1,    57,
      61,    -1,    57,    64,    -1,    57,    65,    -1,    57,    40,
      -1,     6,    70,     3,    60,    59,    40,    -1,    -1,    59,
      41,     3,    60,    -1,    42,     7,    -1,    42,     8,    -1,
      42,     9,    -1,    42,    43,     4,    -1,    42,    44,     4,
      -1,    70,    63,    62,    40,    -1,    -1,    62,    41,    63,
      -1,    45,     3,    60,    -1,     3,    -1,    45,     3,    -1,
       3,    60,    -1,    66,    40,    -1,    66,    71,    -1,    70,
      45,     3,    46,    47,    -1,    70,     3,    46,    47,    -1,
      70,     3,    46,    67,    47,    -1,    70,    45,     3,    46,
      67,    47,    -1,    10,    -1,    69,    68,    -1,    -1,    68,
      41,    69,    -1,    70,    45,     3,    48,    49,    -1,    70,
      45,     3,    -1,    70,     3,    48,    49,    -1,    70,     3,
      -1,    10,    -1,    11,    -1,    12,    -1,    50,    72,    51,
      -1,    -1,    72,    58,    -1,    72,    61,    -1,    72,    73,
      -1,    74,    -1,    75,    -1,    76,    -1,    77,    -1,    79,
      -1,    80,    -1,    81,    -1,    82,    -1,    85,    -1,    86,
      -1,    40,    -1,    71,    -1,    87,    40,    -1,    13,    46,
      87,    47,    73,    78,    -1,    -1,    78,    14,    73,    -1,
      15,    46,    87,    47,    -1,    16,    40,    -1,    17,    33,
       3,    40,    -1,    18,    84,    83,    40,    -1,    -1,    83,
      84,    -1,    32,    87,    -1,    32,     5,    -1,    32,    19,
      -1,    20,    48,    49,     3,    40,    -1,    21,    40,    -1,
      21,    87,    40,    -1,    89,    88,    -1,    -1,    88,    42,
      89,    -1,    88,    25,    89,    -1,    88,    26,    89,    -1,
      88,    27,    89,    -1,    88,    28,    89,    -1,    88,    29,
      89,    -1,    91,    90,    -1,    -1,    90,    24,    91,    -1,
      93,    92,    -1,    -1,    92,    23,    93,    -1,    95,    94,
      -1,    -1,    94,    34,    95,    -1,    94,    35,    95,    -1,
      94,    36,    95,    -1,    94,    37,    95,    -1,    94,    38,
      95,    -1,    94,    39,    95,    -1,    43,    97,    96,    -1,
      44,    97,    96,    -1,    97,    96,    -1,    -1,    96,    43,
      97,    -1,    96,    44,    97,    -1,    99,    98,    -1,    -1,
      98,    45,    99,    -1,    98,    52,    99,    -1,    98,    53,
      99,    -1,   100,    -1,    54,   100,    -1,     7,    -1,     8,
      -1,     9,    -1,     4,    -1,   101,    -1,    22,    70,    48,
      87,    49,    -1,    46,    87,    47,    -1,   103,   102,   103,
      -1,     3,    -1,     3,    48,    87,    49,    -1,     3,    46,
     104,    47,    -1,     3,    46,    47,    -1,    -1,    30,    -1,
      31,    -1,   105,    -1,    87,    -1,   105,    41,    87,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    78,    78,    81,    82,    83,    84,    85,    86,    89,
      92,    93,    96,    97,    98,    99,   100,   103,   106,   107,
     110,   111,   112,   113,   116,   120,   124,   125,   126,   127,
     130,   131,   134,   135,   138,   139,   140,   141,   144,   145,
     146,   149,   152,   153,   154,   155,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   170,   173,   176,   179,
     182,   183,   186,   189,   192,   195,   198,   199,   202,   203,
     204,   207,   210,   211,   214,   217,   218,   219,   220,   221,
     222,   223,   226,   229,   230,   233,   236,   237,   240,   243,
     244,   245,   246,   247,   248,   249,   252,   253,   254,   257,
     258,   259,   262,   265,   266,   267,   268,   271,   272,   275,
     276,   277,   278,   279,   280,   281,   284,   288,   289,   290,
     291,   294,   295,   296,   299,   302,   303
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENT", "NUMBER", "STRING", "CONST",
  "FALSE", "TRUE", "NULLPTR", "VOID", "BOOL", "INT", "IF", "ELSE", "WHILE",
  "BREAK", "CIN", "COUT", "ENDL", "DELETE", "RETURN", "NEW", "LOGICALAND",
  "LOGICALOR", "ADDASSIGN", "SUBTRACTASSIGN", "MULTIPLYASSIGN",
  "DIVIDEASSIGN", "MODULOASSIGN", "OPINCREMENT", "OPDECREMENT",
  "OPSHIFTLEFT", "OPSHIFTRIGHT", "OPEQUAL", "OPNOTEQUAL", "OPLESS",
  "OPLESSEQUAL", "OPGREATER", "OPGREATEREQUAL", "';'", "','", "'='", "'+'",
  "'-'", "'*'", "'('", "')'", "'['", "']'", "'{'", "'}'", "'/'", "'%'",
  "'!'", "$accept", "MiniCpp", "MiniCppList", "ConstDef", "IdentList",
  "Init", "VarDef", "VarDefIdentList", "VarDefIdent", "FuncDecl",
  "FuncDef", "FuncHead", "FormParList", "TypeIdentList", "TypeIdent",
  "Type", "Block", "BlockList", "Stat", "EmptyStat", "BlockStat",
  "ExprStat", "IfStat", "StatList", "WhileStat", "BreakStat", "InputStat",
  "OutputStat", "CoutRightList", "CoutRight", "DeleteStat", "ReturnStat",
  "Expr", "OrExprList", "OrExpr", "AndExprList", "AndExpr", "RelExprList",
  "RelExpr", "SimpleExprList", "SimpleExpr", "TermList", "Term",
  "NotFactList", "NotFact", "Fact", "DudeWtf", "WeirdIdentStuff",
  "OptDecrOrIncr", "ActParList", "ExprList", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      59,    44,    61,    43,    45,    42,    40,    41,    91,    93,
     123,   125,    47,    37,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    57,    57,    57,    57,    58,
      59,    59,    60,    60,    60,    60,    60,    61,    62,    62,
      63,    63,    63,    63,    64,    65,    66,    66,    66,    66,
      67,    67,    68,    68,    69,    69,    69,    69,    70,    70,
      70,    71,    72,    72,    72,    72,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    74,    75,    76,    77,
      78,    78,    79,    80,    81,    82,    83,    83,    84,    84,
      84,    85,    86,    86,    87,    88,    88,    88,    88,    88,
      88,    88,    89,    90,    90,    91,    92,    92,    93,    94,
      94,    94,    94,    94,    94,    94,    95,    95,    95,    96,
      96,    96,    97,    98,    98,    98,    98,    99,    99,   100,
     100,   100,   100,   100,   100,   100,   101,   102,   102,   102,
     102,   103,   103,   103,   104,   105,   105
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     2,     2,     2,     6,
       0,     4,     2,     2,     2,     3,     3,     4,     0,     3,
       3,     1,     2,     2,     2,     2,     5,     4,     5,     6,
       1,     2,     0,     3,     5,     3,     4,     2,     1,     1,
       1,     3,     0,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     6,
       0,     3,     4,     2,     4,     4,     0,     2,     2,     2,
       2,     5,     2,     3,     2,     0,     3,     3,     3,     3,
       3,     3,     2,     0,     3,     2,     0,     3,     2,     0,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     0,
       3,     3,     2,     0,     3,     3,     3,     1,     2,     1,
       1,     1,     1,     1,     5,     3,     3,     1,     4,     4,
       3,     0,     1,     1,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,     0,    38,    39,    40,     8,     4,
       5,     6,     7,     0,     0,     0,    24,    42,    25,    21,
       0,    18,     0,   121,     0,     0,    23,    22,     0,    10,
     112,   109,   110,   111,     0,     0,     0,     0,     0,     0,
     121,     0,   122,   123,    56,   121,   121,   121,    41,   121,
      43,    44,     0,    57,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     0,    75,    83,    86,    89,
      99,   103,   107,   113,     0,    12,    13,    14,     0,     0,
      38,    27,     0,    32,     0,     0,    20,    17,     0,     0,
     121,   121,    63,     0,   121,    66,     0,    72,     0,     0,
      99,    99,     0,   108,    21,     0,    58,    74,    82,    85,
      88,    98,   102,   117,   121,    15,    16,    28,    31,    37,
       0,    26,     0,    19,     9,     0,     0,     0,     0,    69,
      70,    68,     0,     0,    73,   121,    96,    97,   115,    22,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   116,     0,     0,    35,    29,     0,   121,    62,    64,
      65,    67,     0,     0,    77,    78,    79,    80,    81,    76,
      84,    87,    90,    91,    92,    93,    94,    95,   100,   101,
     104,   105,   106,   120,   125,     0,   124,     0,    33,    36,
       0,    11,    60,    71,   114,   119,   121,   118,    34,    59,
     126,   121,    61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     9,    89,    26,    10,    28,    21,    11,
      12,    13,    82,   118,    83,    84,    53,    23,    54,    55,
      56,    57,    58,   209,    59,    60,    61,    62,   132,    95,
      63,    64,    65,   107,    66,   108,    67,   109,    68,   110,
      69,   111,    70,   112,    71,    72,    73,   114,    74,   195,
     196
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -164
static const yytype_int16 yypact[] =
{
    -164,    28,    26,  -164,    97,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,    21,     2,    54,  -164,  -164,  -164,     0,
      69,  -164,    32,     9,     1,    23,  -164,    16,   -29,  -164,
    -164,  -164,  -164,  -164,    50,    67,    43,    61,    95,   101,
     124,    97,  -164,  -164,  -164,   213,   213,   172,  -164,   220,
    -164,  -164,    11,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,   110,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,   132,  -164,  -164,  -164,   147,   148,
     106,  -164,   109,  -164,    20,    87,  -164,  -164,    11,    48,
     172,   172,  -164,   155,   117,  -164,   113,  -164,   119,   127,
    -164,  -164,   118,  -164,    32,   174,  -164,   115,   158,   160,
     154,    58,    40,    -5,    99,  -164,  -164,  -164,   143,   137,
     183,  -164,   150,  -164,  -164,   195,   152,   153,   161,  -164,
    -164,  -164,    47,   201,  -164,   172,    58,    58,  -164,    32,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   213,   213,   213,   213,   213,   165,
     172,  -164,    97,   156,   159,  -164,    32,    60,  -164,  -164,
    -164,  -164,   166,   164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,   163,   173,   176,  -164,  -164,
     181,  -164,  -164,  -164,  -164,  -164,   172,  -164,  -164,   209,
    -164,    60,  -164
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -164,  -164,  -164,   208,  -164,   -21,   210,  -164,   144,  -164,
    -164,  -164,   149,  -164,    83,    82,   233,  -164,  -163,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,   116,
    -164,  -164,   -40,  -164,    96,  -164,   103,  -164,   100,  -164,
     104,    37,   -43,  -164,   -41,   211,  -164,  -164,   151,  -164,
    -164
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -31
static const yytype_int16 yytable[] =
{
      98,    29,   100,   101,   202,    19,    86,   102,    75,    76,
      77,    87,    88,    30,   104,     4,    31,    32,    33,     5,
       6,     7,    34,   119,    35,    36,    37,    38,     3,    39,
      40,    41,     4,    80,     6,     7,     5,     6,     7,    42,
      43,   159,    24,   160,    78,    79,    25,    20,   212,    44,
     126,   127,    45,    46,   131,    47,   105,    22,    24,    17,
      48,    16,    85,    49,    30,   120,     8,    31,    32,    33,
      81,    17,    27,    34,    24,    35,    36,    37,    38,    94,
      39,    40,    41,    92,    14,   156,    15,   170,   124,   125,
      42,    43,   157,   158,    93,   173,    90,    80,     6,     7,
      44,   154,   155,    45,    46,    52,    47,     5,     6,     7,
      17,   188,   189,    91,    49,   190,   191,   192,    86,   194,
     197,    30,   129,    99,    31,    32,    33,    94,    30,    42,
      43,    31,    32,    33,   121,   113,   130,   136,   137,    41,
     140,   141,   142,   143,   144,   201,    41,    42,    43,    96,
     106,   115,   116,   -30,    42,    43,   117,   145,   128,   134,
      45,    46,   133,    47,    97,   138,   210,    45,    46,    30,
      47,    49,    31,    32,    33,   135,    30,   139,    49,    31,
      32,    33,   146,   147,   162,   163,   164,    41,   148,   149,
     150,   151,   152,   153,    41,    42,    43,   165,   166,   167,
     168,   169,    42,    43,   172,   199,   203,   200,    45,    46,
     205,    47,   193,   204,   206,    45,    46,    30,    47,    49,
      31,    32,    33,   211,    30,   207,    49,    31,    32,    33,
     208,    50,   123,    51,   122,    41,   174,   175,   176,   177,
     178,   179,    41,    42,    43,   198,    18,   181,   171,   180,
      42,    43,   182,   183,   184,   185,   186,   187,     0,    47,
     103,     0,     0,     0,     0,   161,    47,    49
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-164)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      40,    22,    45,    46,   167,     3,    27,    47,     7,     8,
       9,    40,    41,     4,     3,     6,     7,     8,     9,    10,
      11,    12,    13,     3,    15,    16,    17,    18,     0,    20,
      21,    22,     6,    10,    11,    12,    10,    11,    12,    30,
      31,    46,    42,    48,    43,    44,    46,    45,   211,    40,
      90,    91,    43,    44,    94,    46,    45,     3,    42,    50,
      51,    40,    46,    54,     4,    45,    40,     7,     8,     9,
      47,    50,     3,    13,    42,    15,    16,    17,    18,    32,
      20,    21,    22,    40,     2,    45,     4,    40,    40,    41,
      30,    31,    52,    53,    33,   135,    46,    10,    11,    12,
      40,    43,    44,    43,    44,    23,    46,    10,    11,    12,
      50,   154,   155,    46,    54,   156,   157,   158,   139,   159,
     160,     4,     5,    41,     7,     8,     9,    32,     4,    30,
      31,     7,     8,     9,    47,     3,    19,   100,   101,    22,
      25,    26,    27,    28,    29,   166,    22,    30,    31,    48,
      40,     4,     4,    47,    30,    31,    47,    42,     3,    40,
      43,    44,    49,    46,    40,    47,   206,    43,    44,     4,
      46,    54,     7,     8,     9,    48,     4,     3,    54,     7,
       8,     9,    24,    23,    41,    48,     3,    22,    34,    35,
      36,    37,    38,    39,    22,    30,    31,    47,     3,    47,
      47,    40,    30,    31,     3,    49,    40,    48,    43,    44,
      47,    46,    47,    49,    41,    43,    44,     4,    46,    54,
       7,     8,     9,    14,     4,    49,    54,     7,     8,     9,
      49,    23,    88,    23,    85,    22,   140,   141,   142,   143,
     144,   145,    22,    30,    31,   162,    13,   147,   132,   146,
      30,    31,   148,   149,   150,   151,   152,   153,    -1,    46,
      49,    -1,    -1,    -1,    -1,   114,    46,    54
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    56,    57,     0,     6,    10,    11,    12,    40,    58,
      61,    64,    65,    66,    70,    70,    40,    50,    71,     3,
      45,    63,     3,    72,    42,    46,    60,     3,    62,    60,
       4,     7,     8,     9,    13,    15,    16,    17,    18,    20,
      21,    22,    30,    31,    40,    43,    44,    46,    51,    54,
      58,    61,    70,    71,    73,    74,    75,    76,    77,    79,
      80,    81,    82,    85,    86,    87,    89,    91,    93,    95,
      97,    99,   100,   101,   103,     7,     8,     9,    43,    44,
      10,    47,    67,    69,    70,    46,    60,    40,    41,    59,
      46,    46,    40,    33,    32,    84,    48,    40,    87,    70,
      97,    97,    87,   100,     3,    45,    40,    88,    90,    92,
      94,    96,    98,     3,   102,     4,     4,    47,    68,     3,
      45,    47,    67,    63,    40,    41,    87,    87,     3,     5,
      19,    87,    83,    49,    40,    48,    96,    96,    47,     3,
      25,    26,    27,    28,    29,    42,    24,    23,    34,    35,
      36,    37,    38,    39,    43,    44,    45,    52,    53,    46,
      48,   103,    41,    48,     3,    47,     3,    47,    47,    40,
      40,    84,     3,    87,    89,    89,    89,    89,    89,    89,
      91,    93,    95,    95,    95,    95,    95,    95,    97,    97,
      99,    99,    99,    47,    87,   104,   105,    87,    69,    49,
      48,    60,    73,    40,    49,    47,    41,    49,    49,    78,
      87,    14,    73
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 78 "MiniCpp.y"
    { printf("digraph program {\n\tfontname=\"Helvetica,Arial,sans-serif\"\n\tnode [fontname=\"Helvetica,Arial,sans-serif\"]\n\tedge [fontname=\"Helvetica,Arial,sans-serif\"]\n\trankdir=LR;\n\tnode [shape = box];\n%s\n}", currGraphBody); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 120 "MiniCpp.y"
    { addEdges((yyvsp[(1) - (2)].iIdent)); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 124 "MiniCpp.y"
    { (yyval.iIdent) = (yyvsp[(3) - (5)].iIdent); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 125 "MiniCpp.y"
    { (yyval.iIdent) = (yyvsp[(2) - (4)].iIdent); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 126 "MiniCpp.y"
    { (yyval.iIdent) = (yyvsp[(2) - (5)].iIdent); }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 127 "MiniCpp.y"
    { (yyval.iIdent) = (yyvsp[(3) - (6)].iIdent); }
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 290 "MiniCpp.y"
    { addCalledFunc((yyvsp[(1) - (4)].iIdent)); }
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 291 "MiniCpp.y"
    { addCalledFunc((yyvsp[(1) - (3)].iIdent)); }
    break;


/* Line 1792 of yacc.c  */
#line 1663 "MiniCpp.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 306 "MiniCpp.y"

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