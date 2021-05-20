#include <Visitors/SymbolTableVisitor.h>
#include <Grammar/Expression.h>
#include <Grammar/Program.h>
#include <Grammar/Lvalue.h>
#include <Grammar/Invocation.h>
#include <Grammar/Declarations.h>
#include <Grammar/Types.h>
#include <Grammar/Identifier.h>
#include <Grammar/Statement.h>

#include <Objects/VariableObject.h>
#include <Objects/MethodObject.h>
#include <Objects/ClassObject.h>

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
	auto pClassDeclaration = std::dynamic_pointer_cast<ClassDeclaration>(pNode);
	auto pVarDeclaration = std::dynamic_pointer_cast<VariableDeclaration>(pNode);
	auto pMethDeclaration = std::dynamic_pointer_cast<MethodDeclaration>(pNode);
	if (pClassDeclaration)
	{
		Visit(pClassDeclaration);
	}
	else if (pVarDeclaration)
	{
		Visit(pVarDeclaration);
	}
	else if (pMethDeclaration)
	{
		Visit(pMethDeclaration);
	}
	else
	{
		pNode->Accept(shared_from_this());
	}
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
	ScopeIncrementer autoScopeManager(shared_from_this());
	pNode->Accept(shared_from_this());
}

void SymbolTableVisitor::Visit(const std::shared_ptr<MethodDeclaration>& pNode)
{
	auto pParentScope = m_pCurrentScope;
	ScopeIncrementer autoScopeManager(shared_from_this()); // Current scope changed!
	pNode->Accept(shared_from_this());

	std::string methodName = m_methodNameStack.top();
	std::string methodReturnType = m_methodRetValueStack.top();

	auto pMethObject = MethodObject::Create(methodReturnType, methodName);

	while(!m_methodArgStack.empty())
	{
		auto typeNamePair = m_methodArgStack.top();
		auto pVarObj = VariableObject::Create(typeNamePair.first, typeNamePair.second);
		pMethObject->AddArg(pVarObj);
		m_pCurrentScope->DeclareSymbol(typeNamePair.second, pVarObj);
		pVarObj->SetCorrespondingScope(m_pCurrentScope);
		m_methodArgStack.pop();
	}
	pParentScope->DeclareSymbol(methodName, pMethObject); // Method belongs to parent scope!
	pMethObject->SetCorrespondingScope(pParentScope);
	m_methodNameStack.pop();
	m_methodRetValueStack.pop();
}

void SymbolTableVisitor::Visit(const std::shared_ptr<Expression>& pNode)
{
	pNode->Accept(shared_from_this());
}

void SymbolTableVisitor::Visit(const std::shared_ptr<Type>& pNode)
{
	pNode->Accept(shared_from_this());
}

void SymbolTableVisitor::AddClassObject(const ClassObject::Ptr& pClass)
{
	m_pCurrentScope->DeclareSymbol(pClass->GetName(), pClass);
	pClass->SetCorrespondingScope(m_pCurrentScope);
}

void SymbolTableVisitor::AddVarType(const std::string& varType)
{
	m_varTypeStack.push(varType);
}

void SymbolTableVisitor::AddVarName(const std::string& varName)
{
	m_varNameStack.push(varName);
}

void SymbolTableVisitor::EnterNewScope()
{
	auto newScopePtr = ScopeNode::Create(m_scopeStack.top());
	m_scopeStack.push(newScopePtr);
	m_pCurrentScope = newScopePtr->Get();
}

void SymbolTableVisitor::ExitCurrentScope()
{
	if(m_scopeStack.size() < 2)
	{
		throw std::runtime_error("trying to exit main scope during execution!");
	}

	m_scopeStack.pop();
	m_pCurrentScope = m_scopeStack.top()->Get();
}


void SymbolTableVisitor::AddMethodName(const std::string& name)
{
	m_methodNameStack.push(name);
}


void SymbolTableVisitor::AddMethodReturnType(const std::string& type)
{
	m_methodRetValueStack.push(type);
}


void SymbolTableVisitor::AddMethodArg(const std::string& retType, const std::string& name)
{
	m_methodArgStack.push({ retType, name });
}


ScopeIncrementer::ScopeIncrementer(const SymbolTableVisitor::Ptr& pVisitor)
{
	m_pVisitor = pVisitor;
	m_pVisitor->EnterNewScope();
}

ScopeIncrementer::~ScopeIncrementer()
{
	m_pVisitor->ExitCurrentScope();
}