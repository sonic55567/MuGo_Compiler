/* Definition section */
%{
    #include "common.h"
    #include "y.tab.h"	/* header file generated by bison */
    extern YYSTYPE yylval;

    #define YY_NO_UNPUT
    #define YY_NO_INPUT
%}

/* Define regular expression label */
letter [a-zA-Z_]
digit [0-9]
id {letter}+({letter}|{digit})*
inumber {digit}+
fnumber ({digit}*\.{digit}+)

%x CMT
%x STR
%option yylineno

/* Rules section */
%%

"/*"        { BEGIN(CMT); }
<CMT>"*/"   { BEGIN(INITIAL); }
<CMT>\n     {;}
<CMT>.      {;}
"//".*      {;}
"\""        { BEGIN(STR);
                return '"';
            }
<STR>"\""   { BEGIN(INITIAL);
                return '"';
            }
<STR>[^\"]* { yylval.s_val = strdup(yytext);
                return STRING_LIT;
            }
"+"         { yylval.s_val = "ADD";
                return '+';
            }
"-"         { yylval.s_val = "SUB";
                return '-'; 
            }
"*"         { yylval.s_val = "MUL";
                return '*'; 
            }
"/"         { yylval.s_val = "QUO";
                return '/'; 
            }
"%"         { yylval.s_val = "REM";
                return '%'; 
            }
"++"        { yylval.s_val = "INC";
                return INC; 
            }
"--"        { yylval.s_val = "DEC";
                return DEC; 
            }

">"         { yylval.s_val = "GTR";
                return '>'; 
            }
"<"         { yylval.s_val = "LSS";
                return '>'; 
            }
">="        { yylval.s_val = "GEQ";
                return GEQ; 
            }
"<="        { yylval.s_val = "LEQ";
                return LEQ; 
            }
"=="        { yylval.s_val = "EQL";
                return EQL; 
            }
"!="        { yylval.s_val = "NEQ";
                return NEQ; 
            }

"="         { yylval.s_val = "ASSIGN";
                return '='; 
            }
"+="        { yylval.s_val = "ADD_ASSIGN";
                return ADD_ASSIGN; 
            }
"-="        { yylval.s_val = "SUB_ASSIGN";
                return SUB_ASSIGN; 
            }
"*="        { yylval.s_val = "MUL_ASSIGN";
                return MUL_ASSIGN; 
            }
"/="        { yylval.s_val = "QUO_ASSIGN";
                return QUO_ASSIGN; 
            }
"%="        { yylval.s_val = "REM_ASSIGN";
                return REM_ASSIGN; 
            }

"&&"        { yylval.s_val = "LAND";
                return LAND; 
            }
"||"        { yylval.s_val = "LOR";
                return LOR; 
            }
"!"         { yylval.s_val = "NOT";
                return '!'; 
            }

"("         { return '('; }
")"         { return ')'; }
"["         { return '['; }
"]"         { return ']'; }
"{"         { return '{'; }
"}"         { return '}'; }

";"         { return ';'; }
","         { return ','; }
"\n"        { return NEWLINE; }

"print"     { yylval.s_val = "PRINT";
                return PRINT; 
            }
"println"   { yylval.s_val = "PRINTLN";
                return PRINTLN; 
            }

"if"        { return IF; }
"else"      { return ELSE; }
"for"       { return FOR; }

"int32"     { yylval.s_val = strdup(yytext);
                return INT;
            }
"float32"   { yylval.s_val = strdup(yytext);
                return FLOAT;
            }
"string"    { yylval.s_val = strdup(yytext);
                return STRING;
            }
"bool"      { yylval.s_val = strdup(yytext);
                return BOOL;
            }
"true"      { yylval.s_val = strdup(yytext);
                return TRUE;
            }
"false"     { yylval.s_val = strdup(yytext);
                return FALSE;
            }
"var"       { return VAR; }

{inumber}   { yylval.i_val = atoi(yytext);
                return INT_LIT;
            }
{fnumber}   { yylval.f_val = atof(yytext);
                return FLOAT_LIT;
            }
{id}        { yylval.s_val = strdup(yytext);
                return ID;
            }

<<EOF>>     { static int once = 0;
                if (once++) {
                    yyterminate();
                }
                yylineno++;
                return NEWLINE;
            }
[ \t]+      {;}
.           {;}
%%

/*  C Code section */
int yywrap(void)
{
    return 1;
}
