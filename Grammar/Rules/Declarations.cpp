#include <iostream>
#include "Declarations.h"
#include "Types.h"
#include "Identifier.h"
#include "Statement.h"

namespace
{
    class EmptyFormals : public Formals
    {
    public:
        EmptyFormals()
        : Formals(nullptr, nullptr) {}

        using Ptr = std::shared_ptr<EmptyFormals>;
    };
};

Formal::Ptr Formal::Create(const Type::Ptr &pType, const Identifier::Ptr &pIdentifier)
{
    return std::shared_ptr<Formal>(new Formal(pType, pIdentifier));
}


Formal::Formal(const Type::Ptr &pType, const Identifier::Ptr &pIdentifier)
    : m_pType(pType)
    , m_pIdentifier(pIdentifier)
{}

void Formal::Accept(PrintVisitor::Ptr visitor)
{
    std::cout << "Formal Visited" << std::endl;
    m_pType->Accept(visitor);
    m_pIdentifier->Accept(visitor);
}

Formals::Ptr Formals::Create(const Formals::Ptr& pLine, const Formal::Ptr& pContent)
{
    return std::shared_ptr<Formals>(new Formals(pLine, pContent));
}


Formals::Ptr Formals::Create()
{
    return std::make_shared<EmptyFormals>();
}

Formals::Formals(const Formals::Ptr& pLine, const Formal::Ptr& pContent)
    : m_pNextContent(pLine)
    , m_pContent(pContent)
{}


void Formals::Accept(PrintVisitor::Ptr visitor)
{
    std::cout << "Formals Visited" << std::endl;
    if (m_pContent)
    {
        m_pContent->Accept(visitor);
    }
    if (m_pNextContent)
    {
        m_pNextContent->Accept(visitor);
    }
}


Declaration::Declaration(const std::shared_ptr<Identifier>& pIdentifier)
    : m_pIdentifier(pIdentifier)
{}


MethodDeclaration::Ptr MethodDeclaration::Create(const Type::Ptr &pType,
                          const Identifier::Ptr &pIdentifier,
                          const Chain<Statement>::Ptr& pStatements,
                          const Formals::Ptr &pFormals)
{
    return std::shared_ptr<MethodDeclaration>(new MethodDeclaration(pType, pIdentifier, pStatements, pFormals));
}


MethodDeclaration::MethodDeclaration(const Type::Ptr& pType,
                                     const Identifier::Ptr& pIdentifier,
                                     const Chain<Statement>::Ptr& pStatements,
                                     const Formals::Ptr& pFormals)
                                     : Declaration(pIdentifier)
                                     , m_pStatements(pStatements)
                                     , m_pFormals(pFormals)
                                     , m_pReturnType(pType)
{

}


void MethodDeclaration::Accept(PrintVisitor::Ptr visitor)
{
    std::cout << "Method Declaration Visited" << std::endl;
    if(m_pStatements)
    {
        m_pStatements->Accept(visitor);
    }
    m_pReturnType->Accept(visitor);
    m_pFormals->Accept(visitor);
}

VariableDeclaration::Ptr VariableDeclaration::Create(const Type::Ptr &pType, const Identifier::Ptr &pIdentifier)
{
    return std::shared_ptr<VariableDeclaration>(new VariableDeclaration(pType, pIdentifier));
}


VariableDeclaration::VariableDeclaration(const Type::Ptr& pType, const Identifier::Ptr& pIdentifier)
    : Declaration(pIdentifier)
    , m_pType(pType)
{}


void VariableDeclaration::Accept(PrintVisitor::Ptr visitor)
{
    std::cout << "Variable Declaration Visited" << std::endl;
    m_pType->Accept(visitor);
    m_pIdentifier->Accept(visitor);
}

ClassDeclaration::Ptr ClassDeclaration::Create(const Identifier::Ptr &pClassId,
                         const Identifier::Ptr &pParentClassId,
                         const Declaration::Ptr &pDeclaration)
{
    return std::shared_ptr<ClassDeclaration>(new ClassDeclaration(pClassId, pParentClassId, pDeclaration));
}


ClassDeclaration::Ptr ClassDeclaration::Create(const Identifier::Ptr &pClassId,
                                               const Chain<Declaration>::Ptr& pDeclarations)
{
    return std::shared_ptr<ClassDeclaration>(new ClassDeclaration(pClassId, pDeclarations));
}



ClassDeclaration::ClassDeclaration(const Identifier::Ptr& pClassId,
                                   const Identifier::Ptr& pParentClassId,
                                   const Declaration::Ptr& pDeclaration)
                                   : Declaration(pClassId)
                                   , m_pParentClassId(pParentClassId)
{}


ClassDeclaration::ClassDeclaration(const Identifier::Ptr& pClassId,
                                   const Chain<Declaration>::Ptr& pDeclarations)
                                    : Declaration(pClassId)
                                    , m_pClassDeclarations(pDeclarations)
{}

void ClassDeclaration::Accept(PrintVisitor::Ptr visitor)
{
    std::cout << "Class Declaration Visited" << std::endl;
    m_pIdentifier->Accept(visitor);
    if (m_pParentClassId)
    {
        m_pParentClassId->Accept(visitor);
    }
    if (m_pClassDeclarations)
    {
        m_pClassDeclarations->Accept(visitor);
    }
}
