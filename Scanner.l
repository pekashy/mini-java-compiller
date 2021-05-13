%{
    #include <cerrno>
    #include <climits>
    #include <cstdlib>
    #include <cstring> // strerror
    #include <string>
    #include <iostream>
    #include "../CompilerDriver.h"
    #include "../Location.h"
    #include "parser.hh"
%}

%option noyywrap nounput noinput batch debug

%option c++
%option yyclass="Scanner"

id    [a-zA-Z][a-zA-Z_0-9]*
int   [0-9]+
blank [ \t\r]

%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION m_pLocation->Update(yyleng);
%}

%%
%{
  m_pLocation->Step();
%}

{blank}+   m_pLocation->Step();
\n+        m_pLocation->SkipEmptyLines(yyleng);
"-"        return m_pLocation->MakeMinus();
"+"        return m_pLocation->MakePlus();
"*"        return m_pLocation->MakeStar();
"/"        return m_pLocation->MakeSlash();
"("        return m_pLocation->MakeLParen();
")"        return m_pLocation->MakeRParen();
"="        return m_pLocation->MakeAssign();
"this"     return m_pLocation->MakeThis();
"."        return m_pLocation->MakeDot();
"]"        return m_pLocation->MakeLSParnt();
"["        return m_pLocation->MakeRSParent();
";"        return m_pLocation->MakeComadot();
"assert"   return m_pLocation->MakeAssert();
"int"      return m_pLocation->MakeInt();
"boolean"  return m_pLocation->MakeBoolean();
"void"     return m_pLocation->MakeVoid();
"public"   return m_pLocation->MakePublic();
"{"        return m_pLocation->MakeLFparen();
"}"        return m_pLocation->MakeRFParen();
"if"       return m_pLocation->MakeIf();
"else"     return m_pLocation->MakeElse();
"while"    return m_pLocation->MakeWhile();
"System.out.println"         return m_pLocation->MakePrint();
"class"    return m_pLocation->MakeClass();
"main"     return m_pLocation->MakeMain();
"static"     return m_pLocation->MakeStatic();
"new"     return m_pLocation->MakeNew();
"true"     return m_pLocation->MakeTrue();
"false"     return m_pLocation->MakeFalse();
"length"     return m_pLocation->MakeLength();
"length"     return m_pLocation->MakeLength();
{int}      return m_pLocation->MakeNumber(yytext);
{id}       return m_pLocation->MakeIdentifier(yytext);
.          m_pLocation->ThrowError("invalid character: " + std::string(yytext));
<<EOF>>    return m_pLocation->MakeEnd();
%%
