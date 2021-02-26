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
":="       return m_pLocation->MakeAssign();
{int}      return m_pLocation->MakeNumber(yytext);
{id}       return m_pLocation->MakeIdentifier(yytext);
.          m_pLocation->ThrowError("invalid character: " + std::string(yytext));
<<EOF>>    return m_pLocation->MakeEnd();
%%
