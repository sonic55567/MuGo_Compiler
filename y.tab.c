/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "compiler_hw3.y" /* yacc.c:339  */

    #include "common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;
    
    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    /* Symbol table function - you can add new function if needed. */
    int level = -1;
    int labelIndex = 0;
    int tableIndex[30];
    int address = 0;
    int i;
    int print_type = 0;     /* print_type: 1:int32, 2:float32, 3:bool, 4:string */ 
    int linnn = 1;
    int isInitial = 0;      /* 1 : declaration has initial value */
    int LHS = 0;
    int RHS = 0;
    int stackIndex = 0;
    int beginIndex = 0;
    int blockIndex = 0;
    int postIndex = 0;
    int whileIndex = 0;
    int conditionIndex = 0;
    int forFlag = 0;        // use to determine what kind of for loop
    int preForFlag[5];
    int preForFlagIndex = 0;
    char convert_str[25] = "";
    char element_type[25] = "-";
    char errorLIT1[25] = "";
    char errorLIT2[25] = "";
    int errorLITIndex = 0;
    int compareFlag = 0;
    int arrayFlag = 0;
    static void create_symbol();
    static void insert_symbol();
    static void lookup_symbol();
    static void dump_symbol();
    static char* conversion();
    static void error_check();
    static char* getType();
    static char* getArrayType();
    static char* getLiteralType();
    static int getAddress();
    static void creatLabel();
    static void getLabel();
    static void creatStackLabel();
    static void getStackLabel();
    
    typedef struct symbol_Table{
        int index;
        char name[30];
        char type[30];
        int address;
        int lineno;
        char element_type[30];
        int level;
    }symbol_table;

    symbol_table table[30];

    int HAS_ERROR = 0;
    FILE *fp;


#line 139 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VAR = 258,
    NEWLINE = 259,
    IF = 260,
    ELSE = 261,
    FOR = 262,
    INT = 263,
    FLOAT = 264,
    BOOL = 265,
    STRING = 266,
    ID = 267,
    INT_LIT = 268,
    FLOAT_LIT = 269,
    TRUE = 270,
    FALSE = 271,
    STRING_LIT = 272,
    ADD_ASSIGN = 273,
    SUB_ASSIGN = 274,
    MUL_ASSIGN = 275,
    QUO_ASSIGN = 276,
    REM_ASSIGN = 277,
    INC = 278,
    DEC = 279,
    GEQ = 280,
    LEQ = 281,
    EQL = 282,
    NEQ = 283,
    LAND = 284,
    LOR = 285,
    PRINT = 286,
    PRINTLN = 287
  };
#endif
/* Tokens.  */
#define VAR 258
#define NEWLINE 259
#define IF 260
#define ELSE 261
#define FOR 262
#define INT 263
#define FLOAT 264
#define BOOL 265
#define STRING 266
#define ID 267
#define INT_LIT 268
#define FLOAT_LIT 269
#define TRUE 270
#define FALSE 271
#define STRING_LIT 272
#define ADD_ASSIGN 273
#define SUB_ASSIGN 274
#define MUL_ASSIGN 275
#define QUO_ASSIGN 276
#define REM_ASSIGN 277
#define INC 278
#define DEC 279
#define GEQ 280
#define LEQ 281
#define EQL 282
#define NEQ 283
#define LAND 284
#define LOR 285
#define PRINT 286
#define PRINTLN 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 80 "compiler_hw3.y" /* yacc.c:355  */

    int i_val;
    float f_val;
    char *s_val;
    char *type;
    /* ... */

#line 251 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 268 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   406

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,    50,     2,     2,    36,     2,     2,
       4,     5,    34,    32,    11,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    10,
      40,    26,    39,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     6,     2,     7,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     8,     2,     9,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    27,    28,    29,    30,    31,    37,    38,
      41,    42,    43,    44,    45,    46,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   128,   128,   128,   132,   133,   137,   138,   142,   143,
     144,   145,   149,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   171,   172,
     200,   201,   202,   206,   207,   208,   212,   213,   214,   215,
     216,   217,   218,   223,   245,   245,   259,   260,   261,   262,
     263,   264,   265,   269,   270,   271,   275,   276,   280,   280,
     328,   328,   382,   382,   436,   436,   490,   490,   544,   544,
     601,   605,   626,   642,   642,   646,   646,   655,   659,   665,
     685,   685,   685,   730,   731,   731,   731,   735,   739,   743,
     743,   780,   780
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "'('", "')'", "'['", "']'", "'{'",
  "'}'", "';'", "','", "NEWLINE", "IF", "ELSE", "FOR", "INT", "FLOAT",
  "BOOL", "STRING", "ID", "INT_LIT", "FLOAT_LIT", "TRUE", "FALSE",
  "STRING_LIT", "'='", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "QUO_ASSIGN", "REM_ASSIGN", "'+'", "'-'", "'*'", "'/'", "'%'", "INC",
  "DEC", "'>'", "'<'", "GEQ", "LEQ", "EQL", "NEQ", "LAND", "LOR", "'!'",
  "PRINT", "PRINTLN", "'\"'", "$accept", "Program", "$@1", "StatementList",
  "Type", "TypeName", "ArrayType", "Expression", "UnaryExpr", "unary_op",
  "PrimaryExpr", "Operand", "IndexExpr", "ConversionExpr", "$@2",
  "Statement", "SimpleStmt", "DeclarationStmt", "AssignmentStmt", "$@3",
  "$@4", "$@5", "$@6", "$@7", "$@8", "ExpressionStmt", "IncDecStmt",
  "Block", "$@9", "IfStmt", "$@10", "Condition", "ForStmt", "$@11", "$@12",
  "ForClause", "$@13", "$@14", "InitStmt", "PostStmt", "PrintStmt", "$@15",
  "$@16", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,    40,    41,    91,    93,   123,   125,
      59,    44,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,    61,   273,   274,   275,
     276,   277,    43,    45,    42,    47,    37,   278,   279,    62,
      60,   280,   281,   282,   283,   284,   285,    33,   286,   287,
      34
};
# endif

#define YYPACT_NINF -83

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-83)))

#define YYTABLE_NINF -80

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -83,     3,   110,   -83,   -13,   145,   145,   -83,   -83,   145,
     -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,   145,   110,    13,   -83,
     -83,   313,   -83,   180,     2,   -83,   -83,   -83,   -83,    -1,
      12,   -83,   -83,   -83,    32,    94,    43,    44,    35,   175,
     248,   110,   347,   -83,   145,    62,    63,   328,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,   145,   145,   145,   145,
     145,   -83,   -83,   145,   145,   145,   145,   145,   145,   145,
     145,   -83,   145,   -83,   -83,   -83,   -83,     7,   -83,   -83,
      57,   -83,    35,    10,    76,   292,   -83,   -83,   -83,    83,
     145,   145,   -83,   145,   145,   145,   145,   145,   145,   145,
      11,    11,   -83,   -83,   -83,     4,     4,     4,     4,     4,
       4,   362,    46,   263,   -83,    80,   145,   -83,   -83,   -83,
      76,   -83,   201,   217,   233,   347,   347,   347,   347,   347,
     347,   -83,   347,   -83,   145,   -83,   -83,   -83,    87,   -83,
     145,   -83,   -83
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,    73,    52,     0,
      80,     8,     9,    11,    10,    41,    36,    37,    38,    39,
      40,    30,    31,    32,    89,    91,     0,     3,     0,     6,
       7,    70,    13,     0,    28,    33,    34,    35,     5,     0,
       0,    53,    54,    55,     0,     0,     0,     0,     0,     0,
       0,     0,    79,    75,     0,     0,     0,     0,     4,    44,
      58,    60,    62,    64,    66,    68,     0,     0,     0,     0,
       0,    71,    72,     0,     0,     0,     0,     0,     0,     0,
       0,    29,     0,    47,    46,    48,    49,     0,    50,    51,
      56,    42,     0,     0,     0,    70,    87,    83,    81,     0,
       0,     0,    14,     0,     0,     0,     0,     0,     0,     0,
      15,    16,    17,    18,    19,    24,    22,    25,    23,    20,
      21,    27,    26,     0,    78,    77,     0,    12,    74,    76,
       0,    84,     0,     0,     0,    59,    61,    63,    65,    67,
      69,    43,    57,    82,     0,    90,    92,    45,     0,    85,
       0,    88,    86
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -83,   -83,   -83,    56,   -42,   -83,   -83,    -5,    77,   -83,
     -83,   -83,   -83,   -83,   -83,   -17,   -45,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,   -83,   -82,   -83,    22,
     -83,   -52,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -83
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,   103,    38,    39,    40,    41,   104,
     105,   106,   107,   108,   109,    42,    43,    44,    51,    45,
      94,    53,    46,    54,   130,    98,   144,   150,    99,   152,
      47,    55,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    50,    97,     3,    52,   124,    90,    48,    82,    96,
      58,    83,   129,     4,     5,     7,     6,    59,     7,   128,
       9,    57,     8,     9,    84,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    66,    67,    68,    69,
      70,     6,    21,    22,    85,    68,    69,    70,   143,    95,
     127,    11,    12,    13,    14,    88,    89,    23,    24,    25,
      26,   110,   111,   112,   113,   114,   100,   101,   115,   116,
     117,   118,   119,   120,   121,   122,    58,   123,    66,    67,
      68,    69,    70,   126,     7,    73,    74,    75,    76,    77,
      78,    79,   148,   131,    87,   132,   133,   149,   134,   135,
     136,   137,   138,   139,   140,   151,    86,    93,    87,   125,
      81,     0,     0,     4,     5,     0,     6,     0,     7,     0,
       0,   142,     8,     9,     0,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,     0,     0,    52,
       0,     0,    21,    22,     0,     0,     0,     0,     0,     5,
       0,     6,     0,     0,     0,     0,     0,    23,    24,    25,
      26,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,     0,     0,     0,     0,     0,    21,    22,     0,
      91,     0,     0,     0,     5,     0,     6,     0,     0,     0,
       0,     0,    23,     0,     0,    26,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,   145,    66,    67,    68,
      69,    70,    21,    22,    73,    74,    75,    76,    77,    78,
      79,    80,   146,     0,     0,     0,     0,    23,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,   147,     0,
      73,    74,    75,    76,    77,    78,    79,    80,     0,    66,
      67,    68,    69,    70,     0,    92,    73,    74,    75,    76,
      77,    78,    79,    80,     0,    66,    67,    68,    69,    70,
     141,     0,    73,    74,    75,    76,    77,    78,    79,    80,
      66,    67,    68,    69,    70,     0,     0,    73,    74,    75,
      76,    77,    78,    79,    80,    66,    67,    68,    69,    70,
     -79,     0,    73,    74,    75,    76,    77,    78,    79,    80,
       0,     0,     0,     0,     0,     0,     0,     0,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      66,    67,    68,    69,    70,     0,     0,    73,    74,    75,
      76,    77,    78,    79,    80,     0,     0,     0,   102,    66,
      67,    68,    69,    70,     0,     0,    73,    74,    75,    76,
      77,    78,    79,    80,    66,    67,    68,    69,    70,     0,
       0,    73,    74,    75,    76,    77,    78
};

static const yytype_int16 yycheck[] =
{
       5,     6,    54,     0,     9,    87,    48,    20,     6,    54,
      27,    12,    94,     3,     4,     8,     6,     4,     8,     9,
      13,    26,    12,    13,    12,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    32,    33,    34,    35,
      36,     6,    32,    33,    12,    34,    35,    36,   130,    54,
      92,    16,    17,    18,    19,    12,    12,    47,    48,    49,
      50,    66,    67,    68,    69,    70,     4,     4,    73,    74,
      75,    76,    77,    78,    79,    80,    93,    82,    32,    33,
      34,    35,    36,    26,     8,    39,    40,    41,    42,    43,
      44,    45,   144,    10,    14,   100,   101,    10,   103,   104,
     105,   106,   107,   108,   109,   150,    12,    51,    14,    87,
      33,    -1,    -1,     3,     4,    -1,     6,    -1,     8,    -1,
      -1,   126,    12,    13,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,   144,
      -1,    -1,    32,    33,    -1,    -1,    -1,    -1,    -1,     4,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      50,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    -1,
       5,    -1,    -1,    -1,     4,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    50,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     5,    32,    33,    34,
      35,    36,    32,    33,    39,    40,    41,    42,    43,    44,
      45,    46,     5,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,     5,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    32,
      33,    34,    35,    36,    -1,     7,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    32,    33,    34,    35,    36,
       7,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      32,    33,    34,    35,    36,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    32,    33,    34,    35,    36,
       8,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      32,    33,    34,    35,    36,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    50,    32,
      33,    34,    35,    36,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    32,    33,    34,    35,    36,    -1,
      -1,    39,    40,    41,    42,    43,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    52,    53,     0,     3,     4,     6,     8,    12,    13,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    32,    33,    47,    48,    49,    50,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    66,    67,
      68,    69,    76,    77,    78,    80,    83,    91,    20,    58,
      58,    79,    58,    82,    84,    92,    93,    58,    66,     4,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    59,     6,    12,    12,    12,    12,    14,    12,    12,
      55,     5,     7,    54,    81,    58,    67,    82,    86,    89,
       4,     4,    50,    65,    70,    71,    72,    73,    74,    75,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    78,    80,    26,    55,     9,    78,
      85,    10,    58,    58,    58,    58,    58,    58,    58,    58,
      58,     7,    58,    78,    87,     5,     5,     5,    82,    10,
      88,    67,    90
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    53,    52,    54,    54,    55,    55,    56,    56,
      56,    56,    57,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    59,    59,
      60,    60,    60,    61,    61,    61,    62,    62,    62,    62,
      62,    62,    62,    63,    65,    64,    66,    66,    66,    66,
      66,    66,    66,    67,    67,    67,    68,    68,    70,    69,
      71,    69,    72,    69,    73,    69,    74,    69,    75,    69,
      76,    77,    77,    79,    78,    81,    80,    80,    80,    82,
      84,    85,    83,    86,    87,    88,    86,    89,    90,    92,
      91,    93,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     4,     0,     5,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     3,     5,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       1,     2,     2,     0,     4,     0,     4,     3,     3,     1,
       0,     0,     5,     1,     0,     0,     7,     1,     1,     0,
       5,     0,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
      yychar = yylex ();
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
     '$$ = $1'.

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
#line 128 "compiler_hw3.y" /* yacc.c:1646  */
    { create_symbol(); }
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 128 "compiler_hw3.y" /* yacc.c:1646  */
    { dump_symbol(); }
#line 1519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 142 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); strcpy(element_type, "-"); }
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 143 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); strcpy(element_type, "-"); }
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 144 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); strcpy(element_type, "-"); }
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 145 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); strcpy(element_type, "-"); }
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 149 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "array"; strcpy(element_type, (yyvsp[0].s_val)); }
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 154 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[-1].s_val); }
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 155 "compiler_hw3.y" /* yacc.c:1646  */
    { error_check((yyvsp[-2].s_val), (yyvsp[0].s_val), (yyvsp[-1].s_val)); printf("%s\n", (yyvsp[-1].s_val)); errorLITIndex = 0; compareFlag = 0; }
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 156 "compiler_hw3.y" /* yacc.c:1646  */
    { error_check((yyvsp[-2].s_val), (yyvsp[0].s_val), (yyvsp[-1].s_val)); printf("%s\n", (yyvsp[-1].s_val)); compareFlag = 0; }
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 157 "compiler_hw3.y" /* yacc.c:1646  */
    { error_check((yyvsp[-2].s_val), (yyvsp[0].s_val), (yyvsp[-1].s_val)); printf("%s\n", (yyvsp[-1].s_val)); compareFlag = 0; }
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 158 "compiler_hw3.y" /* yacc.c:1646  */
    { error_check((yyvsp[-2].s_val), (yyvsp[0].s_val), (yyvsp[-1].s_val)); printf("%s\n", (yyvsp[-1].s_val)); compareFlag = 0; }
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 159 "compiler_hw3.y" /* yacc.c:1646  */
    { error_check((yyvsp[-2].s_val), (yyvsp[0].s_val), (yyvsp[-1].s_val)); printf("%s\n", (yyvsp[-1].s_val)); compareFlag = 0; }
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 160 "compiler_hw3.y" /* yacc.c:1646  */
    { error_check((yyvsp[-2].s_val), (yyvsp[0].s_val), (yyvsp[-1].s_val)); printf("%s\n", (yyvsp[-1].s_val)); print_type = 3; compareFlag = 1; }
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 161 "compiler_hw3.y" /* yacc.c:1646  */
    { error_check((yyvsp[-2].s_val), (yyvsp[0].s_val), (yyvsp[-1].s_val)); printf("%s\n", (yyvsp[-1].s_val)); print_type = 3; compareFlag = 1; }
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 162 "compiler_hw3.y" /* yacc.c:1646  */
    { error_check((yyvsp[-2].s_val), (yyvsp[0].s_val), (yyvsp[-1].s_val)); printf("%s\n", (yyvsp[-1].s_val)); print_type = 3; compareFlag = 1; }
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 163 "compiler_hw3.y" /* yacc.c:1646  */
    { error_check((yyvsp[-2].s_val), (yyvsp[0].s_val), (yyvsp[-1].s_val)); printf("%s\n", (yyvsp[-1].s_val)); print_type = 3; compareFlag = 1; }
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 164 "compiler_hw3.y" /* yacc.c:1646  */
    { error_check((yyvsp[-2].s_val), (yyvsp[0].s_val), (yyvsp[-1].s_val)); printf("%s\n", (yyvsp[-1].s_val)); print_type = 3; compareFlag = 1; }
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 165 "compiler_hw3.y" /* yacc.c:1646  */
    { error_check((yyvsp[-2].s_val), (yyvsp[0].s_val), (yyvsp[-1].s_val)); printf("%s\n", (yyvsp[-1].s_val)); print_type = 3; compareFlag = 1; }
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 166 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("123\n%s\n%s\n%s\n%d\n%d\n\n", (yyvsp[-2].s_val), (yyvsp[-1].s_val), (yyvsp[0].s_val), compareFlag, print_type); error_check((yyvsp[-2].s_val), (yyvsp[0].s_val), (yyvsp[-1].s_val)); printf("%s\n", (yyvsp[-1].s_val)); print_type = 3; compareFlag = 1; }
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 167 "compiler_hw3.y" /* yacc.c:1646  */
    { error_check((yyvsp[-2].s_val), (yyvsp[0].s_val), (yyvsp[-1].s_val)); printf("%s\n", (yyvsp[-1].s_val)); print_type = 3; compareFlag = 1; }
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 172 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("%s\n%s\n", (yyvsp[-1].s_val), (yyvsp[0].s_val));
        (yyval.s_val) = (yyvsp[0].s_val);
        if(strcmp((yyvsp[-1].s_val), "NOT") == 0) {
            fprintf(fp, "ixor\n");
        }
        else if(strcmp((yyvsp[-1].s_val), "NEG") == 0) {
            if(strcmp(getType(level, (yyvsp[0].s_val)), "") != 0) {  
                if(strcmp(getType(level, (yyvsp[0].s_val)), "int32") == 0) {
                    fprintf(fp, "ineg\n");
                }
                else if(strcmp(getType(level, (yyvsp[0].s_val)), "float32") == 0) {
                    fprintf(fp, "fneg\n");
                }
            }
            else {
                if(strcmp(getLiteralType((yyvsp[0].s_val)), "int32") == 0) {
                    fprintf(fp, "ineg\n");
                }
                else if(strcmp(getLiteralType((yyvsp[0].s_val)), "float32") == 0) {
                    fprintf(fp, "fneg\n");
                }
            }
        }
    }
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 200 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "POS"; }
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 201 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "NEG"; }
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 202 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "NOT"; fprintf(fp, "iconst_1\n"); }
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 212 "compiler_hw3.y" /* yacc.c:1646  */
    { char str[25] = "ldc "; char buffer[25]; sprintf(buffer, "%d", (yyvsp[0].i_val)); strcat(str, buffer); (yyval.s_val) = str; if(print_type <= 1) print_type = 1; printf("%s\n", str); fprintf(fp, "%s\n", str); if(errorLITIndex == 0) { strcpy(errorLIT1, str); errorLITIndex++; } else if (errorLITIndex == 1) { strcpy(errorLIT2, str); errorLITIndex = 0; } }
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 213 "compiler_hw3.y" /* yacc.c:1646  */
    { char str[25] = "ldc "; char buffer[25]; sprintf(buffer, "%f", (yyvsp[0].f_val)); strcat(str, buffer); (yyval.s_val) = str; if(print_type <= 2) print_type = 2; printf("%s\n", str); fprintf(fp, "%s\n", str); if(errorLITIndex == 0) { strcpy(errorLIT1, str); errorLITIndex++; } else if (errorLITIndex == 1) { strcpy(errorLIT2, str); errorLITIndex = 0; } }
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 214 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "TRUE"; if(print_type <=3) print_type = 3; printf("%s\n", "iconst_1"); fprintf(fp, "%s\n", "iconst_1"); }
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 215 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "FALSE"; if(print_type <=3) print_type = 3; printf("%s\n", "iconst_0"); fprintf(fp, "%s\n", "iconst_0"); }
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 216 "compiler_hw3.y" /* yacc.c:1646  */
    { char str[25] = "ldc \""; strcat(strcat(str, (yyvsp[0].s_val)), "\""); (yyval.s_val) = str; if(print_type != 4) print_type = 4; printf("%s\n", str); fprintf(fp, "%s\n", str); }
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 217 "compiler_hw3.y" /* yacc.c:1646  */
    { lookup_symbol(level, (yyvsp[0].s_val)); }
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 218 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[-1].s_val); }
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 223 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val) = (yyvsp[-3].s_val);
        arrayFlag = 1;
        if(RHS)  {
            if(strcmp(getArrayType(level, (yyvsp[-3].s_val)), "int32") == 0) {
                fprintf(fp, "iaload\n");
            }
            else if(strcmp(getArrayType(level, (yyvsp[-3].s_val)), "float32") == 0) {
                fprintf(fp, "faload\n");
            }
            else if(strcmp(getArrayType(level, (yyvsp[-3].s_val)), "bool") == 0) {
                fprintf(fp, "iaload\n");
            }
            else if(strcmp(getArrayType(level, (yyvsp[-3].s_val)), "string") == 0) {
                fprintf(fp, "aaload\n");
            }
        }
    }
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 245 "compiler_hw3.y" /* yacc.c:1646  */
    { print_type = 0; }
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 245 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(strcmp(conversion((yyvsp[-4].s_val), print_type),"f2i") == 0) {
            fprintf(fp, "%s\n", conversion((yyvsp[-4].s_val), print_type));
            print_type = 1;
        }
        else if(strcmp(conversion((yyvsp[-4].s_val), print_type),"i2f") == 0) {
            fprintf(fp, "%s\n", conversion((yyvsp[-4].s_val), print_type));
            print_type = 2;
        }
        
    }
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 259 "compiler_hw3.y" /* yacc.c:1646  */
    { linnn++; }
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 260 "compiler_hw3.y" /* yacc.c:1646  */
    { linnn++; print_type = 0; }
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 261 "compiler_hw3.y" /* yacc.c:1646  */
    { linnn++; }
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 262 "compiler_hw3.y" /* yacc.c:1646  */
    { linnn++; creatLabel(); }
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 263 "compiler_hw3.y" /* yacc.c:1646  */
    { linnn++; }
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 264 "compiler_hw3.y" /* yacc.c:1646  */
    { linnn++; RHS = 0; }
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 265 "compiler_hw3.y" /* yacc.c:1646  */
    { linnn++; }
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 269 "compiler_hw3.y" /* yacc.c:1646  */
    { RHS = 0; if(!arrayFlag) fprintf(fp, "pop\n"); arrayFlag = 0; }
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 270 "compiler_hw3.y" /* yacc.c:1646  */
    { arrayFlag = 0; }
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 271 "compiler_hw3.y" /* yacc.c:1646  */
    { arrayFlag = 0; }
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 275 "compiler_hw3.y" /* yacc.c:1646  */
    { isInitial = 0; insert_symbol(tableIndex[level]++, (yyvsp[-1].s_val), (yyvsp[0].s_val), address++, yylineno, element_type); print_type = 0; }
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 276 "compiler_hw3.y" /* yacc.c:1646  */
    { isInitial = 1; insert_symbol(tableIndex[level]++, (yyvsp[-3].s_val), (yyvsp[-2].s_val), address++, yylineno, element_type); print_type = 0; }
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 280 "compiler_hw3.y" /* yacc.c:1646  */
    { RHS = 1; }
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 280 "compiler_hw3.y" /* yacc.c:1646  */
    {

        if(strcmp(getLiteralType((yyvsp[-3].s_val)), "int32") == 0) {
            printf("error:%d: cannot assign to int32\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getLiteralType((yyvsp[-3].s_val)), "float32") == 0) {
            printf("error:%d: cannot assign to float32\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getLiteralType((yyvsp[-3].s_val)), "string") == 0) {
            printf("error:%d: cannot assign to string\n", yylineno);
            HAS_ERROR = 1;
        }
        else if((strncmp((yyvsp[-3].s_val), "TRUE", 4) == 0) || (strncmp((yyvsp[-3].s_val), "FALSE", 5) == 0)) {
            printf("error:%d: cannot assign to bool\n", yylineno);
            HAS_ERROR = 1;
        }
        
        
        if(strcmp(getType(level, (yyvsp[-3].s_val)), "array") == 0) {
            if(strcmp(getArrayType(level, (yyvsp[-3].s_val)), "int32") == 0) {
                fprintf(fp, "iastore\n");
            }
            else if(strcmp(getArrayType(level, (yyvsp[-3].s_val)), "float32") == 0) {
                fprintf(fp, "fastore\n");
            }
            else if(strcmp(getArrayType(level, (yyvsp[-3].s_val)), "string") == 0) {
                fprintf(fp, "aastore\n");
            }
            else if(strcmp(getArrayType(level, (yyvsp[-3].s_val)), "bool") == 0) {
                fprintf(fp, "iastore\n");
            }
        }
        else if(strcmp(getType(level, (yyvsp[-3].s_val)), "int32") == 0) {
            fprintf(fp, "istore %d\n", getAddress(level, (yyvsp[-3].s_val)));
        }
        else if(strcmp(getType(level, (yyvsp[-3].s_val)), "float32") == 0) {
            fprintf(fp, "fstore %d\n", getAddress(level, (yyvsp[-3].s_val)));
        }
        else if(strcmp(getType(level, (yyvsp[-3].s_val)), "string") == 0) {
            fprintf(fp, "astore %d\n", getAddress(level, (yyvsp[-3].s_val)));
        }
        else if(strcmp(getType(level, (yyvsp[-3].s_val)), "bool") == 0) {
            fprintf(fp, "istore %d\n", getAddress(level, (yyvsp[-3].s_val)));
        }
        RHS = 0;
    }
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 328 "compiler_hw3.y" /* yacc.c:1646  */
    { RHS = 1; lookup_symbol(level, (yyvsp[-1].s_val)); }
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 328 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        if(strcmp(getLiteralType((yyvsp[-3].s_val)), "int32") == 0) {
            printf("error:%d: cannot assign to int32\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getLiteralType((yyvsp[-3].s_val)), "float32") == 0) {
            printf("error:%d: cannot assign to float32\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getLiteralType((yyvsp[-3].s_val)), "string") == 0) {
            printf("error:%d: cannot assign to string\n", yylineno);
            HAS_ERROR = 1;
        }
        else if((strncmp((yyvsp[-3].s_val), "TRUE", 4) == 0) || (strncmp((yyvsp[-3].s_val), "FALSE", 5) == 0)) {
            printf("error:%d: cannot assign to bool\n", yylineno);
            HAS_ERROR = 1;
        }
        
        if(strcmp(getType(level, (yyvsp[-3].s_val)), "array") == 0) {
            if(strcmp(getArrayType(level, (yyvsp[-3].s_val)), "int32") == 0) {
                fprintf(fp, "iadd\n");
                fprintf(fp, "iastore\n");
            }
            else if(strcmp(getArrayType(level, (yyvsp[-3].s_val)), "float32") == 0) {
                fprintf(fp, "fadd\n");
                fprintf(fp, "fastore\n");
            }
            else if(strcmp(getArrayType(level, (yyvsp[-3].s_val)), "string") == 0) {
                printf("error:%d: cannot add to string\n", yylineno);
                HAS_ERROR = 1;
            }
            else if(strcmp(getArrayType(level, (yyvsp[-3].s_val)), "bool") == 0) {
                printf("error:%d: cannot add to bool\n", yylineno);
                HAS_ERROR = 1;
            }
        }
        else if(strcmp(getType(level, (yyvsp[-3].s_val)), "int32") == 0) {
            fprintf(fp, "iadd\n");
            fprintf(fp, "istore %d\n", getAddress(level, (yyvsp[-3].s_val)));
        }
        else if(strcmp(getType(level, (yyvsp[-3].s_val)), "float32") == 0) {
            fprintf(fp, "fadd\n");
            fprintf(fp, "fstore %d\n", getAddress(level, (yyvsp[-3].s_val)));
        }
        else if(strcmp(getType(level, (yyvsp[-3].s_val)), "string") == 0) {
            printf("error:%d: cannot add to string\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getType(level, (yyvsp[-3].s_val)), "bool") == 0) {
            printf("error:%d: cannot add to bool\n", yylineno);
            HAS_ERROR = 1;
        }
        RHS = 0;
    }
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 382 "compiler_hw3.y" /* yacc.c:1646  */
    { RHS = 1; lookup_symbol(level, (yyvsp[-1].s_val)); }
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 382 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        if(strcmp(getLiteralType((yyvsp[-3].s_val)), "int32") == 0) {
            printf("error:%d: cannot assign to int32\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getLiteralType((yyvsp[-3].s_val)), "float32") == 0) {
            printf("error:%d: cannot assign to float32\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getLiteralType((yyvsp[-3].s_val)), "string") == 0) {
            printf("error:%d: cannot assign to string\n", yylineno);
            HAS_ERROR = 1;
        }
        else if((strncmp((yyvsp[-3].s_val), "TRUE", 4) == 0) || (strncmp((yyvsp[-3].s_val), "FALSE", 5) == 0)) {
            printf("error:%d: cannot assign to bool\n", yylineno);
            HAS_ERROR = 1;
        }
        
        if(strcmp(getType(level, (yyvsp[-3].s_val)), "array") == 0) {
            if(strcmp(getArrayType(level, (yyvsp[-3].s_val)), "int32") == 0) {
                fprintf(fp, "isub\n");
                fprintf(fp, "iastore\n");
            }
            else if(strcmp(getArrayType(level, (yyvsp[-3].s_val)), "float32") == 0) {
                fprintf(fp, "fsub\n");
                fprintf(fp, "fastore\n");
            }
            else if(strcmp(getArrayType(level, (yyvsp[-3].s_val)), "string") == 0) {
                printf("error:%d: cannot sub to string\n", yylineno);
                HAS_ERROR = 1;
            }
            else if(strcmp(getArrayType(level, (yyvsp[-3].s_val)), "bool") == 0) {
                printf("error:%d: cannot sub to bool\n", yylineno);
                HAS_ERROR = 1;
            }
        }
        else if(strcmp(getType(level, (yyvsp[-3].s_val)), "int32") == 0) {
            fprintf(fp, "isub\n");
            fprintf(fp, "istore %d\n", getAddress(level, (yyvsp[-3].s_val)));
        }
        else if(strcmp(getType(level, (yyvsp[-3].s_val)), "float32") == 0) {
            fprintf(fp, "fsub\n");
            fprintf(fp, "fstore %d\n", getAddress(level, (yyvsp[-3].s_val)));
        }
        else if(strcmp(getType(level, (yyvsp[-3].s_val)), "string") == 0) {
            printf("error:%d: cannot sub to string\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getType(level, (yyvsp[-3].s_val)), "bool") == 0) {
            printf("error:%d: cannot sub to bool\n", yylineno);
            HAS_ERROR = 1;
        }
        RHS = 0;
    }
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 436 "compiler_hw3.y" /* yacc.c:1646  */
    { RHS = 1; lookup_symbol(level, (yyvsp[-1].s_val)); }
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 436 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        if(strcmp(getLiteralType((yyvsp[-3].s_val)), "int32") == 0) {
            printf("error:%d: cannot assign to int32\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getLiteralType((yyvsp[-3].s_val)), "float32") == 0) {
            printf("error:%d: cannot assign to float32\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getLiteralType((yyvsp[-3].s_val)), "string") == 0) {
            printf("error:%d: cannot assign to string\n", yylineno);
            HAS_ERROR = 1;
        }
        else if((strncmp((yyvsp[-3].s_val), "TRUE", 4) == 0) || (strncmp((yyvsp[-3].s_val), "FALSE", 5) == 0)) {
            printf("error:%d: cannot assign to bool\n", yylineno);
            HAS_ERROR = 1;
        }
        
        if(strcmp(getType(level, (yyvsp[-3].s_val)), "array") == 0) {
            if(strcmp(getArrayType(level, (yyvsp[-3].s_val)), "int32") == 0) {
                fprintf(fp, "imul\n");
                fprintf(fp, "iastore\n");
            }
            else if(strcmp(getArrayType(level, (yyvsp[-3].s_val)), "float32") == 0) {
                fprintf(fp, "fmul\n");
                fprintf(fp, "fastore\n");
            }
            else if(strcmp(getArrayType(level, (yyvsp[-3].s_val)), "string") == 0) {
                printf("error:%d: cannot mul to string\n", yylineno);
                HAS_ERROR = 1;
            }
            else if(strcmp(getArrayType(level, (yyvsp[-3].s_val)), "bool") == 0) {
                printf("error:%d: cannot mul to bool\n", yylineno);
                HAS_ERROR = 1;
            }
        }
        else if(strcmp(getType(level, (yyvsp[-3].s_val)), "int32") == 0) {
            fprintf(fp, "imul\n");
            fprintf(fp, "istore %d\n", getAddress(level, (yyvsp[-3].s_val)));
        }
        else if(strcmp(getType(level, (yyvsp[-3].s_val)), "float32") == 0) {
            fprintf(fp, "fmul\n");
            fprintf(fp, "fstore %d\n", getAddress(level, (yyvsp[-3].s_val)));
        }
        else if(strcmp(getType(level, (yyvsp[-3].s_val)), "string") == 0) {
            printf("error:%d: cannot mul to string\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getType(level, (yyvsp[-3].s_val)), "bool") == 0) {
            printf("error:%d: cannot mul to bool\n", yylineno);
            HAS_ERROR = 1;
        }
        RHS = 0;
    }
#line 2094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 490 "compiler_hw3.y" /* yacc.c:1646  */
    { RHS = 1; lookup_symbol(level, (yyvsp[-1].s_val)); }
#line 2100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 490 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        if(strcmp(getLiteralType((yyvsp[-3].s_val)), "int32") == 0) {
            printf("error:%d: cannot assign to int32\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getLiteralType((yyvsp[-3].s_val)), "float32") == 0) {
            printf("error:%d: cannot assign to float32\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getLiteralType((yyvsp[-3].s_val)), "string") == 0) {
            printf("error:%d: cannot assign to string\n", yylineno);
            HAS_ERROR = 1;
        }
        else if((strncmp((yyvsp[-3].s_val), "TRUE", 4) == 0) || (strncmp((yyvsp[-3].s_val), "FALSE", 5) == 0)) {
            printf("error:%d: cannot assign to bool\n", yylineno);
            HAS_ERROR = 1;
        }
        
        if(strcmp(getType(level, (yyvsp[-3].s_val)), "array") == 0) {
            if(strcmp(getArrayType(level, (yyvsp[-3].s_val)), "int32") == 0) {
                fprintf(fp, "idiv\n");
                fprintf(fp, "iastore\n");
            }
            else if(strcmp(getArrayType(level, (yyvsp[-3].s_val)), "float32") == 0) {
                fprintf(fp, "fdiv\n");
                fprintf(fp, "fastore\n");
            }
            else if(strcmp(getArrayType(level, (yyvsp[-3].s_val)), "string") == 0) {
                printf("error:%d: cannot div to string\n", yylineno);
                HAS_ERROR = 1;
            }
            else if(strcmp(getArrayType(level, (yyvsp[-3].s_val)), "bool") == 0) {
                printf("error:%d: cannot div to bool\n", yylineno);
                HAS_ERROR = 1;
            }
        }
        else if(strcmp(getType(level, (yyvsp[-3].s_val)), "int32") == 0) {
            fprintf(fp, "idiv\n");
            fprintf(fp, "istore %d\n", getAddress(level, (yyvsp[-3].s_val)));
        }
        else if(strcmp(getType(level, (yyvsp[-3].s_val)), "float32") == 0) {
            fprintf(fp, "fdiv\n");
            fprintf(fp, "fstore %d\n", getAddress(level, (yyvsp[-3].s_val)));
        }
        else if(strcmp(getType(level, (yyvsp[-3].s_val)), "string") == 0) {
            printf("error:%d: cannot div to string\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getType(level, (yyvsp[-3].s_val)), "bool") == 0) {
            printf("error:%d: cannot div to bool\n", yylineno);
            HAS_ERROR = 1;
        }
        RHS = 0;
    }
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 544 "compiler_hw3.y" /* yacc.c:1646  */
    { RHS = 1; lookup_symbol(level, (yyvsp[-1].s_val)); }
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 544 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        if(strcmp(getLiteralType((yyvsp[-3].s_val)), "int32") == 0) {
            printf("error:%d: cannot assign to int32\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getLiteralType((yyvsp[-3].s_val)), "float32") == 0) {
            printf("error:%d: cannot assign to float32\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getLiteralType((yyvsp[-3].s_val)), "string") == 0) {
            printf("error:%d: cannot assign to string\n", yylineno);
            HAS_ERROR = 1;
        }
        else if((strncmp((yyvsp[-3].s_val), "TRUE", 4) == 0) || (strncmp((yyvsp[-3].s_val), "FALSE", 5) == 0)) {
            printf("error:%d: cannot assign to bool\n", yylineno);
            HAS_ERROR = 1;
        }
        
        if(strcmp(getType(level, (yyvsp[-3].s_val)), "array") == 0) {
            if(strcmp(getArrayType(level, (yyvsp[-3].s_val)), "int32") == 0) {
                fprintf(fp, "irem\n");
                fprintf(fp, "iastore\n");
            }
            else if(strcmp(getArrayType(level, (yyvsp[-3].s_val)), "float32") == 0) {
                printf("error:%d: cannot mul to float32\n", yylineno);
                HAS_ERROR = 1;
            }
            else if(strcmp(getArrayType(level, (yyvsp[-3].s_val)), "string") == 0) {
                printf("error:%d: cannot mul to string\n", yylineno);
                HAS_ERROR = 1;
            }
            else if(strcmp(getArrayType(level, (yyvsp[-3].s_val)), "bool") == 0) {
                printf("error:%d: cannot mul to bool\n", yylineno);
                HAS_ERROR = 1;
            }
        }
        else if(strcmp(getType(level, (yyvsp[-3].s_val)), "int32") == 0) {
            fprintf(fp, "irem\n");
            fprintf(fp, "istore %d\n", getAddress(level, (yyvsp[-3].s_val)));
        }
        else if(strcmp(getType(level, (yyvsp[-3].s_val)), "float32") == 0) {
            printf("error:%d: cannot mul to float32\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getType(level, (yyvsp[-3].s_val)), "string") == 0) {
            printf("error:%d: cannot mul to string\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getType(level, (yyvsp[-3].s_val)), "bool") == 0) {
            printf("error:%d: cannot mul to bool\n", yylineno);
            HAS_ERROR = 1;
        }
        RHS = 0;
    }
#line 2224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 605 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("%s\n", (yyvsp[0].s_val)); 
        if(strcmp(getType(level, (yyvsp[-1].s_val)), "int32") == 0) {
            fprintf(fp, "ldc 1\n");
            fprintf(fp, "iadd\n");
            fprintf(fp, "istore %d\n", getAddress(level, (yyvsp[-1].s_val)));
        }
        else if(strcmp(getType(level, (yyvsp[-1].s_val)), "float32") == 0) {
            fprintf(fp, "ldc 1.000000\n");
            fprintf(fp, "fadd\n");
            fprintf(fp, "fstore %d\n", getAddress(level, (yyvsp[-1].s_val)));
        }
        else if(strcmp(getType(level, (yyvsp[-1].s_val)), "array") == 0) {
            if(strcmp(getArrayType(level, (yyvsp[-1].s_val)), "int32") == 0) {

            }
            else if(strcmp(getArrayType(level, (yyvsp[-1].s_val)), "float32") == 0) {

            }
        }
    }
#line 2250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 626 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("%s\n", (yyvsp[0].s_val)); 
        if(strcmp(getType(level, (yyvsp[-1].s_val)), "int32") == 0) {
            fprintf(fp, "ldc 1\n");
            fprintf(fp, "isub\n");
            fprintf(fp, "istore %d\n", getAddress(level, (yyvsp[-1].s_val)));
        }
        else if(strcmp(getType(level, (yyvsp[-1].s_val)), "float32") == 0) {
            fprintf(fp, "ldc 1.000000\n");
            fprintf(fp, "fsub\n");
            fprintf(fp, "fstore %d\n", getAddress(level, (yyvsp[-1].s_val)));
        }
    }
#line 2268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 642 "compiler_hw3.y" /* yacc.c:1646  */
    { create_symbol(); }
#line 2274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 642 "compiler_hw3.y" /* yacc.c:1646  */
    { dump_symbol(); }
#line 2280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 646 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        fprintf(fp, "ifeq ");
        getLabel(labelIndex);
     }
#line 2289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 649 "compiler_hw3.y" /* yacc.c:1646  */
    {
        fprintf(fp, "goto ");
        getLabel(labelIndex+1);
        creatLabel();
     }
#line 2299 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 655 "compiler_hw3.y" /* yacc.c:1646  */
    {
        creatLabel();
    }
#line 2307 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 659 "compiler_hw3.y" /* yacc.c:1646  */
    {
        creatLabel();
    }
#line 2315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 665 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        if(print_type != 3) {
            if(print_type == 1) {
                printf("error:%d: non-bool (type int32) used as for condition\n", linnn); 
                HAS_ERROR = 1;
            }
            else if(print_type == 2) {
                printf("error:%d: non-bool (type float32) used as for condition\n", linnn); 
                HAS_ERROR = 1;
            }
            else if(print_type == 4) {
                printf("error:%d: non-bool (type string) used as for condition\n", linnn); 
                HAS_ERROR = 1;
            }
        }
        print_type = 0;
    }
#line 2337 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 685 "compiler_hw3.y" /* yacc.c:1646  */
    { creatStackLabel(whileIndex++); }
#line 2343 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 685 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(forFlag == 0) {
            fprintf(fp, "ifeq asd");
            getStackLabel(stackIndex++);
        }
        else {
            fprintf(fp, "block");
            creatStackLabel(--blockIndex);
            fprintf(fp, "ifeq condition");
            getStackLabel(conditionIndex++);
            blockIndex++;
            beginIndex++;
        }
        preForFlag[preForFlagIndex++] = forFlag;

    }
#line 2364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 700 "compiler_hw3.y" /* yacc.c:1646  */
    {
        forFlag = preForFlag[--preForFlagIndex];
        if(forFlag == 0) {
            fprintf(fp, "goto ");
            getStackLabel(--whileIndex);
            fprintf(fp, "asd");
            creatStackLabel(--stackIndex);
            if(preForFlagIndex == 0) {
                stackIndex += 10;
                whileIndex += 10;
            }
        }
        else {
            --whileIndex;
            fprintf(fp, "goto post");
            getStackLabel(--postIndex);
            fprintf(fp, "condition");
            creatStackLabel(--conditionIndex);
            if(preForFlagIndex == 0) {
                beginIndex += 10;
                blockIndex += 10;
                postIndex += 10;
                conditionIndex += 10;
            }
        }
        
    }
#line 2396 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 730 "compiler_hw3.y" /* yacc.c:1646  */
    {forFlag = 0;}
#line 2402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 731 "compiler_hw3.y" /* yacc.c:1646  */
    { forFlag = 1; fprintf(fp, "begin"); creatStackLabel(beginIndex++); }
#line 2408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 731 "compiler_hw3.y" /* yacc.c:1646  */
    { fprintf(fp, "goto block"); getStackLabel(blockIndex++); fprintf(fp, "post"); creatStackLabel(postIndex++); }
#line 2414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 731 "compiler_hw3.y" /* yacc.c:1646  */
    { fprintf(fp, "goto begin"); getStackLabel(--beginIndex); }
#line 2420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 743 "compiler_hw3.y" /* yacc.c:1646  */
    { RHS = 1; }
#line 2426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 744 "compiler_hw3.y" /* yacc.c:1646  */
    {   printf("PRINT ");
        if(print_type == 1) {
            printf("int32\n");
            fprintf(fp, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            fprintf(fp, "swap\n");
            fprintf(fp, "invokevirtual java/io/PrintStream/print(I)V\n");
        }
        else if(print_type == 2) {
            printf("float32\n"); 
            fprintf(fp, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            fprintf(fp, "swap\n");
            fprintf(fp, "invokevirtual java/io/PrintStream/print(F)V\n");
        }
        else if(print_type == 3) {
            printf("bool\n");
            fprintf(fp, "ifne ");
            getLabel(labelIndex);
            fprintf(fp, "ldc \"false\"\n");
            fprintf(fp, "goto ");
            getLabel(labelIndex+1);
            creatLabel();
            fprintf(fp, "ldc \"true\"\n");
            creatLabel();
            fprintf(fp, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            fprintf(fp, "swap\n");
            fprintf(fp, "invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
        }
        else if(print_type == 4) {
            printf("string\n");
            fprintf(fp, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            fprintf(fp, "swap\n");
            fprintf(fp, "invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
        }
        arrayFlag = 0;
        print_type = 0;
    }
#line 2467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 780 "compiler_hw3.y" /* yacc.c:1646  */
    { RHS = 1; }
#line 2473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 781 "compiler_hw3.y" /* yacc.c:1646  */
    {   printf("PRINTLN ");
        if(print_type == 1) {
            printf("int32\n");
            fprintf(fp, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            fprintf(fp, "swap\n");
            fprintf(fp, "invokevirtual java/io/PrintStream/println(I)V\n");
        }
        else if(print_type == 2) {
            printf("float32\n"); 
            fprintf(fp, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            fprintf(fp, "swap\n");
            fprintf(fp, "invokevirtual java/io/PrintStream/println(F)V\n");
        }
        else if(print_type == 3) {
            printf("bool\n");
            fprintf(fp, "ifne ");
            getLabel(labelIndex);
            fprintf(fp, "ldc \"false\"\n");
            fprintf(fp, "goto ");
            getLabel(labelIndex+1);
            creatLabel();
            fprintf(fp, "ldc \"true\"\n");
            creatLabel();
            fprintf(fp, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            fprintf(fp, "swap\n");
            fprintf(fp, "invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
        }
        else if(print_type == 4) {
            printf("string\n");
            fprintf(fp, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            fprintf(fp, "swap\n");
            fprintf(fp, "invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
        }
        arrayFlag = 0;
        print_type = 0;
    }
#line 2514 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2518 "y.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 821 "compiler_hw3.y" /* yacc.c:1906  */


/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    fp = fopen("hw3.j", "w");
    // gen code
    /////// 
    fprintf(fp, ".source hw3.j\n");
    fprintf(fp, ".class public Main\n");
    fprintf(fp, ".super java/lang/Object\n");
    fprintf(fp, ".method public static main([Ljava/lang/String;)V\n");
    fprintf(fp, ".limit stack 100 ; Define your storage size.\n");
    fprintf(fp, ".limit locals 100 ; Define your local space number.\n\n");
    ///////

    ///////
    for(i=0;i<30;i++) {
        tableIndex[i] = 0;
        table[i].level = -1;
    }
    ///////

    yylineno = 0;
    yyparse();

	printf("Total lines: %d\n", yylineno);

    // gen code
    /////// 
    fprintf(fp, "\nreturn\n");
    fprintf(fp, ".end method\n");
    ///////


    fclose(yyin);
    fclose(fp);
    if (HAS_ERROR) {
        remove("hw3.j");
    }

    return 0;
}

static void create_symbol() {
    level++;
}

static void insert_symbol(int index, char* name, char* type, int address, int line, char* element_type) {
    // error redeclared
    int i;
    int flag = 0;
    for(i=0;i<30;i++) {
        if(table[i].level == level) {
            if(strcmp(table[i].name, name) == 0) {
                // error
                printf("error:%d: %s redeclared in this block. previous declaration at line %d\n", yylineno, table[i].name, table[i].lineno);
                HAS_ERROR = 1;
                flag = 1;
            }
        }
    }
    if (!flag) {
        table[address].index = index;
        strcpy(table[address].name, name);
        strcpy(table[address].type, type);
        table[address].address = address;
        table[address].lineno = line;
        strcpy(table[address].element_type, element_type);
        table[address].level = level;
        printf("> Insert {%s} into symbol table (scope level: %d)\n", table[address].name, level);
    }

    //////
    if(strcmp(table[address].type, "array") == 0) {
        fprintf(fp, "newarray ");
        if(strcmp(table[address].element_type, "int32") == 0) {
            fprintf(fp, "int\n");
            fprintf(fp, "astore %d\n", getAddress(level, table[address].name));
        }
        else if(strcmp(table[address].element_type, "float32") == 0) {
            fprintf(fp, "float\n");
            fprintf(fp, "astore %d\n", getAddress(level, table[address].name));
        }
    }
    else if(strcmp(table[address].type, "int32") == 0) {
        if(!isInitial)
            fprintf(fp, "ldc 0\n");
        fprintf(fp, "istore %d\n", getAddress(level, table[address].name));
    }
    else if(strcmp(table[address].type, "float32") == 0) {
        if(!isInitial)
            fprintf(fp, "ldc 0.0\n");
        fprintf(fp, "fstore %d\n", getAddress(level, table[address].name));
    }
    else if(strcmp(table[address].type, "string") == 0) {
        if(!isInitial)
            fprintf(fp, "ldc \"\"\n");
        fprintf(fp, "astore %d\n", getAddress(level, table[address].name));
    }
    else if(strcmp(table[address].type, "bool") == 0) {
        if(!isInitial)
            fprintf(fp, "iconst_0\n");
        fprintf(fp, "istore %d\n", getAddress(level, table[address].name));
    }
    
}

static void lookup_symbol(int level, char *name) {
    int i;
    int index = level;
    while(index >= 0){
        for(i=0;i<30;i++) {
            if(table[i].level == index) {
                if(strcmp(table[i].name, name) == 0) {
                    printf("IDENT (name=%s, address=%d)\n", table[i].name, table[i].address);
                    if((strcmp(table[i].type, "int32") == 0 || strcmp(table[i].element_type, "int32") == 0) && print_type <= 1) {
                        print_type = 1;
                        if(!LHS) {
                            if(strcmp(table[i].type, "array") == 0) {
                                fprintf(fp, "aload %d\n", getAddress(level, name));
                            }
                            else {
                                fprintf(fp, "iload %d\n", getAddress(level, name));
                            }
                        }
                        
                    }
                    else if((strcmp(table[i].type, "float32") == 0 || strcmp(table[i].element_type, "float32") == 0) && print_type <= 2) {
                        print_type = 2;
                        if(!LHS) {
                            if(strcmp(table[i].type, "array") == 0) {
                                fprintf(fp, "aload %d\n", getAddress(level, name));
                            }
                            else {
                                fprintf(fp, "fload %d\n", getAddress(level, name));
                            }
                        }
                    }
                    else if((strcmp(table[i].type, "bool") == 0 || strcmp(table[i].element_type, "bool") == 0) && print_type <= 3) {
                        print_type = 3;
                        if(!LHS) {
                            if(strcmp(table[i].type, "array") == 0) {
                                fprintf(fp, "aload %d\n", getAddress(level, name));
                            }
                            else {
                                fprintf(fp, "iload %d\n", getAddress(level, name));
                            }
                        }
                    }
                    else if((strcmp(table[i].type, "string") == 0 || strcmp(table[i].element_type, "string") == 0) && print_type != 4) {
                        print_type = 4;
                        if(!LHS) {
                            fprintf(fp, "aload %d\n", getAddress(level, name));
                        }
                    }
                    return;
                } 
            }
        }
        index--;
    }

    // error msg here (undefined)
    printf("error:%d: undefined: %s\n", linnn, name);
    HAS_ERROR = 1;
}

static char* getType(int level, char *name) {
    int i;
    int index = level;
    while(index >= 0){
        for(i=0;i<30;i++) {
            if(table[i].level == index) {
                if(strcmp(table[i].name, name) == 0) {
                    printf("IDENT (name=%s, address=%d)\n", table[i].name, table[i].address);
                    if((strcmp(table[i].type, "int32") == 0 || strcmp(table[i].element_type, "int32") == 0) && print_type <= 1) {
                        print_type = 1;
                    }
                    else if((strcmp(table[i].type, "float32") == 0 || strcmp(table[i].element_type, "float32") == 0) && print_type <= 2) {
                        print_type = 2;
                    }
                    else if((strcmp(table[i].type, "bool") == 0 || strcmp(table[i].element_type, "bool") == 0) && print_type <= 3) {
                        print_type = 3;
                    }
                    else if((strcmp(table[i].type, "string") == 0 || strcmp(table[i].element_type, "string") == 0) && print_type != 4) {
                        print_type = 4;
                    }
                    return table[i].type;
                } 
            }
        }
        index--;
    }
    return "";
}

static char* getArrayType(int level, char *name) {
    int i;
    int index = level;
    while(index >= 0){
        for(i=0;i<30;i++) {
            if(table[i].level == index) {
                if(strcmp(table[i].name, name) == 0) {
                    printf("IDENT (name=%s, address=%d)\n", table[i].name, table[i].address);
                    if((strcmp(table[i].type, "int32") == 0 || strcmp(table[i].element_type, "int32") == 0) && print_type <= 1) {
                        print_type = 1;
                    }
                    else if((strcmp(table[i].type, "float32") == 0 || strcmp(table[i].element_type, "float32") == 0) && print_type <= 2) {
                        print_type = 2;
                    }
                    else if((strcmp(table[i].type, "bool") == 0 || strcmp(table[i].element_type, "bool") == 0) && print_type <= 3) {
                        print_type = 3;
                    }
                    else if((strcmp(table[i].type, "string") == 0 || strcmp(table[i].element_type, "string") == 0) && print_type != 4) {
                        print_type = 4;
                    }
                    return table[i].element_type;
                } 
            }
        }
        index--;
    }
    return "";
}

static char* getLiteralType(char str[]) {
    int i;
    if(strncmp(str, "ldc", 3) == 0) {
        // string
        if(str[4] == '\"') return "string";

        // float32
        for(i=4;i<strlen(str);i++) {
            if(str[i] == '.') return "float32";
        }

        // int32
        return "int32";
    }
    else {
        return "";  // not a literal
    }
}

static int getAddress(int level, char *name) {
    int i;
    int index = level;
    while(index >= 0){
        for(i=0;i<30;i++) {
            if(table[i].level == index) {
                if(strcmp(table[i].name, name) == 0) {
                    printf("IDENT (name=%s, address=%d)\n", table[i].name, table[i].address);
                    if((strcmp(table[i].type, "int32") == 0 || strcmp(table[i].element_type, "int32") == 0) && print_type <= 1) {
                        print_type = 1;
                    }
                    else if((strcmp(table[i].type, "float32") == 0 || strcmp(table[i].element_type, "float32") == 0) && print_type <= 2) {
                        print_type = 2;
                    }
                    else if((strcmp(table[i].type, "bool") == 0 || strcmp(table[i].element_type, "bool") == 0) && print_type <= 3) {
                        print_type = 3;
                    }
                    else if((strcmp(table[i].type, "string") == 0 || strcmp(table[i].element_type, "string") == 0) && print_type != 4) {
                        print_type = 4;
                    }
                    return table[i].address;
                } 
            }
        }
        index--;
    }
    return -1;
}

static void dump_symbol() {
    int i;
    printf("> Dump symbol table (scope level: %d)\n", level);
    printf("%-10s%-10s%-10s%-10s%-10s%s\n",
           "Index", "Name", "Type", "Address", "Lineno", "Element type");
    
    for(i=0;i<30;i++) {
        if(table[i].level == level) {
            printf("%-10d%-10s%-10s%-10d%-10d%s\n",
                table[i].index, table[i].name, table[i].type, table[i].address, table[i].lineno, table[i].element_type);
            table[i].level = -1;
        }
    }
    tableIndex[level] = 0;
    level--;
}

static char* conversion(char a[], int p) {
    strcpy(convert_str, "");

    if(p == 1) {
        strcat(convert_str, "I to ");
    }
    else if(p == 2) {
        strcat(convert_str, "F to ");
    }

    if(strcmp(a, "int32") == 0) {
        strcat(convert_str, "I");
    }
    else if(strcmp(a, "float32") == 0) {
        strcat(convert_str, "F");
    }

    if(strcmp(convert_str, "I to F") == 0) {
        strcpy(convert_str, "i2f");
    }
    else if(strcmp(convert_str, "F to I") == 0) {
        strcpy(convert_str, "f2i");
    }

    return convert_str;
}

static void error_check(char a[], char b[], char operator[]) {
    int i;
    int index = level;
    int typeIndex1 = 0;
    int typeIndex2 = 0;
    int flagLIT1 = 0;
    int flagLIT2 = 0;
    while(index >= 0){
        int flag = 0;
        for(i=0;i<30;i++) {
            if(table[i].level == index) {
                if(strcmp(table[i].name, a) == 0) {
                    if(strcmp(table[i].type, "int32") == 0 || strcmp(table[i].element_type, "int32") == 0) {
                        typeIndex1 = 1;
                    }
                    else if(strcmp(table[i].type, "float32") == 0 || strcmp(table[i].element_type, "float32") == 0) {
                        typeIndex1 = 2;
                    }
                    flagLIT1 = 1;
                    flag = 1;
                    break;
                } 
            }
        }
        if(flag)
            break;
        index--;
    }

    index = level;

    while(index >= 0){
        int flag = 0;
        for(i=0;i<30;i++) {
            if(table[i].level == index) {
                if(strcmp(table[i].name, b) == 0) {
                    if(strcmp(table[i].type, "int32") == 0 || strcmp(table[i].element_type, "int32") == 0) {
                        typeIndex2 = 1;
                    }
                    else if(strcmp(table[i].type, "float32") == 0 || strcmp(table[i].element_type, "float32") == 0) {
                        typeIndex2 = 2;
                    }
                    flagLIT2 = 1;
                    flag = 1;
                    break;
                } 
            }
        }
        if(flag)
            break;
        index--;
    }

    // literal
    
    /*
    if(flagLIT1 == 0 && (strcmp(a, "int32") != 0) && (strcmp(b, "int32") != 0) && (strcmp(a, "float32") != 0) && (strcmp(b, "float32") != 0)) {
        printf("TTTTEEEEE\n%s\n%s\n",a,b);
        printf("%s\n%s\n",errorLIT1,errorLIT2);
        if(strcmp(getLiteralType(errorLIT1), "int32") == 0) {
            typeIndex1 = 1;
        }
        else if(strcmp(getLiteralType(errorLIT1), "float32") == 0) {
            typeIndex1 = 2;
        }
    }
    if(flagLIT2 == 0 && (strcmp(a, "int32") != 0) && (strcmp(b, "int32") != 0) && (strcmp(a, "float32") != 0) && (strcmp(b, "float32") != 0)) {
        printf("2222222\n%s\n%s\n",a,b);
        printf("%s\n%s\n",errorLIT1,errorLIT2);
        if(flagLIT1 != 0) {
            if(strcmp(getLiteralType(errorLIT1), "int32") == 0) {
                typeIndex2 = 1;
            }
            else if(strcmp(getLiteralType(errorLIT1), "float32") == 0) {
                typeIndex2 = 2;
            }
        }
        else {
            if(strcmp(getLiteralType(errorLIT2), "int32") == 0) {
                typeIndex2 = 1;
            }
            else if(strcmp(getLiteralType(errorLIT2), "float32") == 0) {
                typeIndex2 = 2;
            }
        }
        
    }
    */

    if(flagLIT1 == 0) {
        if(strcmp(getLiteralType(a), "int32") == 0) {
            typeIndex1 = 1;
        }
        else if(strcmp(getLiteralType(a), "float32") == 0) {
            typeIndex1 = 2;
        }
    }
    if(flagLIT2 == 0) {
        if(strcmp(getLiteralType(b), "int32") == 0) {
            typeIndex2 = 1;
        }
        else if(strcmp(getLiteralType(b), "float32") == 0) {
            typeIndex2 = 2;
        }
    }

    // conversion condition
    if(typeIndex1 == 0) {
        if(strcmp(a, "int32") == 0) {
            typeIndex1 = 1;
        }
        else if(strcmp(a, "float32") == 0) {
            typeIndex1 = 2;
        }
        else {
            typeIndex1 = typeIndex2;
        }
    }
    if(typeIndex2 == 0) {
        if(strcmp(b, "int32") == 0) {
            typeIndex2 = 1;
        }
        else if(strcmp(b, "float32") == 0) {
            typeIndex2 = 2;
        }
        else {
            typeIndex2 = typeIndex1;
        }
    }

    // show message
    if(strcmp(operator, "REM") == 0 && (typeIndex1==2 || typeIndex2==2)) {
        printf("error:%d: invalid operation: (operator %s not defined on float32)\n", yylineno, operator);
        HAS_ERROR = 1;
    }
    else if((strcmp(operator, "LAND") == 0 || strcmp(operator, "LOR") == 0) && (typeIndex1==1 || typeIndex2==1) && !compareFlag) {
        if(print_type != 3) {
            printf("error:%d: invalid operation: (operator %s not defined on int32)\n", yylineno, operator);
            HAS_ERROR = 1;
        }
        else {
            if(typeIndex1 == 1 && compareFlag != 1)
                printf("error:%d: invalid operation: (operator %s not defined on int32)\n", yylineno, operator);
                HAS_ERROR = 1;
        }
        
    }
    else if((strcmp(operator, "LAND") == 0 || strcmp(operator, "LOR") == 0) && (typeIndex1==2 || typeIndex2==2) && !compareFlag) {
        if(print_type != 3) {
            printf("error:%d: invalid operation: (operator %s not defined on float32)\n", yylineno, operator);
            HAS_ERROR = 1;
        }
        else {
            if(typeIndex1 == 2 && compareFlag != 1)
                printf("error:%d: invalid operation: (operator %s not defined on float32)\n", yylineno, operator);
                HAS_ERROR = 1;
        }
    }
    else if(typeIndex1==1 && typeIndex2==2) {
        printf("error:%d: invalid operation: %s (mismatched types int32 and float32)\n", yylineno, operator);
        HAS_ERROR = 1;
    }
    else if(typeIndex1==2 && typeIndex2==1) {
        printf("error:%d: invalid operation: %s (mismatched types float32 and int32)\n", yylineno, operator);
        HAS_ERROR = 1;
    }
    
    // print jasmin code
    else if(print_type == 3) {
        if(strcmp(operator, "LAND") == 0) {
            fprintf(fp, "iand\n");
        }
        else if(strcmp(operator, "LOR") == 0) {
            fprintf(fp, "ior\n");
        }
    }
    else if(typeIndex1==1 && typeIndex2==1) {
        if(strcmp(operator, "ADD") == 0) {
            fprintf(fp, "iadd\n");
        }
        else if(strcmp(operator, "SUB") == 0) {
            fprintf(fp, "isub\n");
        }
        else if(strcmp(operator, "MUL") == 0) {
            fprintf(fp, "imul\n");
        }
        else if(strcmp(operator, "QUO") == 0) {
            fprintf(fp, "idiv\n");
        }
        else if(strcmp(operator, "REM") == 0) {
            fprintf(fp, "irem\n");
        }
        else if(strcmp(operator, "EQL") == 0) {
            fprintf(fp, "isub\n");
            fprintf(fp, "ifeq ");
            getLabel(labelIndex);
            fprintf(fp, "iconst_0\n");
            fprintf(fp, "goto ");
            getLabel(labelIndex+1);
            creatLabel();
            fprintf(fp, "iconst_1\n");
            creatLabel();
        }
        else if(strcmp(operator, "NEQ") == 0) {
            fprintf(fp, "isub\n");
            fprintf(fp, "ifeq ");
            getLabel(labelIndex);
            fprintf(fp, "iconst_1\n");
            fprintf(fp, "goto ");
            getLabel(labelIndex+1);
            creatLabel();
            fprintf(fp, "iconst_0\n");
            creatLabel();
        }
        else if(strcmp(operator, "LSS") == 0) {
            fprintf(fp, "isub\n");
            fprintf(fp, "iflt ");
            getLabel(labelIndex);
            fprintf(fp, "iconst_0\n");
            fprintf(fp, "goto ");
            getLabel(labelIndex+1);
            creatLabel();
            fprintf(fp, "iconst_1\n");
            creatLabel();
        }
        else if(strcmp(operator, "LEQ") == 0) {
            fprintf(fp, "isub\n");
            fprintf(fp, "ifle ");
            getLabel(labelIndex);
            fprintf(fp, "iconst_0\n");
            fprintf(fp, "goto ");
            getLabel(labelIndex+1);
            creatLabel();
            fprintf(fp, "iconst_1\n");
            creatLabel();
        }
        else if(strcmp(operator, "GTR") == 0) {
            fprintf(fp, "isub\n");
            fprintf(fp, "ifgt ");
            getLabel(labelIndex);
            fprintf(fp, "iconst_0\n");
            fprintf(fp, "goto ");
            getLabel(labelIndex+1);
            creatLabel();
            fprintf(fp, "iconst_1\n");
            creatLabel();
        }
        else if(strcmp(operator, "GEQ") == 0) {
            fprintf(fp, "isub\n");
            fprintf(fp, "ifge ");
            getLabel(labelIndex);
            fprintf(fp, "iconst_0\n");
            fprintf(fp, "goto ");
            getLabel(labelIndex+1);
            creatLabel();
            fprintf(fp, "iconst_1\n");
            creatLabel();
        }
    }
    else if(typeIndex1==2 && typeIndex2==2) {
        if(strcmp(operator, "ADD") == 0) {
            fprintf(fp, "fadd\n");
        }
        else if(strcmp(operator, "SUB") == 0) {
            fprintf(fp, "fsub\n");
        }
        else if(strcmp(operator, "MUL") == 0) {
            fprintf(fp, "fmul\n");
        }
        else if(strcmp(operator, "QUO") == 0) {
            fprintf(fp, "fdiv\n");
        }
        else if(strcmp(operator, "EQL") == 0) {
            fprintf(fp, "fcmpl\n");
            fprintf(fp, "ifeq ");
            getLabel(labelIndex);
            fprintf(fp, "iconst_0\n");
            fprintf(fp, "goto ");
            getLabel(labelIndex+1);
            creatLabel();
            fprintf(fp, "iconst_1\n");
            creatLabel();
        }
        else if(strcmp(operator, "NEQ") == 0) {
            fprintf(fp, "fcmpl\n");
            fprintf(fp, "ifeq ");
            getLabel(labelIndex);
            fprintf(fp, "iconst_1\n");
            fprintf(fp, "goto ");
            getLabel(labelIndex+1);
            creatLabel();
            fprintf(fp, "iconst_0\n");
            creatLabel();
        }
        else if(strcmp(operator, "LSS") == 0) {
            fprintf(fp, "fcmpl\n");
            fprintf(fp, "iflt ");
            getLabel(labelIndex);
            fprintf(fp, "iconst_0\n");
            fprintf(fp, "goto ");
            getLabel(labelIndex+1);
            creatLabel();
            fprintf(fp, "iconst_1\n");
            creatLabel();
        }
        else if(strcmp(operator, "LEQ") == 0) {
            fprintf(fp, "fcmpl\n");
            fprintf(fp, "ifle ");
            getLabel(labelIndex);
            fprintf(fp, "iconst_0\n");
            fprintf(fp, "goto ");
            getLabel(labelIndex+1);
            creatLabel();
            fprintf(fp, "iconst_1\n");
            creatLabel();
        }
        else if(strcmp(operator, "GTR") == 0) {
            fprintf(fp, "fcmpl\n");
            fprintf(fp, "ifgt ");
            getLabel(labelIndex);
            fprintf(fp, "iconst_0\n");
            fprintf(fp, "goto ");
            getLabel(labelIndex+1);
            creatLabel();
            fprintf(fp, "iconst_1\n");
            creatLabel();
        }
        else if(strcmp(operator, "GEQ") == 0) {
            fprintf(fp, "fcmpl\n");
            fprintf(fp, "ifge ");
            getLabel(labelIndex);
            fprintf(fp, "iconst_0\n");
            fprintf(fp, "goto ");
            getLabel(labelIndex+1);
            creatLabel();
            fprintf(fp, "iconst_1\n");
            creatLabel();
        }
    }
    printf("%d\n%d\n%s\n%s\n", typeIndex1, typeIndex2, b, operator);
}

static void creatLabel() {
    char str[25] = "label";
    char buffer[25];
    char colon[2] = ":";
    sprintf(buffer, "%d", labelIndex++);
    strcat(strcat(str, buffer), colon);
    fprintf(fp, "%s\n", str);
}

static void getLabel(int labelIndex) {
    char str[25] = "label";
    char buffer[25];
    sprintf(buffer, "%d", labelIndex);
    strcat(str, buffer);
    fprintf(fp, "%s\n", str);
}

static void creatStackLabel(int index) {
    char str[25] = "stacklabel";
    char buffer[25];
    char colon[2] = ":";
    sprintf(buffer, "%d", index);
    strcat(strcat(str, buffer), colon);
    fprintf(fp, "%s\n", str);
}

static void getStackLabel(int index) {
    char str[25] = "stacklabel";
    char buffer[25];
    sprintf(buffer, "%d", index);
    strcat(str, buffer);
    fprintf(fp, "%s\n", str);
}
