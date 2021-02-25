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


%{
  // Code definitions at the end of scanner.cpp

  // A number symbol corresponding to the value in S.
  yy::parser::symbol_type make_NUMBER(
    const std::string &s,
    const yy::parser::location_type& loc
  );

  void Scanner::UpdateLocation() {
    m_pLocation->Update(yyleng);
  }
%}

blank [ \t\r]


%{
  // Code run each time a pattern is matched.
  #define YY_USER_ACTION UpdateLocation();
%}


%%
{blank}+   m_pLocation->Step();
\n+        m_pLocation->SkipEmptyLines(yyleng);
"-"        return m_pLocation->MakeMinus();
"+"        return m_pLocation->MakePlus();
"*"        return m_pLocation->MakeStar();
"/"        return m_pLocation->MakeSlash();
"("        return m_pLocation->MakeLParen();
")"        return m_pLocation->MakeRParen();
":="       return m_pLocation->MakeAssign();
<<EOF>>    ;
%%
