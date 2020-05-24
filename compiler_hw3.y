/*	Definition section */
%{
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

%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    float f_val;
    char *s_val;
    char *type;
    /* ... */
}

/* Token without return */
%token VAR
%token '(' ')' '[' ']' '{' '}'
%token ';' ',' NEWLINE
%token IF ELSE FOR



/* Token with return, which need to sepcify type */
%token <s_val> INT FLOAT BOOL STRING ID  
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT
%token <s_val> TRUE FALSE
%token <s_val> STRING_LIT
%token <s_val> '=' ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN QUO_ASSIGN REM_ASSIGN
%token <s_val> '+' '-' '*' '/' '%' INC DEC
%token <s_val> '>' '<' GEQ LEQ EQL NEQ
%token <s_val> LAND LOR '!'
%token <s_val> PRINT PRINTLN

/* Nonterminal with return, which need to sepcify type */
%type <s_val> Type TypeName ArrayType
%type <s_val> PrintStmt Expression UnaryExpr PrimaryExpr Operand IndexExpr ConversionExpr AssignmentStmt
%type <s_val> unary_op

%left LOR
%left LAND
%left GEQ LEQ EQL NEQ '>' '<'
%left '+' '-'
%left '*' '/' '%'
%left '!'
%left INC DEC

/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%

Program     
    : { create_symbol(); } StatementList { dump_symbol(); }
;

StatementList
    : StatementList Statement
    | Statement
;

Type
    : TypeName
    | ArrayType
;

TypeName
    : INT   { $$ = $1; strcpy(element_type, "-"); }
    | FLOAT     { $$ = $1; strcpy(element_type, "-"); }
    | STRING    { $$ = $1; strcpy(element_type, "-"); }
    | BOOL      { $$ = $1; strcpy(element_type, "-"); }
;

ArrayType
    : '[' Expression ']' Type   { $$ = "array"; strcpy(element_type, $4); }
;

Expression
    : UnaryExpr
    | '"' Expression '"'    { $$ = $2; }
    | Expression '+' Expression    { error_check($1, $3, $2); printf("%s\n", $2); errorLITIndex = 0; compareFlag = 0; }
    | Expression '-' Expression    { error_check($1, $3, $2); printf("%s\n", $2); compareFlag = 0; }
    | Expression '*' Expression    { error_check($1, $3, $2); printf("%s\n", $2); compareFlag = 0; }
    | Expression '/' Expression    { error_check($1, $3, $2); printf("%s\n", $2); compareFlag = 0; }
    | Expression '%' Expression    { error_check($1, $3, $2); printf("%s\n", $2); compareFlag = 0; }
    | Expression EQL Expression    { error_check($1, $3, $2); printf("%s\n", $2); print_type = 3; compareFlag = 1; }
    | Expression NEQ Expression    { error_check($1, $3, $2); printf("%s\n", $2); print_type = 3; compareFlag = 1; }
    | Expression '<' Expression    { error_check($1, $3, $2); printf("%s\n", $2); print_type = 3; compareFlag = 1; }
    | Expression LEQ Expression    { error_check($1, $3, $2); printf("%s\n", $2); print_type = 3; compareFlag = 1; }
    | Expression '>' Expression    { error_check($1, $3, $2); printf("%s\n", $2); print_type = 3; compareFlag = 1; }
    | Expression GEQ Expression    { error_check($1, $3, $2); printf("%s\n", $2); print_type = 3; compareFlag = 1; }
    | Expression LOR Expression    { printf("123\n%s\n%s\n%s\n%d\n%d\n\n", $1, $2, $3, compareFlag, print_type); error_check($1, $3, $2); printf("%s\n", $2); print_type = 3; compareFlag = 1; }
    | Expression LAND Expression    { error_check($1, $3, $2); printf("%s\n", $2); print_type = 3; compareFlag = 1; }
;

UnaryExpr
    : PrimaryExpr
    | unary_op UnaryExpr    {
        printf("%s\n%s\n", $1, $2);
        $$ = $2;
        if(strcmp($1, "NOT") == 0) {
            fprintf(fp, "ixor\n");
        }
        else if(strcmp($1, "NEG") == 0) {
            if(strcmp(getType(level, $2), "") != 0) {  
                if(strcmp(getType(level, $2), "int32") == 0) {
                    fprintf(fp, "ineg\n");
                }
                else if(strcmp(getType(level, $2), "float32") == 0) {
                    fprintf(fp, "fneg\n");
                }
            }
            else {
                if(strcmp(getLiteralType($2), "int32") == 0) {
                    fprintf(fp, "ineg\n");
                }
                else if(strcmp(getLiteralType($2), "float32") == 0) {
                    fprintf(fp, "fneg\n");
                }
            }
        }
    }
;

unary_op
    : '+'   { $$ = "POS"; }
    | '-'   { $$ = "NEG"; }
    | '!'   { $$ = "NOT"; fprintf(fp, "iconst_1\n"); }
;

PrimaryExpr
    : Operand
    | IndexExpr
    | ConversionExpr
;

Operand
    : INT_LIT       { char str[25] = "ldc "; char buffer[25]; sprintf(buffer, "%d", $1); strcat(str, buffer); $$ = str; if(print_type <= 1) print_type = 1; printf("%s\n", str); fprintf(fp, "%s\n", str); if(errorLITIndex == 0) { strcpy(errorLIT1, str); errorLITIndex++; } else if (errorLITIndex == 1) { strcpy(errorLIT2, str); errorLITIndex = 0; } }
    | FLOAT_LIT     { char str[25] = "ldc "; char buffer[25]; sprintf(buffer, "%f", $1); strcat(str, buffer); $$ = str; if(print_type <= 2) print_type = 2; printf("%s\n", str); fprintf(fp, "%s\n", str); if(errorLITIndex == 0) { strcpy(errorLIT1, str); errorLITIndex++; } else if (errorLITIndex == 1) { strcpy(errorLIT2, str); errorLITIndex = 0; } }
    | TRUE          { $$ = "TRUE"; if(print_type <=3) print_type = 3; printf("%s\n", "iconst_1"); fprintf(fp, "%s\n", "iconst_1"); }
    | FALSE         { $$ = "FALSE"; if(print_type <=3) print_type = 3; printf("%s\n", "iconst_0"); fprintf(fp, "%s\n", "iconst_0"); }
    | STRING_LIT    { char str[25] = "ldc \""; strcat(strcat(str, $1), "\""); $$ = str; if(print_type != 4) print_type = 4; printf("%s\n", str); fprintf(fp, "%s\n", str); }
    | ID    { lookup_symbol(level, $1); }
    | '(' Expression ')'    { $$ = $2; }
;


IndexExpr
    : PrimaryExpr '[' Expression ']'    {
        $$ = $1;
        arrayFlag = 1;
        if(RHS)  {
            if(strcmp(getArrayType(level, $1), "int32") == 0) {
                fprintf(fp, "iaload\n");
            }
            else if(strcmp(getArrayType(level, $1), "float32") == 0) {
                fprintf(fp, "faload\n");
            }
            else if(strcmp(getArrayType(level, $1), "bool") == 0) {
                fprintf(fp, "iaload\n");
            }
            else if(strcmp(getArrayType(level, $1), "string") == 0) {
                fprintf(fp, "aaload\n");
            }
        }
    }
;


ConversionExpr
    : Type '(' { print_type = 0; } Expression ')'   {
        if(strcmp(conversion($1, print_type),"f2i") == 0) {
            fprintf(fp, "%s\n", conversion($1, print_type));
            print_type = 1;
        }
        else if(strcmp(conversion($1, print_type),"i2f") == 0) {
            fprintf(fp, "%s\n", conversion($1, print_type));
            print_type = 2;
        }
        
    }
;

Statement
    : DeclarationStmt NEWLINE   { linnn++; }
    | SimpleStmt NEWLINE    { linnn++; print_type = 0; }
    | Block NEWLINE     { linnn++; }
    | IfStmt NEWLINE    { linnn++; creatLabel(); }
    | ForStmt NEWLINE   { linnn++; }
    | PrintStmt NEWLINE { linnn++; RHS = 0; }
    | NEWLINE   { linnn++; }
;

SimpleStmt
    : AssignmentStmt    { RHS = 0; if(!arrayFlag) fprintf(fp, "pop\n"); arrayFlag = 0; }
    | ExpressionStmt    { arrayFlag = 0; }
    | IncDecStmt        { arrayFlag = 0; }
;

DeclarationStmt
    : VAR ID Type   { isInitial = 0; insert_symbol(tableIndex[level]++, $2, $3, address++, yylineno, element_type); print_type = 0; }
    | VAR ID Type '=' Expression    { isInitial = 1; insert_symbol(tableIndex[level]++, $2, $3, address++, yylineno, element_type); print_type = 0; }
;

AssignmentStmt
    : Expression '=' { RHS = 1; } Expression   {

        if(strcmp(getLiteralType($1), "int32") == 0) {
            printf("error:%d: cannot assign to int32\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getLiteralType($1), "float32") == 0) {
            printf("error:%d: cannot assign to float32\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getLiteralType($1), "string") == 0) {
            printf("error:%d: cannot assign to string\n", yylineno);
            HAS_ERROR = 1;
        }
        else if((strncmp($1, "TRUE", 4) == 0) || (strncmp($1, "FALSE", 5) == 0)) {
            printf("error:%d: cannot assign to bool\n", yylineno);
            HAS_ERROR = 1;
        }
        
        
        if(strcmp(getType(level, $1), "array") == 0) {
            if(strcmp(getArrayType(level, $1), "int32") == 0) {
                fprintf(fp, "iastore\n");
            }
            else if(strcmp(getArrayType(level, $1), "float32") == 0) {
                fprintf(fp, "fastore\n");
            }
            else if(strcmp(getArrayType(level, $1), "string") == 0) {
                fprintf(fp, "aastore\n");
            }
            else if(strcmp(getArrayType(level, $1), "bool") == 0) {
                fprintf(fp, "iastore\n");
            }
        }
        else if(strcmp(getType(level, $1), "int32") == 0) {
            fprintf(fp, "istore %d\n", getAddress(level, $1));
        }
        else if(strcmp(getType(level, $1), "float32") == 0) {
            fprintf(fp, "fstore %d\n", getAddress(level, $1));
        }
        else if(strcmp(getType(level, $1), "string") == 0) {
            fprintf(fp, "astore %d\n", getAddress(level, $1));
        }
        else if(strcmp(getType(level, $1), "bool") == 0) {
            fprintf(fp, "istore %d\n", getAddress(level, $1));
        }
        RHS = 0;
    }
    | Expression ADD_ASSIGN { RHS = 1; lookup_symbol(level, $1); } Expression    { 
        if(strcmp(getLiteralType($1), "int32") == 0) {
            printf("error:%d: cannot assign to int32\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getLiteralType($1), "float32") == 0) {
            printf("error:%d: cannot assign to float32\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getLiteralType($1), "string") == 0) {
            printf("error:%d: cannot assign to string\n", yylineno);
            HAS_ERROR = 1;
        }
        else if((strncmp($1, "TRUE", 4) == 0) || (strncmp($1, "FALSE", 5) == 0)) {
            printf("error:%d: cannot assign to bool\n", yylineno);
            HAS_ERROR = 1;
        }
        
        if(strcmp(getType(level, $1), "array") == 0) {
            if(strcmp(getArrayType(level, $1), "int32") == 0) {
                fprintf(fp, "iadd\n");
                fprintf(fp, "iastore\n");
            }
            else if(strcmp(getArrayType(level, $1), "float32") == 0) {
                fprintf(fp, "fadd\n");
                fprintf(fp, "fastore\n");
            }
            else if(strcmp(getArrayType(level, $1), "string") == 0) {
                printf("error:%d: cannot add to string\n", yylineno);
                HAS_ERROR = 1;
            }
            else if(strcmp(getArrayType(level, $1), "bool") == 0) {
                printf("error:%d: cannot add to bool\n", yylineno);
                HAS_ERROR = 1;
            }
        }
        else if(strcmp(getType(level, $1), "int32") == 0) {
            fprintf(fp, "iadd\n");
            fprintf(fp, "istore %d\n", getAddress(level, $1));
        }
        else if(strcmp(getType(level, $1), "float32") == 0) {
            fprintf(fp, "fadd\n");
            fprintf(fp, "fstore %d\n", getAddress(level, $1));
        }
        else if(strcmp(getType(level, $1), "string") == 0) {
            printf("error:%d: cannot add to string\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getType(level, $1), "bool") == 0) {
            printf("error:%d: cannot add to bool\n", yylineno);
            HAS_ERROR = 1;
        }
        RHS = 0;
    }  
    | Expression SUB_ASSIGN { RHS = 1; lookup_symbol(level, $1); } Expression    { 
        if(strcmp(getLiteralType($1), "int32") == 0) {
            printf("error:%d: cannot assign to int32\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getLiteralType($1), "float32") == 0) {
            printf("error:%d: cannot assign to float32\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getLiteralType($1), "string") == 0) {
            printf("error:%d: cannot assign to string\n", yylineno);
            HAS_ERROR = 1;
        }
        else if((strncmp($1, "TRUE", 4) == 0) || (strncmp($1, "FALSE", 5) == 0)) {
            printf("error:%d: cannot assign to bool\n", yylineno);
            HAS_ERROR = 1;
        }
        
        if(strcmp(getType(level, $1), "array") == 0) {
            if(strcmp(getArrayType(level, $1), "int32") == 0) {
                fprintf(fp, "isub\n");
                fprintf(fp, "iastore\n");
            }
            else if(strcmp(getArrayType(level, $1), "float32") == 0) {
                fprintf(fp, "fsub\n");
                fprintf(fp, "fastore\n");
            }
            else if(strcmp(getArrayType(level, $1), "string") == 0) {
                printf("error:%d: cannot sub to string\n", yylineno);
                HAS_ERROR = 1;
            }
            else if(strcmp(getArrayType(level, $1), "bool") == 0) {
                printf("error:%d: cannot sub to bool\n", yylineno);
                HAS_ERROR = 1;
            }
        }
        else if(strcmp(getType(level, $1), "int32") == 0) {
            fprintf(fp, "isub\n");
            fprintf(fp, "istore %d\n", getAddress(level, $1));
        }
        else if(strcmp(getType(level, $1), "float32") == 0) {
            fprintf(fp, "fsub\n");
            fprintf(fp, "fstore %d\n", getAddress(level, $1));
        }
        else if(strcmp(getType(level, $1), "string") == 0) {
            printf("error:%d: cannot sub to string\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getType(level, $1), "bool") == 0) {
            printf("error:%d: cannot sub to bool\n", yylineno);
            HAS_ERROR = 1;
        }
        RHS = 0;
    } 
    | Expression MUL_ASSIGN { RHS = 1; lookup_symbol(level, $1); } Expression    { 
        if(strcmp(getLiteralType($1), "int32") == 0) {
            printf("error:%d: cannot assign to int32\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getLiteralType($1), "float32") == 0) {
            printf("error:%d: cannot assign to float32\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getLiteralType($1), "string") == 0) {
            printf("error:%d: cannot assign to string\n", yylineno);
            HAS_ERROR = 1;
        }
        else if((strncmp($1, "TRUE", 4) == 0) || (strncmp($1, "FALSE", 5) == 0)) {
            printf("error:%d: cannot assign to bool\n", yylineno);
            HAS_ERROR = 1;
        }
        
        if(strcmp(getType(level, $1), "array") == 0) {
            if(strcmp(getArrayType(level, $1), "int32") == 0) {
                fprintf(fp, "imul\n");
                fprintf(fp, "iastore\n");
            }
            else if(strcmp(getArrayType(level, $1), "float32") == 0) {
                fprintf(fp, "fmul\n");
                fprintf(fp, "fastore\n");
            }
            else if(strcmp(getArrayType(level, $1), "string") == 0) {
                printf("error:%d: cannot mul to string\n", yylineno);
                HAS_ERROR = 1;
            }
            else if(strcmp(getArrayType(level, $1), "bool") == 0) {
                printf("error:%d: cannot mul to bool\n", yylineno);
                HAS_ERROR = 1;
            }
        }
        else if(strcmp(getType(level, $1), "int32") == 0) {
            fprintf(fp, "imul\n");
            fprintf(fp, "istore %d\n", getAddress(level, $1));
        }
        else if(strcmp(getType(level, $1), "float32") == 0) {
            fprintf(fp, "fmul\n");
            fprintf(fp, "fstore %d\n", getAddress(level, $1));
        }
        else if(strcmp(getType(level, $1), "string") == 0) {
            printf("error:%d: cannot mul to string\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getType(level, $1), "bool") == 0) {
            printf("error:%d: cannot mul to bool\n", yylineno);
            HAS_ERROR = 1;
        }
        RHS = 0;
    } 
    | Expression QUO_ASSIGN { RHS = 1; lookup_symbol(level, $1); } Expression    { 
        if(strcmp(getLiteralType($1), "int32") == 0) {
            printf("error:%d: cannot assign to int32\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getLiteralType($1), "float32") == 0) {
            printf("error:%d: cannot assign to float32\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getLiteralType($1), "string") == 0) {
            printf("error:%d: cannot assign to string\n", yylineno);
            HAS_ERROR = 1;
        }
        else if((strncmp($1, "TRUE", 4) == 0) || (strncmp($1, "FALSE", 5) == 0)) {
            printf("error:%d: cannot assign to bool\n", yylineno);
            HAS_ERROR = 1;
        }
        
        if(strcmp(getType(level, $1), "array") == 0) {
            if(strcmp(getArrayType(level, $1), "int32") == 0) {
                fprintf(fp, "idiv\n");
                fprintf(fp, "iastore\n");
            }
            else if(strcmp(getArrayType(level, $1), "float32") == 0) {
                fprintf(fp, "fdiv\n");
                fprintf(fp, "fastore\n");
            }
            else if(strcmp(getArrayType(level, $1), "string") == 0) {
                printf("error:%d: cannot div to string\n", yylineno);
                HAS_ERROR = 1;
            }
            else if(strcmp(getArrayType(level, $1), "bool") == 0) {
                printf("error:%d: cannot div to bool\n", yylineno);
                HAS_ERROR = 1;
            }
        }
        else if(strcmp(getType(level, $1), "int32") == 0) {
            fprintf(fp, "idiv\n");
            fprintf(fp, "istore %d\n", getAddress(level, $1));
        }
        else if(strcmp(getType(level, $1), "float32") == 0) {
            fprintf(fp, "fdiv\n");
            fprintf(fp, "fstore %d\n", getAddress(level, $1));
        }
        else if(strcmp(getType(level, $1), "string") == 0) {
            printf("error:%d: cannot div to string\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getType(level, $1), "bool") == 0) {
            printf("error:%d: cannot div to bool\n", yylineno);
            HAS_ERROR = 1;
        }
        RHS = 0;
    } 
    | Expression REM_ASSIGN { RHS = 1; lookup_symbol(level, $1); } Expression    { 
        if(strcmp(getLiteralType($1), "int32") == 0) {
            printf("error:%d: cannot assign to int32\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getLiteralType($1), "float32") == 0) {
            printf("error:%d: cannot assign to float32\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getLiteralType($1), "string") == 0) {
            printf("error:%d: cannot assign to string\n", yylineno);
            HAS_ERROR = 1;
        }
        else if((strncmp($1, "TRUE", 4) == 0) || (strncmp($1, "FALSE", 5) == 0)) {
            printf("error:%d: cannot assign to bool\n", yylineno);
            HAS_ERROR = 1;
        }
        
        if(strcmp(getType(level, $1), "array") == 0) {
            if(strcmp(getArrayType(level, $1), "int32") == 0) {
                fprintf(fp, "irem\n");
                fprintf(fp, "iastore\n");
            }
            else if(strcmp(getArrayType(level, $1), "float32") == 0) {
                printf("error:%d: cannot mul to float32\n", yylineno);
                HAS_ERROR = 1;
            }
            else if(strcmp(getArrayType(level, $1), "string") == 0) {
                printf("error:%d: cannot mul to string\n", yylineno);
                HAS_ERROR = 1;
            }
            else if(strcmp(getArrayType(level, $1), "bool") == 0) {
                printf("error:%d: cannot mul to bool\n", yylineno);
                HAS_ERROR = 1;
            }
        }
        else if(strcmp(getType(level, $1), "int32") == 0) {
            fprintf(fp, "irem\n");
            fprintf(fp, "istore %d\n", getAddress(level, $1));
        }
        else if(strcmp(getType(level, $1), "float32") == 0) {
            printf("error:%d: cannot mul to float32\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getType(level, $1), "string") == 0) {
            printf("error:%d: cannot mul to string\n", yylineno);
            HAS_ERROR = 1;
        }
        else if(strcmp(getType(level, $1), "bool") == 0) {
            printf("error:%d: cannot mul to bool\n", yylineno);
            HAS_ERROR = 1;
        }
        RHS = 0;
    } 
;

ExpressionStmt
    : Expression
;

IncDecStmt
    : Expression INC    {
        printf("%s\n", $2); 
        if(strcmp(getType(level, $1), "int32") == 0) {
            fprintf(fp, "ldc 1\n");
            fprintf(fp, "iadd\n");
            fprintf(fp, "istore %d\n", getAddress(level, $1));
        }
        else if(strcmp(getType(level, $1), "float32") == 0) {
            fprintf(fp, "ldc 1.000000\n");
            fprintf(fp, "fadd\n");
            fprintf(fp, "fstore %d\n", getAddress(level, $1));
        }
        else if(strcmp(getType(level, $1), "array") == 0) {
            if(strcmp(getArrayType(level, $1), "int32") == 0) {

            }
            else if(strcmp(getArrayType(level, $1), "float32") == 0) {

            }
        }
    }
    | Expression DEC    {
        printf("%s\n", $2); 
        if(strcmp(getType(level, $1), "int32") == 0) {
            fprintf(fp, "ldc 1\n");
            fprintf(fp, "isub\n");
            fprintf(fp, "istore %d\n", getAddress(level, $1));
        }
        else if(strcmp(getType(level, $1), "float32") == 0) {
            fprintf(fp, "ldc 1.000000\n");
            fprintf(fp, "fsub\n");
            fprintf(fp, "fstore %d\n", getAddress(level, $1));
        }
    }
;

Block
    : '{' { create_symbol(); } StatementList '}' { dump_symbol(); }
;

IfStmt
    : IF Condition { 
        fprintf(fp, "ifeq ");
        getLabel(labelIndex);
     } Block {
        fprintf(fp, "goto ");
        getLabel(labelIndex+1);
        creatLabel();
     }

    | IfStmt ELSE IfStmt {
        creatLabel();
    }

    | IfStmt ELSE Block {
        creatLabel();
    }
;

Condition
    : Expression { 
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
;

ForStmt
    : FOR { creatStackLabel(whileIndex++); } ForClause {
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

    } Block {
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
;

ForClause
    : Condition {forFlag = 0;}
    | InitStmt ';' { forFlag = 1; fprintf(fp, "begin"); creatStackLabel(beginIndex++); } Condition ';' { fprintf(fp, "goto block"); getStackLabel(blockIndex++); fprintf(fp, "post"); creatStackLabel(postIndex++); } PostStmt { fprintf(fp, "goto begin"); getStackLabel(--beginIndex); }
;

InitStmt
    : SimpleStmt
;

PostStmt
    : SimpleStmt
;

PrintStmt
    : PRINT { RHS = 1; } '(' Expression ')'      
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
    | PRINTLN { RHS = 1; } '(' Expression ')'
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
;



%%

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
