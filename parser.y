%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    #include <memory>
    class Assignment;
    class AssignmentList;
    class GrammarNode;
    class Location;
    class Scanner;
    class CompilerDriver;
    class Program;
}

%define parse.trace
%define parse.error verbose

%code {
    #include "../Grammar/NodeFactory.h"
    #include "../CompilerDriver.h"
    #include "../Location.h"
    #include "../Scanner.h"
    #include "location.hh"

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
%nterm <std::shared_ptr<GrammarNode>> exp
%nterm <std::shared_ptr<Assignment>> assignment
%nterm <std::shared_ptr<AssignmentList>> assignments
%nterm <Program*> unit

%%
%start unit;

unit: assignments exp { return 0; };

assignments:
    %empty
    {
    	// For some mysterious reasomn dynamic_cast is neccessary
    	auto p = std::dynamic_pointer_cast<AssignmentList>(NodeFactory::CreateAssignmentList());
    	if(p)
    	{
    		$$ = p;
    	}
    	else
    	{
    		assert(false);
    	}
      /*A -> eps */
    }
    | assignments assignment {
        $1->AddAssignment($2); $$ = $1;
    };

assignment:
    "identifier" ":=" exp {
        $$ = NodeFactory::CreateAssignment($1, $3);
        // driver.variables[$1] = $3->eval();
    };

%left "+" "-";
%left "*" "/";

exp:
    "number" {$$ = NodeFactory::CreateNumberExpression($1);  }
    | "identifier" {$$ = NodeFactory::CreateIdentExpression($1);  }
    | exp "+" exp { $$ = NodeFactory::CreateAddExpression($1, $3);  }
    | exp "-" exp { $$ = NodeFactory::CreateSubstractExpression($1, $3);  }
    | exp "*" exp { $$ = NodeFactory::CreateMulExpression($1, $3);  }
    | exp "/" exp { $$ = NodeFactory::CreateDivExpression($1, $3); }
    | "(" exp ")" { $$ = $2; };

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
