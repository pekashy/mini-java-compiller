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


Declaration::Ptr Declaration::Create(const Type::Ptr &pType, const Identifier::Ptr &pIdentifier)
{
    return std::shared_ptr<Declaration>(new Declaration(pType, pIdentifier));
}


Declaration::Declaration(const Type::Ptr &pType, const Identifier::Ptr &pIdentifier)
    : m_pType(pType)
    , m_pIdentifier(pIdentifier)
{}


MethodDeclaration::Ptr MethodDeclaration::Create(const Type::Ptr &pType,
                          const Identifier::Ptr &pIdentifier,
                          const Chain<Statement>::Ptr& pStatements,
                          const Formals::Ptr &pFormals)
{
    return std::shared_ptr<MethodDeclaration>(new MethodDeclaration(pType, pIdentifier, pStatements, pFormals));
}


MethodDeclaration::MethodDeclaration(const Type::Ptr &pType,
                                     const Identifier::Ptr &pIdentifier,
                                     const Chain<Statement>::Ptr& pStatements,
                                     const Formals::Ptr &pFormals)
                                     : Declaration(pType, pIdentifier)
                                     , m_pStatements(pStatements)
                                     , m_pFormals(pFormals)
{}


VariableDeclaration::Ptr VariableDeclaration::Create(const Type::Ptr &pType, const Identifier::Ptr &pIdentifier)
{
    return std::shared_ptr<VariableDeclaration>(new VariableDeclaration(pType, pIdentifier));
}


VariableDeclaration::VariableDeclaration(const Type::Ptr &pType, const Identifier::Ptr &pIdentifier)
    : Declaration(pType, pIdentifier)
{}


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



ClassDeclaration::ClassDeclaration(const Identifier::Ptr &pClassId,
                                   const Identifier::Ptr &pParentClassId,
                                   const Declaration::Ptr& pDeclaration)
                                   : m_pClassId(pClassId)
                                   , m_pParentClassId(pParentClassId)
                                   , m_pClassDeclaration(pDeclaration)
{}


ClassDeclaration::ClassDeclaration(const Identifier::Ptr &pClassId,
                                   const Chain<Declaration>::Ptr &pDeclarations)
                                    : m_pClassId(pClassId)
                                    , m_pClassDeclarations(pDeclarations)
{}
