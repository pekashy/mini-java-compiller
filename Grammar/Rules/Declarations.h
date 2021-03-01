#pragma once

#include "../GrammarNode.h"
#include "Types.h"
#include "Identifier.h"
#include "Statement.h"

// TODO: vector of statements and types
class Formals : public GrammarNode
{
public:
    using Ptr = std::shared_ptr<Formals>;
    static Ptr Create(const Type::Ptr& pType, const Identifier::Ptr& pIdentifier);
private:
    Formals(const Type::Ptr& pType, const Identifier::Ptr& pIdentifier);
    Type::Ptr m_pType;
    Identifier::Ptr m_pIdentifier;
};


class Declaration : public GrammarNode
{
public:
    using Ptr = std::shared_ptr<Declaration>;
    static Ptr Create(const Type::Ptr& pType, const Identifier::Ptr& pIdentifier);
protected:
    Declaration(const Type::Ptr& pType, const Identifier::Ptr& pIdentifier);
    Type::Ptr m_pType;
    Identifier::Ptr m_pIdentifier;
};


class ClassDeclaration : public GrammarNode
{
public:
    using Ptr = std::shared_ptr<ClassDeclaration>;
    static Ptr Create(const Identifier::Ptr& pClassId, const Identifier::Ptr& pParentClassId,
        const Declaration::Ptr& pDeclaration);
    static Ptr Create(const Identifier::Ptr& pClassId, const Declaration::Ptr& pDeclaration);
protected:
    ClassDeclaration(const Identifier::Ptr& pClassId, const Identifier::Ptr& pParentClassId,
                     const Declaration::Ptr& pDeclaration);

    ClassDeclaration(const Identifier::Ptr& pClassId, const Declaration::Ptr& pDeclaration);

    Type::Ptr m_pType;
    Identifier::Ptr m_pClassId;
    Identifier::Ptr m_pParentClassId = nullptr;
    Declaration::Ptr m_pClassDeclaration;
};



class MethodDeclaration : public Declaration
{
public:
    using Ptr = std::shared_ptr<MethodDeclaration>;
    static Ptr Create(const Type::Ptr& pType, const Identifier::Ptr& pIdentifier,
        const Statement::Ptr& pStatement, const Formals::Ptr& pFormals);
private:
    MethodDeclaration(const Type::Ptr& pType, const Identifier::Ptr& pIdentifier,
                         const Statement::Ptr& pStatement, const Formals::Ptr& pFormals);
    Statement::Ptr m_pStatement;
    Formals::Ptr m_pFormals;
};


class VariableDeclaration : public Declaration
{
public:
    using Ptr = std::shared_ptr<VariableDeclaration>;
    static Ptr Create(const Type::Ptr& pType, const Identifier::Ptr& pIdentifier);
private:
    VariableDeclaration(const Type::Ptr& pType, const Identifier::Ptr& pIdentifier);
};
