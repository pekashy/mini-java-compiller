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
    class Expression;
    class GrammarNode;
    class Location;
    class Scanner;
    class CompilerDriver;
    class Program;
    class Lvalue;
    class FieldInvocation;
    class ClassDeclaration;
    class Declaration;
    class VariableDeclaration;
    class Type;
    class SimpleType;
    class ArrayType;
    class Identifier;
    class Formals;
    class Statement;
    class MethodInvocation;
    class MainClassDeclaration;
    class MethodDeclaration;
}

%define parse.trace
%define parse.error verbose

%code {
    #include "location.hh"
    #include "../CompilerDriver.h"
    #include "../Location.h"
    #include "../Scanner.h"

    #include "../Grammar/Rules/Program.h"
    #include "../Grammar/Rules/Lvalue.h"
    #include "../Grammar/Rules/Invocation.h"
    #include "../Grammar/Rules/Declarations.h"
    #include "../Grammar/Rules/Expression.h"
    #include "../Grammar/Rules/AssignmentList.h"
    #include "../Grammar/Rules/Assignment.h"
    #include "../Grammar/Rules/Types.h"
    #include "../Grammar/Rules/Identifier.h"
    #include "../Grammar/Rules/Statement.h"

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
    ASSIGN "="
    MINUS "-"
    PLUS "+"
    STAR "*"
    SLASH "/"
    LPAREN "("
    RPAREN ")"
    THIS "this"
    DOT "."
    LSPAREN "["
    RSPAREN "]"
    COMADOT ";"
    INT "int"
    BOOLEAN "boolean"
    VOID "void"
    PUBLIC "public"
    LFPARENT "{"
    RFPARENT "}"
    ASSERT "assert"
    IF "if"
    ELSE "else"
    WHILE "while"
    PRINT "System.out.println"
    RETURN "return"
    CLASS "class"
    MAIN "public static void main()"
;


%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"
%nterm <std::shared_ptr<Identifier>> identifier
%nterm <std::shared_ptr<Expression>> exp
%nterm <std::shared_ptr<Assignment>> assignment
%nterm <std::shared_ptr<AssignmentList>> assignments
%nterm <std::shared_ptr<Program>> unit
%nterm <std::shared_ptr<Lvalue>> lvalue
%nterm <std::shared_ptr<FieldInvocation>> fieldInvocation
%nterm <std::shared_ptr<VariableDeclaration>> variableDeclaration
%nterm <std::shared_ptr<VariableDeclaration>> localVariableDeclaration
%nterm <std::shared_ptr<SimpleType>> simpleType
%nterm <std::shared_ptr<ArrayType>> arrayType
%nterm <std::shared_ptr<Type>> type
%nterm <std::shared_ptr<Identifier>> typeIdentifier
%nterm <std::shared_ptr<Formals>> formals
%nterm <std::shared_ptr<MethodDeclaration>> methodDeclaration
%nterm <std::shared_ptr<Statement>> statement
%nterm <std::shared_ptr<MethodInvocation>> methodInvocation
%nterm <std::shared_ptr<Declaration>> declaration
%nterm <std::shared_ptr<ClassDeclaration>> classDeclaration
%nterm <std::shared_ptr<MainClassDeclaration>> mainClass
%nterm <std::shared_ptr<Program>> program


%%
%start program;

program:
	  mainClass classDeclaration {$$ = Program::Create($1, $2); driver.SetProgram($$); }


mainClass:
	  CLASS identifier "{" MAIN "{" statement "}" "}" { $$ = MainClassDeclaration::Create($6, $2); }


classDeclaration:
	  CLASS identifier "{" declaration "}" { $$ = ClassDeclaration::Create($2, $4); }


declaration:
	  variableDeclaration { $$ = $1; }
	| methodDeclaration { $$ = $1; }


methodDeclaration:
	  PUBLIC type identifier "(" formals ")" "{" statement "}" { $$ = MethodDeclaration::Create($2, $3, $8, $5);}


statement:
	  ASSERT "(" exp ")" { $$ = Statement::CreateAssertion($3); }
	| localVariableDeclaration { $$ = Statement::CreateLocalVarDeclaration($1);}
	| "{" statement "}" { $$ = Statement::CreateInnerStatement($2);}
	| IF "(" exp ")" statement { $$ = Statement::CreateIf($3, $5);}
	| IF "(" exp ")" statement ELSE statement { $$ = Statement::CreateIfElse($3, $5, $7);}
	| WHILE "(" exp ")" statement { $$ = Statement::CreateWhile($3, $5);}
	| PRINT "(" exp ")" ";" { $$ = Statement::CreatePrint($3);}
	| lvalue "=" exp ";" { $$ = Statement::CreateAssignment($3, $1);}
	| RETURN exp ";" { $$ = Statement::CreateReturn($2);}
	| methodInvocation ";" { $$ = Statement::CreateMethodInvoc($1);}

formals:
	  type identifier {$$ = Formals::Create($1, $2);}


localVariableDeclaration:
	  variableDeclaration { $$ = $1; }


variableDeclaration:
	  type identifier ";" {$$ = VariableDeclaration::Create($1, $2);}


type:
	  simpleType { $$ = $1; }
	| arrayType { $$ = $1; }


arrayType:
	  simpleType "[" "]" { $$ = ArrayType::Create($1); }


simpleType:
	  "int" { $$ = SimpleType::Create(Types::Int); }
	| "boolean" { $$ = SimpleType::Create(Types::Boolean); }
	| "void" { $$ = SimpleType::Create(Types::Void); }
	| identifier { $$ = SimpleType::Create($1); }


typeIdentifier:
	  identifier { $$ = $1; }


lvalue:
	  identifier { $$ = Lvalue::Create($1); }
	| identifier "[" exp "]" { $$ = Lvalue::Create($1, $3);}
	| fieldInvocation { $$ = Lvalue::Create($1); }


methodInvocation:
	  exp "." identifier "(" exp ")" {$$ = MethodInvocation::Create($1, $3, $5);}


fieldInvocation:
	  THIS "." identifier { $$ = FieldInvocation::Create($3); }
	| THIS "." identifier "[" exp "]" { $$ = FieldInvocation::Create($3, $5); }


%left "+" "-";
%left "*" "/";


exp:
    "number" {$$ = Expression::CreateNumberExpression($1);  }
    | identifier {$$ = Expression::CreateIdentExpression($1);  }
    | exp "+" exp { $$ = Expression::CreateAddExpression($1, $3);  }
    | exp "-" exp { $$ = Expression::CreateSubstractExpression($1, $3);  }
    | exp "*" exp { $$ = Expression::CreateMulExpression($1, $3);  }
    | exp "/" exp { $$ = Expression::CreateDivExpression($1, $3); }
    | "(" exp ")" { $$ = $2; };


identifier:
	IDENTIFIER { $$ = Identifier::Create($1); }
%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
