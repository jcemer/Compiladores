/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDF = 258,
     INT = 259,
     DOUBLE = 260,
     REAL = 261,
     CHAR = 262,
     QUOTE = 263,
     LE = 264,
     GE = 265,
     EQ = 266,
     NE = 267,
     AND = 268,
     OR = 269,
     NOT = 270,
     IF = 271,
     THEN = 272,
     ELSE = 273,
     WHILE = 274,
     INT_LIT = 275,
     F_LIT = 276,
     END = 277,
     TRUE = 278,
     FALSE = 279,
     STRING = 280,
     CONST = 281,
     STR_LIT = 282,
     PRINTF = 283
   };
#endif
/* Tokens.  */
#define IDF 258
#define INT 259
#define DOUBLE 260
#define REAL 261
#define CHAR 262
#define QUOTE 263
#define LE 264
#define GE 265
#define EQ 266
#define NE 267
#define AND 268
#define OR 269
#define NOT 270
#define IF 271
#define THEN 272
#define ELSE 273
#define WHILE 274
#define INT_LIT 275
#define F_LIT 276
#define END 277
#define TRUE 278
#define FALSE 279
#define STRING 280
#define CONST 281
#define STR_LIT 282
#define PRINTF 283




/* Copy the first part of user declarations.  */
#line 2 "pico.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdarg.h>

    #include "node.h"
    #include "symbol_table.c"
    #include "lista.c"
    #include "attr.h"

    Node* syntax_tree = NULL;
    symbol_t s_table;
    int desloc = 0;

    #define UNDEFINED_SYMBOL_ERROR -21
    #define TYPE_MISMATCH_ERROR -20
    #define ARRAY_DIM_ERROR -22
    #define NOT_ARRAY_ERROR - 23
    #define GET_ERROR 1

    #define SP "SP"
    #define RX "Rx"

    const char * itoa(int);
    void address(char **, int, char *);

    void insert_nodes(Node *, Node *);
    int operation(attr_expr **, char *, attr_expr *, attr_expr *);
    int rx_temp(int type);

    int errorValue;
    int error(int);
    int error_undeclared(char *);
    int error_array(int, char *);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 39 "pico.y"
{
  struct _node * no;
  char* string;
}
/* Line 193 of yacc.c.  */
#line 194 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 219 "y.tab.c"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  35
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   162

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNRULES -- Number of states.  */
#define YYNSTATES  119

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      36,    37,    31,    29,    35,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    34,    33,
      44,    38,    43,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      25,    26,    27,    28
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     8,    11,    15,    19,    21,    25,
      27,    29,    31,    33,    35,    37,    42,    47,    52,    57,
      61,    67,    70,    74,    78,    80,    82,    87,    89,    93,
      97,   101,   105,   109,   113,   115,   117,   119,   121,   126,
     128,   133,   141,   149,   151,   155,   157,   159,   163,   167,
     171,   174,   178,   182,   186,   190,   194
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,    47,    54,    -1,    54,    -1,    48,    33,
      -1,    47,    48,    33,    -1,    50,    34,    49,    -1,     3,
      -1,     3,    35,    49,    -1,    51,    -1,    52,    -1,     4,
      -1,     5,    -1,     6,    -1,     7,    -1,     4,    36,    53,
      37,    -1,     5,    36,    53,    37,    -1,     6,    36,    53,
      37,    -1,     7,    36,    53,    37,    -1,    20,    34,    20,
      -1,    20,    34,    20,    35,    53,    -1,    55,    33,    -1,
      55,    33,    54,    -1,    56,    38,    58,    -1,    60,    -1,
       3,    -1,     3,    39,    57,    40,    -1,    58,    -1,    58,
      35,    57,    -1,    58,    29,    58,    -1,    58,    30,    58,
      -1,    58,    31,    58,    -1,    58,    32,    58,    -1,    36,
      58,    37,    -1,    20,    -1,    21,    -1,    56,    -1,    59,
      -1,     3,    36,    57,    37,    -1,    58,    -1,    28,    36,
      58,    37,    -1,    16,    36,    62,    37,    17,    54,    61,
      -1,    19,    36,    62,    37,    41,    54,    42,    -1,    22,
      -1,    18,    54,    22,    -1,    23,    -1,    24,    -1,    36,
      62,    37,    -1,    62,    13,    62,    -1,    62,    14,    62,
      -1,    15,    62,    -1,    58,    43,    58,    -1,    58,    44,
      58,    -1,    58,     9,    58,    -1,    58,    10,    58,    -1,
      58,    11,    58,    -1,    58,    12,    58,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   104,   104,   108,   114,   117,   123,   130,   133,   139,
     144,   152,   159,   166,   173,   183,   195,   207,   219,   234,
     248,   271,   275,   287,   302,   309,   321,   379,   388,   406,
     411,   416,   421,   426,   430,   438,   446,   450,   456,   462,
     469,   477,   480,   486,   489,   495,   498,   501,   504,   507,
     510,   513,   516,   519,   522,   525,   528
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDF", "INT", "DOUBLE", "REAL", "CHAR",
  "QUOTE", "LE", "GE", "EQ", "NE", "AND", "OR", "NOT", "IF", "THEN",
  "ELSE", "WHILE", "INT_LIT", "F_LIT", "END", "TRUE", "FALSE", "STRING",
  "CONST", "STR_LIT", "PRINTF", "'+'", "'-'", "'*'", "'/'", "';'", "':'",
  "','", "'('", "')'", "'='", "'['", "']'", "'{'", "'}'", "'>'", "'<'",
  "$accept", "code", "declaracoes", "declaracao", "listadeclaracao",
  "tipo", "tipounico", "tipolista", "listadupla", "acoes", "comando",
  "lvalue", "listaexpr", "expr", "chamaproc", "enunciado",
  "fiminstcontrole", "expbool", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    43,
      45,    42,    47,    59,    58,    44,    40,    41,    61,    91,
      93,   123,   125,    62,    60
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    46,    47,    47,    48,    49,    49,    50,
      50,    51,    51,    51,    51,    52,    52,    52,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    57,    57,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    59,    60,
      60,    60,    60,    61,    61,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     3,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     3,
       5,     2,     3,     3,     1,     1,     4,     1,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     4,     1,
       4,     7,     7,     1,     3,     1,     1,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    25,    11,    12,    13,    14,     0,     0,    34,    35,
       0,     0,     0,     0,     0,     0,     9,    10,     3,     0,
      36,    39,    37,    24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,     0,     1,     0,     2,     4,     0,
      21,     0,     0,     0,     0,     0,     0,    27,     0,     0,
       0,     0,     0,     0,     0,    45,    46,     0,     0,     0,
       0,     0,    33,     5,     7,     6,    22,    23,    29,    30,
      31,    32,    38,     0,    26,     0,    15,    16,    17,    18,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    40,     0,    28,    19,    47,    53,    54,
      55,    56,    51,    52,    48,    49,     0,     0,     8,     0,
       0,     0,    20,     0,    43,    41,    42,     0,    44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    12,    13,    14,    65,    15,    16,    17,    50,    18,
      19,    33,    46,    21,    22,    23,   115,    59
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -31
static const yytype_int16 yypact[] =
{
     119,    12,   -30,   -22,   -14,    -7,     3,     5,   -31,   -31,
      16,    57,    64,   119,   -21,    20,   -31,   -31,   -31,    -2,
      19,    79,   -31,   -31,    57,    57,    50,    50,    50,    50,
      66,    66,    57,   -31,    68,   -31,    38,   -31,   -31,    76,
     125,    57,    57,    57,    57,    57,    43,   127,    42,    49,
      55,    59,    75,    90,    66,   -31,   -31,    66,    15,    -5,
      -3,   100,   -31,   -31,    98,   -31,   -31,    79,   -11,   -11,
     -31,   -31,   -31,    57,   -31,    83,   -31,   -31,   -31,   -31,
     -31,     6,    54,    57,    57,    57,    57,    57,    57,    66,
      66,   117,    95,   -31,    76,   -31,   107,   -31,    79,    79,
      79,    79,    79,    79,   -31,   130,   125,   125,   -31,    50,
       1,   106,   -31,   125,   -31,   -31,   -31,   128,   -31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -31,   -31,   -31,   136,    58,   -31,   -31,   -31,   -25,   -12,
     -31,     0,   -20,    31,   -31,   -31,   -31,   -24
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      20,    37,    51,    52,    53,    48,    26,    60,    89,    90,
      89,    90,    38,    20,    27,    83,    84,    85,    86,   113,
      44,    45,    28,   114,    83,    84,    85,    86,    66,    29,
      80,    40,    91,    82,    92,    42,    43,    44,    45,    30,
      20,    31,    34,    62,    42,    43,    44,    45,    24,    87,
      88,    25,    32,    95,    39,    47,    47,    41,    87,    88,
       1,    58,    58,    61,    35,   104,   105,    89,    90,     1,
      49,    63,    67,    68,    69,    70,    71,     8,     9,    64,
      72,    54,    74,    75,   112,    58,     8,     9,    81,    55,
      56,    97,    76,    11,   110,   111,    77,    42,    43,    44,
      45,   117,    57,    96,    47,    62,    20,    20,    42,    43,
      44,    45,    78,    20,    98,    99,   100,   101,   102,   103,
      58,    58,     1,     2,     3,     4,     5,    79,     1,    42,
      43,    44,    45,    94,   106,     6,   107,    93,     7,     8,
       9,     6,   109,    89,     7,     8,     9,    10,   116,    36,
     118,     0,   108,    10,     0,    11,    42,    43,    44,    45,
       0,    11,    73
};

static const yytype_int8 yycheck[] =
{
       0,    13,    27,    28,    29,    25,    36,    31,    13,    14,
      13,    14,    33,    13,    36,     9,    10,    11,    12,    18,
      31,    32,    36,    22,     9,    10,    11,    12,    40,    36,
      54,    33,    37,    57,    37,    29,    30,    31,    32,    36,
      40,    36,    11,    37,    29,    30,    31,    32,    36,    43,
      44,    39,    36,    73,    34,    24,    25,    38,    43,    44,
       3,    30,    31,    32,     0,    89,    90,    13,    14,     3,
      20,    33,    41,    42,    43,    44,    45,    20,    21,     3,
      37,    15,    40,    34,   109,    54,    20,    21,    57,    23,
      24,    37,    37,    36,   106,   107,    37,    29,    30,    31,
      32,   113,    36,    20,    73,    37,   106,   107,    29,    30,
      31,    32,    37,   113,    83,    84,    85,    86,    87,    88,
      89,    90,     3,     4,     5,     6,     7,    37,     3,    29,
      30,    31,    32,    35,    17,    16,    41,    37,    19,    20,
      21,    16,    35,    13,    19,    20,    21,    28,    42,    13,
      22,    -1,    94,    28,    -1,    36,    29,    30,    31,    32,
      -1,    36,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    16,    19,    20,    21,
      28,    36,    46,    47,    48,    50,    51,    52,    54,    55,
      56,    58,    59,    60,    36,    39,    36,    36,    36,    36,
      36,    36,    36,    56,    58,     0,    48,    54,    33,    34,
      33,    38,    29,    30,    31,    32,    57,    58,    57,    20,
      53,    53,    53,    53,    15,    23,    24,    36,    58,    62,
      62,    58,    37,    33,     3,    49,    54,    58,    58,    58,
      58,    58,    37,    35,    40,    34,    37,    37,    37,    37,
      62,    58,    62,     9,    10,    11,    12,    43,    44,    13,
      14,    37,    37,    37,    35,    57,    20,    37,    58,    58,
      58,    58,    58,    58,    62,    62,    17,    41,    49,    35,
      54,    54,    53,    18,    22,    61,    42,    54,    22
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 104 "pico.y"
    {
        syntax_tree = (yyval.no) = create_node((yylsp[(1) - (2)]).first_line, nodo_programa, "code", (yyvsp[(1) - (2)].no), (yyvsp[(2) - (2)].no), NULL, NULL);
        (yyval.no)->attribute = (yyvsp[(2) - (2)].no)->attribute;
    }
    break;

  case 3:
#line 108 "pico.y"
    { 
        syntax_tree = (yyval.no) = (yyvsp[(1) - (1)].no);
    }
    break;

  case 4:
#line 114 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (2)]).first_line, nodo_declaracoes, "declaracoes", (yyvsp[(1) - (2)].no), coringa(";"), NULL, NULL); 
    }
    break;

  case 5:
#line 117 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (3)]).first_line, nodo_declaracoes, "declaracoes", (yyvsp[(1) - (3)].no), (yyvsp[(2) - (3)].no), coringa(";"), NULL, NULL);
    }
    break;

  case 6:
#line 123 "pico.y"
    {
        insert_nodes((Node *)(yyvsp[(1) - (3)].no), (Node *)(yyvsp[(3) - (3)].no));
        (yyval.no) = create_node((yylsp[(1) - (3)]).first_line, nodo_declaracao, "declaracao", (yyvsp[(1) - (3)].no), coringa(":"), (yyvsp[(3) - (3)].no), NULL, NULL);
    }
    break;

  case 7:
#line 130 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, nodo_idf, (yyvsp[(1) - (1)].string), NULL, NULL);
    }
    break;

  case 8:
#line 133 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (3)]).first_line, nodo_listadeclaracao, "listadeclaracao", create_node((yylsp[(1) - (3)]).first_line, nodo_idf, (yyvsp[(1) - (3)].string), NULL, NULL), coringa(","), (yyvsp[(3) - (3)].no), NULL, NULL);
    }
    break;

  case 9:
#line 139 "pico.y"
    {
        //$$ = create_node(@1.first_line, nodo_tipo, "tipo", $1, NULL, NULL);
        //$$->attribute = $1->attribute;
        (yyval.no) = (yyvsp[(1) - (1)].no);
    }
    break;

  case 10:
#line 144 "pico.y"
    {
        //$$ = create_node(@1.first_line, nodo_tipo, "tipo", $1, NULL, NULL);
        //$$->attribute = $1->attribute;
        (yyval.no) = (yyvsp[(1) - (1)].no);   
    }
    break;

  case 11:
#line 152 "pico.y"
    {
        attr_tipounico * at = malloc(sizeof(attr_tipounico));
        at->type = INT_TYPE;
        at->size = INT_SIZE;
        (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, nodo_tipounico, "int", NULL, NULL);
        (yyval.no)->attribute = at;
    }
    break;

  case 12:
#line 159 "pico.y"
    {
        attr_tipounico * at = malloc(sizeof(attr_tipounico));
        at->type = DOUBLE_TYPE;
        at->size = DOUBLE_SIZE;
        (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, nodo_tipounico, "double", NULL, NULL);
        (yyval.no)->attribute = at;
    }
    break;

  case 13:
#line 166 "pico.y"
    {
        attr_tipounico * at = malloc(sizeof(attr_tipounico));
        at->type = REAL_TYPE;
        at->size = REAL_SIZE;
        (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, nodo_tipounico, "real", NULL, NULL);
        (yyval.no)->attribute = at;
    }
    break;

  case 14:
#line 173 "pico.y"
    {
        attr_tipounico * at = malloc(sizeof(attr_tipounico));
        at->type = CHAR_TYPE;
        at->size = CHAR_SIZE;
        (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, nodo_tipounico, "char", NULL, NULL);
        (yyval.no)->attribute = at;
    }
    break;

  case 15:
#line 183 "pico.y"
    {
        attr_tipolista * at = malloc(sizeof(attr_tipolista));
        attr_listadupla * at_inner = ((attr_listadupla *) (yyvsp[(3) - (4)].no)->attribute);

        at->type = INT_TYPE;
        at->type_size = INT_SIZE;
        at->size = at_inner->size * INT_SIZE;
        at->inner = at_inner;

        (yyval.no) = create_node((yylsp[(1) - (4)]).first_line, nodo_tipolista, "int", coringa("("), (yyvsp[(3) - (4)].no), coringa(")"), NULL, NULL);
        (yyval.no)->attribute = at;
    }
    break;

  case 16:
#line 195 "pico.y"
    {
        attr_tipolista * at = malloc(sizeof(attr_tipolista));
        attr_listadupla * at_inner = ((attr_listadupla *) (yyvsp[(3) - (4)].no)->attribute);

        at->type = DOUBLE_TYPE;
        at->type_size = DOUBLE_SIZE;
        at->size = at_inner->size * DOUBLE_SIZE;
        at->inner = at_inner;

        (yyval.no) = create_node((yylsp[(1) - (4)]).first_line, nodo_tipolista, "double", coringa("("), (yyvsp[(3) - (4)].no), coringa(")"), NULL, NULL);
        (yyval.no)->attribute = at;
    }
    break;

  case 17:
#line 207 "pico.y"
    {
        attr_tipolista * at = malloc(sizeof(attr_tipolista));
        attr_listadupla * at_inner = ((attr_listadupla *) (yyvsp[(3) - (4)].no)->attribute);

        at->type = REAL_TYPE;
        at->type_size = REAL_SIZE;
        at->size = at_inner->size * REAL_SIZE;
        at->inner = at_inner;

        (yyval.no) = create_node((yylsp[(1) - (4)]).first_line, nodo_tipolista, "real", coringa("("), (yyvsp[(3) - (4)].no), coringa(")"), NULL, NULL);
        (yyval.no)->attribute = at;    
    }
    break;

  case 18:
#line 219 "pico.y"
    {
        attr_tipolista * at = malloc(sizeof(attr_tipolista));
        attr_listadupla * at_inner = ((attr_listadupla *) (yyvsp[(3) - (4)].no)->attribute);

        at->type = CHAR_TYPE;
        at->type_size = CHAR_SIZE;
        at->size = at_inner->size * CHAR_SIZE;
        at->inner = at_inner;

        (yyval.no) = create_node((yylsp[(1) - (4)]).first_line, nodo_tipolista, "char", coringa("("), (yyvsp[(3) - (4)].no), coringa(")"), NULL, NULL);
        (yyval.no)->attribute = at;
    }
    break;

  case 19:
#line 234 "pico.y"
    {
        attr_listadupla * at = malloc(sizeof(attr_listadupla));

        at->lenght = 1;
        at->dim_init = malloc(sizeof(int));
        at->dim_size = malloc(sizeof(int));

        at->dim_init[0] = atoi((yyvsp[(1) - (3)].string));
        at->dim_size[0] = atoi((yyvsp[(3) - (3)].string)) - at->dim_init[0] + 1;
        at->size = at->dim_size[0];

        (yyval.no) = create_node((yylsp[(1) - (3)]).first_line, nodo_listadupla, "listadupla", create_node((yylsp[(1) - (3)]).first_line, nodo_int, (yyvsp[(1) - (3)].string), NULL, NULL), coringa(":"), create_node((yylsp[(1) - (3)]).first_line, nodo_int, (yyvsp[(3) - (3)].string), NULL, NULL), NULL, NULL);
        (yyval.no)->attribute = at;
    }
    break;

  case 20:
#line 248 "pico.y"
    {
        attr_listadupla * at = malloc(sizeof(attr_listadupla));
        attr_listadupla * at_last = ((attr_listadupla *) (yyvsp[(5) - (5)].no)->attribute);

        at->lenght = at_last->lenght + 1;
        at->dim_init = malloc(sizeof(int) * at->lenght);
        at->dim_size = malloc(sizeof(int) * at->lenght);

        at->dim_init[0] = atoi((yyvsp[(1) - (5)].string));
        at->dim_size[0] = atoi((yyvsp[(3) - (5)].string)) - at->dim_init[0] + 1;
        int i;
        for (i = 0; i < at_last->lenght; i++) {
            at->dim_init[i+1] = at_last->dim_init[i];
            at->dim_size[i+1] = at_last->dim_size[i];
        }
        at->size = at->dim_size[0] * at_last->size;

        (yyval.no) = create_node((yylsp[(1) - (5)]).first_line, nodo_listadupla, "listadupla", create_node((yylsp[(1) - (5)]).first_line, nodo_int, (yyvsp[(1) - (5)].string), NULL, NULL), coringa(":"), create_node((yylsp[(1) - (5)]).first_line, nodo_int, (yyvsp[(3) - (5)].string), NULL, NULL), coringa(","), (yyvsp[(5) - (5)].no), NULL, NULL);
        (yyval.no)->attribute = at;    
    }
    break;

  case 21:
#line 271 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (2)]).first_line, nodo_acoes, "acoes", (yyvsp[(1) - (2)].no), coringa(";"), NULL, NULL);
        (yyval.no)->attribute = (yyvsp[(1) - (2)].no)->attribute;
    }
    break;

  case 22:
#line 275 "pico.y"
    {
        attr * at = (attr *) malloc(sizeof(attr));
        at->code = NULL;
        cat_tac(&(at->code), &((attr *) (yyvsp[(1) - (3)].no)->attribute)->code);
        cat_tac(&(at->code), &((attr *) (yyvsp[(3) - (3)].no)->attribute)->code);

        (yyval.no) = create_node((yylsp[(1) - (3)]).first_line, nodo_acoes, "acoes", (yyvsp[(1) - (3)].no), coringa(";"), (yyvsp[(3) - (3)].no), NULL, NULL);
        (yyval.no)->attribute = at;
    }
    break;

  case 23:
#line 287 "pico.y"
    {
        attr * at = (attr *) malloc(sizeof(attr));
        attr_expr * left = ((attr_expr *) (yyvsp[(1) - (3)].no)->attribute);
        attr_expr * right = ((attr_expr *) (yyvsp[(3) - (3)].no)->attribute);

        if (left->type != right->type)
            return error(TYPE_MISMATCH_ERROR);

        at->code = left->code;
        cat_tac(&(at->code), &(right->code));
        append_inst_tac(&(at->code), create_inst_tac(left->value, right->value, ":=", ""));

        (yyval.no) = create_node((yylsp[(1) - (3)]).first_line, nodo_comando, "comando", (yyvsp[(1) - (3)].no), coringa("="), (yyvsp[(3) - (3)].no), NULL, NULL);
        (yyval.no)->attribute = at;
    }
    break;

  case 24:
#line 302 "pico.y"
    { 
        (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, nodo_comando, "comando", (yyvsp[(1) - (1)].no), NULL, NULL);
        (yyval.no)->attribute = (yyvsp[(1) - (1)].no)->attribute;
    }
    break;

  case 25:
#line 309 "pico.y"
    {
        attr_expr *at = malloc(sizeof(attr_expr));
        entry_t * e = lookup(s_table, (yyvsp[(1) - (1)].string));
        if (!e)
            return error_undeclared((yyvsp[(1) - (1)].string));
        address(&(at->value), e->desloc, SP);
        at->type = e->type;
        at->code = NULL;

        (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, nodo_idf, (yyvsp[(1) - (1)].string), NULL, NULL);
        (yyval.no)->attribute = at;
    }
    break;

  case 26:
#line 321 "pico.y"
    {
        attr_expr *at = malloc(sizeof(attr_expr));
        attr_listaexpr * at_lista = ((attr_listaexpr *) (yyvsp[(3) - (4)].no)->attribute);

        entry_t * e = lookup(s_table, (yyvsp[(1) - (4)].string));
        if (!e)
            return error_undeclared((yyvsp[(1) - (4)].string));
        at->type = e->type;
        at->code = NULL;

        // EXTRA
        entry_textra * e_extra = ((entry_textra *) e->extra);
        if (!e_extra)
            return error_array(NOT_ARRAY_ERROR, (yyvsp[(1) - (4)].string));
        if (at_lista->lenght > e_extra->lenght)
            return error_array(ARRAY_DIM_ERROR, (yyvsp[(1) - (4)].string));

        // CHECK LISTAEXPR: type and cat codes
        int i;
        for (i = 0; i < at_lista->lenght; i++) {
            if (at_lista->expr[i]->type != INT_TYPE)
                return error(TYPE_MISMATCH_ERROR);
            cat_tac(&(at->code), &(at_lista->expr[i]->code));
        }

        char * res;
        address(&res, rx_temp(INT_TYPE), RX);
        // e
        if (at_lista->lenght == 1)
            append_inst_tac(&(at->code), create_inst_tac(res, at_lista->expr[0]->value, ":=", ""));

        for (i = 1; i < at_lista->lenght; i++) {
            append_inst_tac(&(at->code), create_inst_tac(res, i == 1 ? at_lista->expr[0]->value : res, "MUL", itoa(e_extra->dim_size[i])));
            append_inst_tac(&(at->code), create_inst_tac(res, res, "ADD", at_lista->expr[i]->value));
        }
        // e * k
        append_inst_tac(&(at->code), create_inst_tac(res, res, "MUL", itoa(e_extra->type_size)));
        // e * k + c
        append_inst_tac(&(at->code), 
            create_inst_tac(res, res, e_extra->c > 0 ? "ADD" : "SUB", itoa(abs(e_extra->c)))
        );

        char * ret;
        address(&ret, rx_temp(INT_TYPE), RX);

        char * right = malloc(sizeof(char) * 17);
        strcpy(right, res);
        strcat(right, " (000(SP))");

        append_inst_tac(&(at->code), create_inst_tac(ret, right, ":=", ""));
        at->value = ret;

        (yyval.no) = create_node((yylsp[(1) - (4)]).first_line, nodo_lvalue, "lvalue", create_node((yylsp[(1) - (4)]).first_line, nodo_idf, (yyvsp[(1) - (4)].string), NULL, NULL), coringa("["), (yyvsp[(3) - (4)].no), coringa("]"), NULL, NULL);
        (yyval.no)->attribute = at;
    }
    break;

  case 27:
#line 379 "pico.y"
    {
        attr_listaexpr *at = malloc(sizeof(attr_listaexpr));
        at->lenght = 1;
        at->expr = malloc(sizeof(attr_expr *));
        at->expr[0] = (attr_expr *) (yyvsp[(1) - (1)].no)->attribute;

        (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, nodo_parametro, "listaexpr", (yyvsp[(1) - (1)].no), NULL, NULL);
        (yyval.no)->attribute = at;
    }
    break;

  case 28:
#line 388 "pico.y"
    {
        attr_listaexpr * at = malloc(sizeof(attr_listaexpr));
        attr_listaexpr * at_last = ((attr_listaexpr *) (yyvsp[(3) - (3)].no)->attribute);

        at->lenght = at_last->lenght + 1;
        at->expr = malloc(sizeof(attr_expr *) * at->lenght);
        
        at->expr[0] = (attr_expr *) (yyvsp[(1) - (3)].no)->attribute;
        int i;
        for (i = 0; i < at_last->lenght; i++) 
            at->expr[i+1] = at_last->expr[i];

        (yyval.no) = create_node((yylsp[(1) - (3)]).first_line, nodo_parametro, "listaexpr", (yyvsp[(1) - (3)].no), coringa(","), (yyvsp[(3) - (3)].no), NULL, NULL);
        (yyval.no)->attribute = at;
    }
    break;

  case 29:
#line 406 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (3)]).first_line, nodo_mais, "+", (yyvsp[(1) - (3)].no), coringa("+"), (yyvsp[(3) - (3)].no), NULL, NULL);
        if (operation((attr_expr **) &((yyval.no)->attribute), "ADD", (yyvsp[(1) - (3)].no)->attribute, (yyvsp[(3) - (3)].no)->attribute))
            return error(GET_ERROR);
    }
    break;

  case 30:
#line 411 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (3)]).first_line, nodo_menos, "-", (yyvsp[(1) - (3)].no), coringa("-"), (yyvsp[(3) - (3)].no), NULL, NULL);
        if (operation((attr_expr **) &((yyval.no)->attribute), "SUB", (yyvsp[(1) - (3)].no)->attribute, (yyvsp[(3) - (3)].no)->attribute))
            return error(GET_ERROR);
    }
    break;

  case 31:
#line 416 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (3)]).first_line, nodo_multiplicacao, "*", (yyvsp[(1) - (3)].no), coringa("*"), (yyvsp[(3) - (3)].no), NULL, NULL);
        if (operation((attr_expr **) &((yyval.no)->attribute), "MUL", (yyvsp[(1) - (3)].no)->attribute, (yyvsp[(3) - (3)].no)->attribute))
            return error(GET_ERROR);
    }
    break;

  case 32:
#line 421 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (3)]).first_line, nodo_divisao, "/", (yyvsp[(1) - (3)].no), coringa("/"), (yyvsp[(3) - (3)].no), NULL, NULL);
        if (operation((attr_expr **) &((yyval.no)->attribute), "DIV", (yyvsp[(1) - (3)].no)->attribute, (yyvsp[(3) - (3)].no)->attribute))
            return error(GET_ERROR);
    }
    break;

  case 33:
#line 426 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (3)]).first_line, nodo_expressao, "()", coringa("("), (yyvsp[(2) - (3)].no), coringa(")"), NULL, NULL);
        (yyval.no)->attribute = (yyvsp[(2) - (3)].no)->attribute;
    }
    break;

  case 34:
#line 430 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, nodo_int, (yyvsp[(1) - (1)].string), NULL, NULL);
        attr_expr * at = malloc(sizeof(attr_expr));
        at->value = (yyvsp[(1) - (1)].string);
        at->type = INT_TYPE;
        at->code = NULL;
        (yyval.no)->attribute = at;
    }
    break;

  case 35:
#line 438 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, nodo_float, (yyvsp[(1) - (1)].string), NULL, NULL);
        attr_expr * at = malloc(sizeof(attr_expr));
        at->value = (yyvsp[(1) - (1)].string);
        at->type = REAL_TYPE;
        at->code = NULL;
        (yyval.no)->attribute = at;
    }
    break;

  case 36:
#line 446 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, nodo_expr, "expr", (yyvsp[(1) - (1)].no), NULL, NULL);
        (yyval.no)->attribute = (yyvsp[(1) - (1)].no)->attribute;
    }
    break;

  case 37:
#line 450 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, nodo_expr, "expr", (yyvsp[(1) - (1)].no), NULL, NULL);
    }
    break;

  case 38:
#line 456 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (4)]).first_line, nodo_proc, "chamaproc", create_node((yylsp[(1) - (4)]).first_line, nodo_idf, (yyvsp[(1) - (4)].string), NULL, NULL), coringa("("), (yyvsp[(3) - (4)].no), coringa(")"), NULL, NULL);
    }
    break;

  case 39:
#line 462 "pico.y"
    {
        attr * at = (attr *) malloc(sizeof(attr));
        at->code = ((attr_expr *) (yyvsp[(1) - (1)].no)->attribute)->code;

        (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, nodo_expr, "expr", (yyvsp[(1) - (1)].no), NULL, NULL);
        (yyval.no)->attribute = at;
    }
    break;

  case 40:
#line 469 "pico.y"
    {
        attr * at = (attr *) malloc(sizeof(attr));
        at->code = ((attr_expr *) (yyvsp[(3) - (4)].no)->attribute)->code;
        append_inst_tac(&(at->code), create_inst_tac("", "", "PRINT", ((attr_expr *) (yyvsp[(3) - (4)].no)->attribute)->value));

        (yyval.no) = create_node((yylsp[(1) - (4)]).first_line, nodo_printf, "print", (yyvsp[(3) - (4)].no), NULL, NULL);
        (yyval.no)->attribute = at;
    }
    break;

  case 41:
#line 477 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (7)]).first_line, nodo_if, "if", coringa("("), (yyvsp[(3) - (7)].no), coringa(")"), coringa("then"), (yyvsp[(6) - (7)].no), (yyvsp[(7) - (7)].no), NULL, NULL);
    }
    break;

  case 42:
#line 480 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (7)]).first_line, nodo_while, "while", coringa("("), (yyvsp[(3) - (7)].no), coringa(")"), coringa("{"), (yyvsp[(6) - (7)].no), coringa("}"), NULL, NULL);
    }
    break;

  case 43:
#line 486 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, nodo_end, "end", NULL, NULL);
    }
    break;

  case 44:
#line 489 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (3)]).first_line, nodo_else, "else", (yyvsp[(2) - (3)].no), create_node((yylsp[(1) - (3)]).first_line, nodo_end, "end", NULL, NULL), NULL, NULL);
    }
    break;

  case 45:
#line 495 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, nodo_true, "true", NULL, NULL);
    }
    break;

  case 46:
#line 498 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (1)]).first_line, nodo_false, "false", NULL, NULL);
    }
    break;

  case 47:
#line 501 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (3)]).first_line, nodo_expressao, "()", coringa("("), (yyvsp[(2) - (3)].no), coringa(")"), NULL, NULL);
    }
    break;

  case 48:
#line 504 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (3)]).first_line, nodo_and, "and", (yyvsp[(1) - (3)].no), coringa("&"), (yyvsp[(3) - (3)].no), NULL, NULL);
    }
    break;

  case 49:
#line 507 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (3)]).first_line, nodo_or, "or", (yyvsp[(1) - (3)].no), coringa("|"), (yyvsp[(3) - (3)].no), NULL, NULL);
    }
    break;

  case 50:
#line 510 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (2)]).first_line, nodo_not, "not", coringa("!"), (yyvsp[(2) - (2)].no), NULL, NULL);
    }
    break;

  case 51:
#line 513 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (3)]).first_line, nodo_sup, "sup", (yyvsp[(1) - (3)].no), coringa(">"), (yyvsp[(3) - (3)].no), NULL, NULL);
    }
    break;

  case 52:
#line 516 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (3)]).first_line, nodo_inf, "inf", (yyvsp[(1) - (3)].no), coringa("<"),(yyvsp[(3) - (3)].no), NULL, NULL);
    }
    break;

  case 53:
#line 519 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (3)]).first_line, nodo_le, "le", (yyvsp[(1) - (3)].no), coringa("<="), (yyvsp[(3) - (3)].no), NULL, NULL);
    }
    break;

  case 54:
#line 522 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (3)]).first_line, nodo_ge, "ge", (yyvsp[(1) - (3)].no), coringa(">="), (yyvsp[(3) - (3)].no), NULL, NULL);
    }
    break;

  case 55:
#line 525 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (3)]).first_line, nodo_eq, "eq", (yyvsp[(1) - (3)].no), coringa("=="), (yyvsp[(3) - (3)].no), NULL, NULL);
    }
    break;

  case 56:
#line 528 "pico.y"
    {
        (yyval.no) = create_node((yylsp[(1) - (3)]).first_line, nodo_ne, "ne", (yyvsp[(1) - (3)].no), coringa("<>"), (yyvsp[(3) - (3)].no), NULL, NULL);
    }
    break;


/* Line 1267 of yacc.c.  */
#line 2141 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
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

  yyerror_range[0] = yylsp[1-yylen];
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
      if (yyn != YYPACT_NINF)
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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


#line 534 "pico.y"

 /* A partir daqui, insere-se qlqer codigo C necessario.
  */

int NaN(int type) {
    return type == CHAR_TYPE; // not a number
}
const char * itoa(int value) {
    static char buffer [33];
    sprintf(buffer, "%d", value);
    return buffer;
}
void address(char ** out, int num, char *ap) {
    * out = malloc(sizeof(char) * 8);
    sprintf(* out, "%03d(%s)", num, ap);
}

void insert_nodes(Node * ntype, Node * nvar) {
    int i;
    /* NODO IDF */
    if (nvar->type == nodo_idf) {
        entry_t *e = malloc(sizeof(entry_t));
        e->name = malloc(sizeof(char)* (strlen(nvar->lexeme) + 1));
        strcpy(e->name, nvar->lexeme);

        // TIPO UNICO
        if (ntype->type == nodo_tipounico) {
            e->type = ((attr_tipounico *) ntype->attribute)->type;
            e->size = ((attr_tipounico *) ntype->attribute)->size;
            e->extra = NULL;
        // TIPO LISTA
        } else if(ntype->type == nodo_tipolista) {
            e->type = ((attr_tipolista *) ntype->attribute)->type;
            e->size = ((attr_tipolista *) ntype->attribute)->size;

            attr_tipolista * at = (attr_tipolista *) ntype->attribute;
            attr_listadupla * at_lista = at->inner;
            // extra
            entry_textra * e_extra = malloc(sizeof(entry_textra));
            e_extra->lenght = at_lista->lenght;
            e_extra->type_size = at->type_size;
            // extra / c
            e_extra->c = at_lista->dim_init[0];
            for(i = 1; i < at_lista->lenght; i++)
                e_extra->c = (e_extra->c * at_lista->dim_size[i]) + at_lista->dim_init[i];
            e_extra->c *= -at->type_size;
            e_extra->c += desloc;
            // extra / dim_size
            e_extra->dim_size = malloc(sizeof(int) * e_extra->lenght);
            for(i = 0; i < e_extra->lenght; i++)
                e_extra->dim_size[i] = at_lista->dim_size[i];

            e->extra = e_extra;
        }
        e->desloc = desloc;
        desloc += e->size;
        insert(&s_table, e);

    /* NODO LISTA DECLARACAO */
    } else if (nvar->type == nodo_listadeclaracao) {
        for(i = 0; i < nb_of_children(nvar); i++)
            insert_nodes(ntype, child(nvar, i));
    }
}

// OPERATION: add sub mul div
int operation(attr_expr ** ret, char * type, attr_expr * left, attr_expr * right) {
    attr_expr * at = (attr_expr *) malloc(sizeof(attr_expr));
    * ret = at;
    at->code = left->code;
    cat_tac(&(at->code), &(right->code));

    if(NaN(left->type) || NaN(right->type))
        return error(TYPE_MISMATCH_ERROR);
    
    if(left->type == INT_TYPE && right->type == INT_TYPE) {
        at->type = INT_TYPE;
        address(&(at->value), rx_temp(INT_TYPE), RX);
        append_inst_tac(&(at->code), create_inst_tac(at->value, left->value, type, right->value));
    }
    // TODO: FLOAT
    return 0;
}

// RX TEMP
int rx_temp(int type) {
    static int tmp = 0;
    int ret = tmp;
    switch (type) {
        case CHAR_TYPE:     tmp += CHAR_SIZE; break;
        case INT_TYPE:      tmp += INT_SIZE; break;
        case REAL_TYPE:     tmp += REAL_SIZE; break;
        case DOUBLE_TYPE:   tmp += DOUBLE_SIZE; break;
    }
    return ret;
}

// ERROR
int error(int value) {
    if (value == GET_ERROR) {
        printf("Error %i", value);
        return errorValue;
    }
    return errorValue = value;
}
int error_undeclared(char * var) {
    printf("UNDEFINED SYMBOL. A Variavel %s nao foi declarada\n", var);
    return error(UNDEFINED_SYMBOL_ERROR);
}
int error_array(int type, char * var) {
    switch (type) {
        case NOT_ARRAY_ERROR:
            printf("ERRO! Variavel %s nao eh um array!\n", var); break;
        case ARRAY_DIM_ERROR:
            printf("ERRO! Array %s indexado em mais dimensoes do que possui!\n", var); break;
    }
    return error(type);
}


