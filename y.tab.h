/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 80 "compiler_hw3.y" /* yacc.c:1909  */

    int i_val;
    float f_val;
    char *s_val;
    char *type;
    /* ... */

#line 126 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
