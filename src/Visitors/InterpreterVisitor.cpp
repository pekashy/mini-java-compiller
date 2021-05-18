#include <Visitors/Visitor.h>

#include <Grammar/Expression.h>
#include <Grammar/Program.h>
#include <Grammar/Lvalue.h>
#include <Grammar/Invocation.h>
#include <Grammar/Declarations.h>
#include <Grammar/Types.h>
#include <Grammar/Identifier.h>
#include <Grammar/Statement.h>

#include <iostream>
#include <Visitors/InterpreterVisitor.h>

InterpreterVisitor::Ptr InterpreterVisitor::Create()
{
	return std::shared_ptr<InterpreterVisitor>(new InterpreterVisitor());
}

void InterpreterVisitor::Visit(const std::shared_ptr<Expression>& pNode)
{
	pNode->Accept(shared_from_this());
}

void InterpreterVisitor::Visit(const std::shared_ptr<BooleanExpression>& pNode)
{
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
	InterpretationLocker locker(shared_from_this());
	pNode->Accept(shared_from_this());
}

void InterpreterVisitor::Visit(const std::shared_ptr<ClassDeclaration>& pNode)
{
	InterpretationLocker locker(shared_from_this()); // as we do only for main function in main class
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
	InterpretationLocker locker(shared_from_this());
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


void InterpreterVisitor::AddToResult(const std::string& rPart)
{
	if (m_bInterpretationLocked)
	{
		return;
	}

	m_interpretRes << rPart;
}

InterpreterVisitor::InterpreterVisitor()
	: m_bInterpretationLocked(false)
{
	m_interpretRes << "int main() {\n";
}

std::string InterpreterVisitor::GetInterpreterResult() const
{
	return m_interpretRes.str() + "}";
}

void InterpreterVisitor::LockInterpretation()
{
	m_bInterpretationLocked = true;
}

void InterpreterVisitor::UnlockInterpretation()
{
	m_bInterpretationLocked = false;
}


InterpretationLocker::InterpretationLocker(const InterpreterVisitor::Ptr& pVisitor)
	: m_pVisitor(pVisitor)
{
	m_pVisitor->LockInterpretation();
}


InterpretationLocker::~InterpretationLocker()
{
	m_pVisitor->UnlockInterpretation();
}
