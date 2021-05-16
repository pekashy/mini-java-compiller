#include <iostream>
#include "Visitor.h"
#include "GrammarNode.h"
#include "Rules/Expression.h"
#include "Rules/Assignment.h"
#include "Rules/Program.h"
#include "Rules/Lvalue.h"
#include "Rules/Invocation.h"
#include "Rules/Declarations.h"
#include "Rules/Types.h"
#include "Rules/Identifier.h"
#include "Rules/Statement.h"
#include "Rules/Expression.h"

PrintVisitor::Ptr PrintVisitor::Create()
{
	return std::shared_ptr<PrintVisitor>(new PrintVisitor());
}


void PrintVisitor::Visit(const std::shared_ptr<Assignment>& pNode)
{
	pNode->Accept(shared_from_this());
}

void PrintVisitor::Visit(const std::shared_ptr<BooleanExpression>& pNode)
{
	pNode->Accept(shared_from_this());
}

void PrintVisitor::Visit(const std::shared_ptr<Program>& pNode)
{
	pNode->Accept(shared_from_this());
}

void PrintVisitor::Visit(const std::shared_ptr<Lvalue>& pNode)
{
	pNode->Accept(shared_from_this());
}

void PrintVisitor::Visit(const std::shared_ptr<FieldInvocation>& pNode)
{
	pNode->Accept(shared_from_this());
}

void PrintVisitor::Visit(const std::shared_ptr<ClassDeclaration>& pNode)
{
	pNode->Accept(shared_from_this());
}

void PrintVisitor::Visit(const std::shared_ptr<Declaration>& pNode)
{
	pNode->Accept(shared_from_this());

}

void PrintVisitor::Visit(const std::shared_ptr<VariableDeclaration>& pNode)
{
	pNode->Accept(shared_from_this());
}

void PrintVisitor::Visit(const std::shared_ptr<SimpleType>& pNode)
{
	pNode->Accept(shared_from_this());
}

void PrintVisitor::Visit(const std::shared_ptr<ArrayType>& pNode)
{
	pNode->Accept(shared_from_this());
}

void PrintVisitor::Visit(const std::shared_ptr<Identifier>& pNode)
{
	pNode->Accept(shared_from_this());
}

void PrintVisitor::Visit(const std::shared_ptr<Formals>& pNode)
{
	pNode->Accept(shared_from_this());
}

void PrintVisitor::Visit(const std::shared_ptr<Formal>& pNode)
{
	pNode->Accept(shared_from_this());
}

void PrintVisitor::Visit(const std::shared_ptr<Statement>& pNode)
{
	pNode->Accept(shared_from_this());

}

void PrintVisitor::Visit(const std::shared_ptr<MethodInvocation>& pNode)
{
	pNode->Accept(shared_from_this());
}

void PrintVisitor::Visit(const std::shared_ptr<MainClassDeclaration>& pNode)
{
	pNode->Accept(shared_from_this());

}

void PrintVisitor::Visit(const std::shared_ptr<MethodDeclaration>& pNode)
{
	pNode->Accept(shared_from_this());
}

void PrintVisitor::Visit(const std::shared_ptr<Expression>& pNode)
{
	pNode->Accept(shared_from_this());
}

void PrintVisitor::Visit(const std::shared_ptr<Type>& pNode)
{
	pNode->Accept(shared_from_this());
}

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
