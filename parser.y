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
    class Program;
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
    #include "../Program.h"

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
%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"
%nterm <Expression*> exp
%nterm <Assignment*> assignment
%nterm <AssignmentList*> assignments
%nterm <Program*> unit

%%
%start unit;

unit: assignments exp { driver.SetProgram(Program::Create($1, $2)); return 0;};

assignments:
    %empty { $$ = new AssignmentList(); /* A -> eps */}
    | assignments assignment {
        $1->AddAssignment($2); $$ = $1;
    };

assignment:
    "identifier" ":=" exp {
        $$ = new Assignment($1, $3);
        // driver.variables[$1] = $3->eval();
    };

%left "+" "-";
%left "*" "/";

exp:
    "number" {$$ = new NumberExpression($1); }
    | "identifier" {$$ = new IdentExpression($1); }
    | exp "+" exp { $$ = new AddExpression($1, $3); }
    | exp "-" exp { $$ = new SubstractExpression($1, $3); }
    | exp "*" exp { $$ = new MulExpression($1, $3); }
    | exp "/" exp { $$ = new DivExpression($1, $3); }
    | "(" exp ")" { $$ = $2; };

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
