#include <iostream>
#include <Grammar/Types.h>
#include <Grammar/Declarations.h>
#include <Grammar/Identifier.h>
#include <Grammar/Statement.h>

namespace
{
	class EmptyFormals : public Formals
	{
	 public:
		EmptyFormals() : Formals(nullptr, nullptr)
		{
		}

		using Ptr = std::shared_ptr<EmptyFormals>;
	};
};

Formal::Ptr Formal::Create(const Type::Ptr& pType, const Identifier::Ptr& pIdentifier)
{
	return std::shared_ptr<Formal>(new Formal(pType, pIdentifier));
}

Formal::Formal(const Type::Ptr& pType, const Identifier::Ptr& pIdentifier) : m_pType(pType), m_pIdentifier(pIdentifier)
{
}

void Formal::Accept(const std::shared_ptr<PrintVisitor>& pVisitor)
{
	std::cout << "Formal Visited" << std::endl;
	GenericAccept<PrintVisitor::Ptr>(pVisitor);
}

void Formal::Accept(const std::shared_ptr<InterpreterVisitor>& pVisitor)
{
	GenericAccept<InterpreterVisitor::Ptr>(pVisitor);
}

void Formal::Accept(const std::shared_ptr<SymbolTableVisitor>& pVisitor)
{
	pVisitor->AddMethodArg(m_pType->GetType(), m_pIdentifier->GetId());
	GenericAccept<SymbolTableVisitor::Ptr>(pVisitor);
}


template<class V> void Formal::GenericAccept(const V& pVisitor)
{
	pVisitor->Visit(m_pType);
	pVisitor->Visit(m_pIdentifier);
}

Formals::Ptr Formals::Create(const Formals::Ptr& pLine, const Formal::Ptr& pContent)
{
	return std::shared_ptr<Formals>(new Formals(pLine, pContent));
}

Formals::Ptr Formals::Create()
{
	return std::make_shared<EmptyFormals>();
}

Formals::Formals(const Formals::Ptr& pLine, const Formal::Ptr& pContent) : m_pNextContent(pLine), m_pContent(pContent)
{
}

void Formals::Accept(const std::shared_ptr<PrintVisitor>& pVisitor)
{
	std::cout << "Formals Visited" << std::endl;
	GenericAccept<PrintVisitor::Ptr>(pVisitor);
}

void Formals::Accept(const std::shared_ptr<InterpreterVisitor>& pVisitor)
{
	GenericAccept<InterpreterVisitor::Ptr>(pVisitor);
}

void Formals::Accept(const std::shared_ptr<SymbolTableVisitor>& pVisitor)
{
	GenericAccept<SymbolTableVisitor::Ptr>(pVisitor);
}

template<class V> void Formals::GenericAccept(const V& pVisitor)
{
	if (m_pContent)
	{
		pVisitor->Visit(m_pContent);
	}
	if (m_pNextContent)
	{
		pVisitor->Visit(m_pNextContent);
	}
}

Declaration::Declaration(const std::shared_ptr<Identifier>& pIdentifier) : m_pIdentifier(pIdentifier)
{
}

MethodDeclaration::Ptr MethodDeclaration::Create(const Type::Ptr& pType, const Identifier::Ptr& pIdentifier, const Chain<
	Statement>::Ptr& pStatements, const Formals::Ptr& pFormals)
{
	return std::shared_ptr<MethodDeclaration>(new MethodDeclaration(pType, pIdentifier, pStatements, pFormals));
}

MethodDeclaration::MethodDeclaration(const Type::Ptr& pType, const Identifier::Ptr& pIdentifier, const Chain<Statement>::Ptr& pStatements, const Formals::Ptr& pFormals)
	: Declaration(pIdentifier), m_pStatements(pStatements), m_pFormals(pFormals), m_pReturnType(pType)
{

}

void MethodDeclaration::Accept(const std::shared_ptr<PrintVisitor>& pVisitor)
{
	std::cout << "Method Declaration Visited" << std::endl;
	GenericAccept<PrintVisitor::Ptr>(pVisitor);
	pVisitor->Visit(m_pIdentifier);
	pVisitor->Visit(m_pFormals);
	pVisitor->Visit(m_pReturnType);
}

void MethodDeclaration::Accept(const std::shared_ptr<InterpreterVisitor>& pVisitor)
{
	GenericAccept<InterpreterVisitor::Ptr>(pVisitor);
	InterpretationLocker locker(pVisitor);
	pVisitor->Visit(m_pIdentifier);
	pVisitor->Visit(m_pFormals);
	pVisitor->Visit(m_pReturnType);
}

void MethodDeclaration::Accept(const std::shared_ptr<SymbolTableVisitor>& pVisitor)
{
	pVisitor->AddMethodName(m_pIdentifier->GetId());
	pVisitor->AddMethodReturnType(m_pReturnType->GetType());

	pVisitor->Visit(m_pIdentifier);
	pVisitor->Visit(m_pFormals);
	pVisitor->Visit(m_pReturnType);
	GenericAccept<SymbolTableVisitor::Ptr>(pVisitor);
}


template<class V> void MethodDeclaration::GenericAccept(const V& pVisitor)
{
	if (m_pStatements)
	{
		m_pStatements->Accept(pVisitor);
	}
}

VariableDeclaration::Ptr VariableDeclaration::Create(const Type::Ptr& pType, const Identifier::Ptr& pIdentifier)
{
	return std::shared_ptr<VariableDeclaration>(new VariableDeclaration(pType, pIdentifier));
}

VariableDeclaration::VariableDeclaration(const Type::Ptr& pType, const Identifier::Ptr& pIdentifier)
	: Declaration(pIdentifier), m_pType(pType)
{
}

void VariableDeclaration::Accept(const std::shared_ptr<PrintVisitor>& pVisitor)
{
	std::cout << "Variable Declaration Visited" << std::endl;
	GenericAccept<PrintVisitor::Ptr>(pVisitor);
}

void VariableDeclaration::Accept(const std::shared_ptr<InterpreterVisitor>& pVisitor)
{
	GenericAccept<InterpreterVisitor::Ptr>(pVisitor);
	pVisitor->AddToResult(";\n");
}

void VariableDeclaration::Accept(const std::shared_ptr<SymbolTableVisitor>& pVisitor)
{
	GenericAccept<SymbolTableVisitor::Ptr>(pVisitor);
	pVisitor->AddVarType(m_pType->GetType());
	pVisitor->AddVarName(m_pIdentifier->GetId());
}

template<class V> void VariableDeclaration::GenericAccept(const V& pVisitor)
{
	pVisitor->Visit(m_pType);
	pVisitor->Visit(m_pIdentifier);
}

ClassDeclaration::Ptr ClassDeclaration::Create(const Identifier::Ptr& pClassId, const Identifier::Ptr& pParentClassId, const Declaration::Ptr& pDeclaration)
{
	return std::shared_ptr<ClassDeclaration>(new ClassDeclaration(pClassId, pParentClassId, pDeclaration));
}

ClassDeclaration::Ptr ClassDeclaration::Create(const Identifier::Ptr& pClassId, const Chain<Declaration>::Ptr& pDeclarations)
{
	return std::shared_ptr<ClassDeclaration>(new ClassDeclaration(pClassId, pDeclarations));
}

ClassDeclaration::ClassDeclaration(const Identifier::Ptr& pClassId, const Identifier::Ptr& pParentClassId, const Declaration::Ptr& pDeclaration)
	: Declaration(pClassId), m_pParentClassId(pParentClassId)
{
}

ClassDeclaration::ClassDeclaration(const Identifier::Ptr& pClassId, const Chain<Declaration>::Ptr& pDeclarations)
	: Declaration(pClassId), m_pClassDeclarations(pDeclarations)
{
}

void ClassDeclaration::Accept(const std::shared_ptr<PrintVisitor>& pVisitor)
{
	std::cout << "Class Declaration Visited" << std::endl;
	GenericAccept<PrintVisitor::Ptr>(pVisitor);
}

void ClassDeclaration::Accept(const std::shared_ptr<InterpreterVisitor>& pVisitor)
{
	GenericAccept<InterpreterVisitor::Ptr>(pVisitor);
}

void ClassDeclaration::Accept(const std::shared_ptr<SymbolTableVisitor>& pVisitor)
{
	GenericAccept<SymbolTableVisitor::Ptr>(pVisitor);
}


template<class V> void ClassDeclaration::GenericAccept(const V& pVisitor)
{
	pVisitor->Visit(m_pIdentifier);
	if (m_pParentClassId)
	{
		pVisitor->Visit(m_pParentClassId);
	}
	if (m_pClassDeclarations)
	{
		m_pClassDeclarations->Accept(pVisitor);
	}
}