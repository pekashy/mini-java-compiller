#include <Visitors/SymbolTableVisitor.h>
#include <Grammar/Expression.h>
#include <Grammar/Program.h>
#include <Grammar/Lvalue.h>
#include <Grammar/Invocation.h>
#include <Grammar/Declarations.h>
#include <Grammar/Types.h>
#include <Grammar/Identifier.h>
#include <Grammar/Statement.h>

#include <SymbolTree/Scope.h>
#include <SymbolTree/ScopeNode.h>

#include <Objects/VariableObject.h>

SymbolTableVisitor::Ptr SymbolTableVisitor::Create()
{
	return std::shared_ptr<SymbolTableVisitor>(new SymbolTableVisitor());
}


SymbolTableVisitor::SymbolTableVisitor()
{
	m_pCurrentScope = scopeTree.GetRoot()->Get();
	m_scopeStack.push(scopeTree.GetRoot());
}


void SymbolTableVisitor::Visit(const std::shared_ptr<BooleanExpression>& pNode)
{
	pNode->Accept(shared_from_this());
}

void SymbolTableVisitor::Visit(const std::shared_ptr<Program>& pNode)
{
	pNode->Accept(shared_from_this());
}

void SymbolTableVisitor::Visit(const std::shared_ptr<Lvalue>& pNode)
{
	pNode->Accept(shared_from_this());
}

void SymbolTableVisitor::Visit(const std::shared_ptr<FieldInvocation>& pNode)
{
	pNode->Accept(shared_from_this());
}

void SymbolTableVisitor::Visit(const std::shared_ptr<ClassDeclaration>& pNode)
{
	pNode->Accept(shared_from_this());
}

void SymbolTableVisitor::Visit(const std::shared_ptr<Declaration>& pNode)
{
	pNode->Accept(shared_from_this());
}

void SymbolTableVisitor::Visit(const std::shared_ptr<VariableDeclaration>& pNode)
{
	pNode->Accept(shared_from_this());
	std::string variableName = m_varNameStack.top();
	std::string variableType = m_varTypeStack.top();
	auto pVarObject = VariableObject::Create(variableType, variableName);
	pVarObject->SetCorrespondingScope(m_pCurrentScope);
	m_pCurrentScope->DeclareSymbol(variableName, pVarObject);
	m_varNameStack.pop();
	m_varTypeStack.pop();
}

void SymbolTableVisitor::Visit(const std::shared_ptr<SimpleType>& pNode)
{
	pNode->Accept(shared_from_this());
}

void SymbolTableVisitor::Visit(const std::shared_ptr<ArrayType>& pNode)
{
	pNode->Accept(shared_from_this());
}

void SymbolTableVisitor::Visit(const std::shared_ptr<Identifier>& pNode)
{
	pNode->Accept(shared_from_this());
}

void SymbolTableVisitor::Visit(const std::shared_ptr<Formals>& pNode)
{
	pNode->Accept(shared_from_this());
}

void SymbolTableVisitor::Visit(const std::shared_ptr<Formal>& pNode)
{
	pNode->Accept(shared_from_this());
}

void SymbolTableVisitor::Visit(const std::shared_ptr<Statement>& pNode)
{
	pNode->Accept(shared_from_this());

}

void SymbolTableVisitor::Visit(const std::shared_ptr<MethodInvocation>& pNode)
{
	pNode->Accept(shared_from_this());
}

void SymbolTableVisitor::Visit(const std::shared_ptr<MainClassDeclaration>& pNode)
{
	pNode->Accept(shared_from_this());
}

void SymbolTableVisitor::Visit(const std::shared_ptr<MethodDeclaration>& pNode)
{
	pNode->Accept(shared_from_this());
}

void SymbolTableVisitor::Visit(const std::shared_ptr<Expression>& pNode)
{
	pNode->Accept(shared_from_this());
}

void SymbolTableVisitor::Visit(const std::shared_ptr<Type>& pNode)
{
	pNode->Accept(shared_from_this());
}

