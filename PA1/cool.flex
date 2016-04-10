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

%}

/*
 * Define names for regular expressions here.
 */

DARROW          =>
ULETTER         [A-Z]
LLETTER         [a-z]
DIGIT           [0-9]

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

TYPEID          [A-Z][a-zA-Z0-9_]*
OBJID           [a-z][a-zA-Z0-9_]*

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

 /*
  *  Whitespaceept is any of " ", \n, \t.
  *
  */
[ \t\f\r\v]+      {}



 /*
  *  String constants (C syntax)
  *  Escape sequence \c is accepted for all characters c. Except for 
  *  \n \t \b \f, the result is c.
  *
  */

 /*
  *  Newline \n
  *
  */
\n            {curr_lineno++}


 /*
  * Object identifiers are strings starting with a lowercase letter.
  * Can contain letters, digits, and underscore character.
  * i.e. self, myInt.
  *
  */
{OBJID}      { cool_yylval.symbol = idtable.add_string(yytext); return (OBJECTID); }

 /*
  * Type identifiers are strings starting with an uppercase letter.
  * Can contain letters, digits, and underscore character.
  * i.e. SELF_TYPE, Int.
  *
  */
{TYPEID}      { cool_yylval.class_ = yytext; return (TYPEID); }
%%
