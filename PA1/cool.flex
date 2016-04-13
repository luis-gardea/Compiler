/*
 *  The scanner definition for COOL.
 */

/*
 *  Stuff enclosed in %{ %} in the first section is copied verbatim to the
 *  output, so headers and global definitions are placed here to be visible
 * to the code in the file.  Don't remove anything that was here initially
 */
%{
#include <cool-parse.h>
#include <stringtab.h>
#include <utilities.h>

/* The compiler assumes these identifiers. */
#define yylval cool_yylval
#define yylex  cool_yylex

/* Max size of string constants */
#define MAX_STR_CONST 1025
#define YY_NO_UNPUT   /* keep g++ happy */

extern FILE *fin; /* we read from this file */

/* define YY_INPUT so we read from the FILE fin:
 * This change makes it possible to use this scanner in
 * the Cool compiler.
 */
#undef YY_INPUT
#define YY_INPUT(buf,result,max_size) \
	if ( (result = fread( (char*)buf, sizeof(char), max_size, fin)) < 0) \
		YY_FATAL_ERROR( "read() in flex scanner failed");

char string_buf[MAX_STR_CONST]; /* to assemble string constants */
char *string_buf_ptr;

extern int curr_lineno;
extern int verbose_flag;

extern YYSTYPE cool_yylval;

/*
 *  Add Your own definitions here
 */
int num_chars = 0;

int check_overflow() {
  if (num_chars == (MAX_STR_CONST - 1)) {
    cool_yylval.error_msg = "String constant too long";
    num_chars = 0;
    return true; 
  } else {
    return false;
  }
}

%}

/*
 * Define names for regular expressions here.
 */

DARROW          =>
ULETTER         [A-Z]
LLETTER         [a-z]
DIGIT           [0-9]
TYPEID          [A-Z][a-zA-Z0-9_]*
OBJID           [a-z][a-zA-Z0-9_]*

CLASS           (?i:class)
ELSE            (?i:else)
FI              (?i:fi)
IF              (?i:if)
IN              (?i:in)
INHERITS        (?i:inherits)
ISVOID          (?i:isvoid)
LET             (?i:let)
LOOP            (?i:loop)
POOL            (?i:pool)
THEN            (?i:then)
WHILE           (?i:while)
CASE            (?i:case)
ESAC            (?i:esac)
NEW             (?i:new)
OF              (?i:of)
NOT             (?i:not)

FALSE           f(?i:alse)
TRUE            t(?i:rue)



%x STRING
%x BADSTRING
%%


 /*
  *  Nested comments
  */


 /*
  *  The multiple-character operators.
  */
{DARROW}		{ return (DARROW); }
"<-"            { return (ASSIGN); } 
"<="            { return (LE); }
";"             { return ';'; }
":"             { return ':'; }
"{"             { return '{'; }
"}"             { return '}'; }
"+"             { return '+'; }
"-"             { return '-'; }
","             { return ';'; }
"="             { return '='; }
"@"             { return '@'; }
"."             { return '.'; }
"/"             { return '/'; }
"*"             { return '*'; }
"~"             { return '~'; }
"("             { return '('; }
")"             { return ')'; }
"<"             { return '<'; }


 /*
  * Keywords are case-insensitive except for the values true and false,
  * which must begin with a lower-case letter.
  */
{CLASS}       { return (CLASS); }
{ELSE}        { return (ELSE); }
{FI}          { return (FI); }
{IF}          { return (IF); }
{IN}          { return (IN); }
{INHERITS}    { return (INHERITS); }
{ISVOID}      { return (ISVOID); }
{LET}         { return (LET); }
{LOOP}        { return (LOOP); }
{POOL}        { return (POOL); }
{THEN}        { return (THEN); }
{WHILE}       { return (WHILE); }
{CASE}        { return (CASE); }
{ESAC}        { return (ESAC); }
{NEW}         { return (NEW); }
{OF}          { return (OF); }
{NOT}         { return (NOT); }

{FALSE}       { cool_yylval.boolean = false; return (BOOL_CONST); }
{TRUE}        { cool_yylval.boolean = true; return (BOOL_CONST); }

{DIGIT}+      { cool_yylval.symbol = inttable.add_string(yytext); return (INT_CONST);}

 /*
  *  Newline \n
  *
  */
\n            {curr_lineno++;}

 /*
  *  Whitespaceept is any of " ", \n, \t.
  *
  */
[ \t\f\r\v]+      {}

 /*
 * Object identifiers are strings starting with a lowercase letter.
 * Can contain letters, digits, and underscore character.
 * i.e. self, myInt.
 *
 */
{OBJID}       { cool_yylval.symbol = idtable.add_string(yytext); return (OBJECTID); }

 /*
  * Type identifiers are strings starting with an uppercase letter.
  * Can contain letters, digits, and underscore character.
  * i.e. SELF_TYPE, Int.
  *
  */
{TYPEID}      { cool_yylval.symbol = idtable.add_string(yytext); return (TYPEID); }

 /*
  *  String constants (C syntax)
  *  Escape sequence \c is accepted for all characters c. Except for 
  *  \n \t \b \f, the result is c.
  *
  */  
\"         string_buf_ptr = string_buf; BEGIN(STRING);
     
<STRING>{
    /* saw closing quote - all done */
    \"        { 
                BEGIN(INITIAL);
                *string_buf_ptr = '\0';
                cool_yylval.symbol = stringtable.add_string(string_buf);
                return (STR_CONST);
              }

    <<EOF>>   {
                BEGIN(INITIAL);
                cool_yylval.error_msg = "EOF in string constant"; 
                return (ERROR);
              }

    \n        {
                BEGIN(INITIAL);
                curr_lineno++;
                cool_yylval.error_msg = "Unterminated string constant";
                return (ERROR);
              }

    \\0       {
                BEGIN(BADSTRING);
                cool_yylval.error_msg = "String contains null character";
              }
    
    \\n        if (check_overflow()) BEGIN(BADSTRING); else {*(string_buf_ptr++) = '\n'; num_chars++};
    \\t        if (check_overflow()) BEGIN(BADSTRING); else {*(string_buf_ptr++) = '\t'; num_chars++};
    \\r        if (check_overflow()) BEGIN(BADSTRING); else {*(string_buf_ptr++) = '\r'; num_chars++};
    \\b        if (check_overflow()) BEGIN(BADSTRING); else {*(string_buf_ptr++) = '\b'; num_chars++};
    \\f        if (check_overflow()) BEGIN(BADSTRING); else {*(string_buf_ptr++) = '\f'; num_chars++};
     
    \\.        if (check_overflow()) BEGIN(BADSTRING); else {*(string_buf_ptr++) = yytext[1]; num_chars++};

    \\\n       if (check_overflow()) BEGIN(BADSTRING); else {curr_lineno++; *(string_buf_ptr++) = yytext[1]; num_chars++};

    [^\\\n\"] {  
                char* yptr = yytext;
                if (check_overflow()) BEGIN(BADSTRING); else {
                  while( *yptr ) {
                    *(string_buf_ptr++) = *(yptr++);
                    num_chars++;
                  }
                }
              } 
                
}

<BADSTRING>{
  \n        {
              BEGIN(INITIAL);
              curr_lineno++;
              return (ERROR);
            }

  \"        { 
              BEGIN(INITIAL);
              return (ERROR);
            }

  [^\\n\"] {}
}

<<EOF>>         {
    yyterminate();
}

%%