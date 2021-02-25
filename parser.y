%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    class Location;
    class Scanner;
    class CompilerDriver;
    class Expression;
    class NumberExpression;
    class AddExpression;
    class SubstractExpression;
    class DivExpression;
    class IdentExpression;
    class Assignment;
    class AssignmentList;
}

%define parse.trace
%define parse.error verbose

%code {
    #include "../CompilerDriver.h"
    #include "../Location.h"
    #include "../Scanner.h"
    #include "location.hh"

    #include "../expressions/NumberExpression.h"
    #include "../expressions/AddExpression.h"
    #include "../expressions/MulExpression.h"
    #include "../expressions/DivExpression.h"
    #include "../expressions/SubstractExpression.h"
    #include "../expressions/IdentExpression.h"
    #include "../assignments/Assignment.h"
    #include "../assignments/AssignmentList.h"

    static yy::parser::symbol_type yylex(Scanner& scanner, CompilerDriver& driver) {
        return scanner.ScanToken();
    }
}


%lex-param { Scanner &scanner }
%lex-param { CompilerDriver &driver }
%parse-param { Scanner &scanner }
%parse-param { CompilerDriver &driver }

%locations

%define api.token.prefix {TOK_}

%token
    END 0 "end of file"
    ASSIGN ":="
    MINUS "-"
    PLUS "+"
    STAR "*"
    SLASH "/"
    LPAREN "("
    RPAREN ")"
;
// %printer { yyo << $$; } <*>;

%%
%start unit;
unit: {}
%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
