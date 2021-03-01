#include "Declarations.h"


Formals::Ptr Formals::Create(const Type::Ptr &pType, const Identifier::Ptr &pIdentifier)
{
    return std::shared_ptr<Formals>(new Formals(pType, pIdentifier));
}


Formals::Formals(const Type::Ptr &pType, const Identifier::Ptr &pIdentifier)
    : m_pType(pType)
    , m_pIdentifier(pIdentifier)
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
                          const Statement::Ptr &pStatement,
                          const Formals::Ptr &pFormals)
{
    return std::shared_ptr<MethodDeclaration>(new MethodDeclaration(pType, pIdentifier, pStatement, pFormals));
}


MethodDeclaration::MethodDeclaration(const Type::Ptr &pType,
                                     const Identifier::Ptr &pIdentifier,
                                     const Statement::Ptr &pStatement,
                                     const Formals::Ptr &pFormals)
                                     : Declaration(pType, pIdentifier)
                                     , m_pStatement(pStatement)
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
                                               const Declaration::Ptr &pDeclaration)
{
    return std::shared_ptr<ClassDeclaration>(new ClassDeclaration(pClassId, pDeclaration));
}



ClassDeclaration::ClassDeclaration(const Identifier::Ptr &pClassId,
                                   const Identifier::Ptr &pParentClassId,
                                   const Declaration::Ptr &pDeclaration)
                                   : m_pClassId(pClassId)
                                   , m_pParentClassId(pParentClassId)
                                   , m_pClassDeclaration(pDeclaration)
{}


ClassDeclaration::ClassDeclaration(const Identifier::Ptr &pClassId,
                                   const Declaration::Ptr &pDeclaration)
                                    : m_pClassId(pClassId)
                                    , m_pClassDeclaration(pDeclaration)
{}
