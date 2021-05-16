#include "include/Visitors/Visitor.h"

#include "Grammar/GrammarNode.h"
#include "include/Grammar/Expression.h"
#include "include/Grammar/Assignment.h"
#include "include/Grammar/Program.h"
#include "include/Grammar/Lvalue.h"
#include "include/Grammar/Invocation.h"
#include "include/Grammar/Declarations.h"
#include "include/Grammar/Types.h"
#include "include/Grammar/Identifier.h"
#include "include/Grammar/Statement.h"

#include <iostream>


InterpreterVisitor::Ptr InterpreterVisitor::Create()
{
	return std::shared_ptr<InterpreterVisitor>(new InterpreterVisitor());
}

void InterpreterVisitor::Visit(const std::shared_ptr<Expression>& pNode)
{
	std::cout << "Interpreting expression: ";
	pNode->Accept(shared_from_this());
}

void InterpreterVisitor::Visit(const std::shared_ptr<Assignment>& pNode)
{
	pNode->Accept(shared_from_this());
}

void InterpreterVisitor::Visit(const std::shared_ptr<BooleanExpression>& pNode)
{
	std::cout << "Interpreting expression: ";
	pNode->Accept(shared_from_this());
}

void InterpreterVisitor::Visit(const std::shared_ptr<Program>& pNode)
{
	pNode->Accept(shared_from_this());
}

void InterpreterVisitor::Visit(const std::shared_ptr<Lvalue>& pNode)
{
	pNode->Accept(shared_from_this());

}
void InterpreterVisitor::Visit(const std::shared_ptr<FieldInvocation>& pNode)
{
	pNode->Accept(shared_from_this());
}

void InterpreterVisitor::Visit(const std::shared_ptr<ClassDeclaration>& pNode)
{
	pNode->Accept(shared_from_this());
}

void InterpreterVisitor::Visit(const std::shared_ptr<Declaration>& pNode)
{
	pNode->Accept(shared_from_this());
}

void InterpreterVisitor::Visit(const std::shared_ptr<VariableDeclaration>& pNode)
{
	pNode->Accept(shared_from_this());
}

void InterpreterVisitor::Visit(const std::shared_ptr<SimpleType>& pNode)
{
	pNode->Accept(shared_from_this());

}

void InterpreterVisitor::Visit(const std::shared_ptr<ArrayType>& pNode)
{
	pNode->Accept(shared_from_this());

}

void InterpreterVisitor::Visit(const std::shared_ptr<Identifier>& pNode)
{
	pNode->Accept(shared_from_this());
}

void InterpreterVisitor::Visit(const std::shared_ptr<Formals>& pNode)
{
	pNode->Accept(shared_from_this());

}

void InterpreterVisitor::Visit(const std::shared_ptr<Formal>& pNode)
{
	pNode->Accept(shared_from_this());

}

void InterpreterVisitor::Visit(const std::shared_ptr<Statement>& pNode)
{
	pNode->Accept(shared_from_this());

}

void InterpreterVisitor::Visit(const std::shared_ptr<MethodInvocation>& pNode)
{
	pNode->Accept(shared_from_this());
}

void InterpreterVisitor::Visit(const std::shared_ptr<MainClassDeclaration>& pNode)
{
	pNode->Accept(shared_from_this());
}

void InterpreterVisitor::Visit(const std::shared_ptr<MethodDeclaration>& pNode)
{
	pNode->Accept(shared_from_this());
}

void InterpreterVisitor::Visit(const std::shared_ptr<Type>& pNode)
{
	pNode->Accept(shared_from_this());
}
