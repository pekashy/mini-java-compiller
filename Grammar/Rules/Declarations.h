#pragma once

#include "../GrammarNode.h"

class Type;
class Identifier;
class Statement;


// TODO: vector of statements and types
class Formal : public GrammarNode
{
public:
    using Ptr = std::shared_ptr<Formal>;
    static Ptr Create(const std::shared_ptr<Type>& pType, const std::shared_ptr<Identifier>& pIdentifier);
private:
    Formal(const std::shared_ptr<Type>& pType, const std::shared_ptr<Identifier>& pIdentifier);
    std::shared_ptr<Type> m_pType;
    std::shared_ptr<Identifier> m_pIdentifier;
};


class Formals : public GrammarNode
{
public:
    using Ptr = std::shared_ptr<Formals>;
    static Ptr Create(const Formals::Ptr& pLine, const Formal::Ptr& pContent);
    static Ptr Create();
protected:
    Formals(const Formals::Ptr& pLine, const Formal::Ptr& pContent);
    Formals::Ptr m_pNextContent;
    Formal::Ptr m_pContent;
};


class Declaration : public GrammarNode
{
public:
    using Ptr = std::shared_ptr<Declaration>;
    static Ptr Create(const std::shared_ptr<Type>& pType, const std::shared_ptr<Identifier>& pIdentifier);
protected:
    Declaration(const std::shared_ptr<Type>& pType, const std::shared_ptr<Identifier>& pIdentifier);
    std::shared_ptr<Type> m_pType;
    std::shared_ptr<Identifier> m_pIdentifier;
};


class ClassDeclaration : public GrammarNode
{
public:
    using Ptr = std::shared_ptr<ClassDeclaration>;
    static Ptr Create(const std::shared_ptr<Identifier>& pClassId, const std::shared_ptr<Identifier>& pParentClassId,
        const Declaration::Ptr& pDeclaration);
    static Ptr Create(const std::shared_ptr<Identifier>& pClassId, const Declaration::Ptr& pDeclaration);
protected:
    ClassDeclaration(const std::shared_ptr<Identifier>& pClassId, const std::shared_ptr<Identifier>& pParentClassId,
                     const Declaration::Ptr& pDeclaration);

    ClassDeclaration(const std::shared_ptr<Identifier>& pClassId, const Declaration::Ptr& pDeclaration);

    std::shared_ptr<Type> m_pType;
    std::shared_ptr<Identifier> m_pClassId;
    std::shared_ptr<Identifier> m_pParentClassId = nullptr;
    Declaration::Ptr m_pClassDeclaration;
};


class MethodDeclaration : public Declaration
{
public:
    using Ptr = std::shared_ptr<MethodDeclaration>;
    static Ptr Create(const std::shared_ptr<Type>& pType, const std::shared_ptr<Identifier>& pIdentifier,
        const std::shared_ptr<Statement>& pStatement, const Formals::Ptr& pFormals);
private:
    MethodDeclaration(const std::shared_ptr<Type>& pType, const std::shared_ptr<Identifier>& pIdentifier,
                         const std::shared_ptr<Statement>& pStatement, const Formals::Ptr& pFormals);
    std::shared_ptr<Statement> m_pStatement;
    Formals::Ptr m_pFormals;
};


class VariableDeclaration : public Declaration
{
public:
    using Ptr = std::shared_ptr<VariableDeclaration>;
    static Ptr Create(const std::shared_ptr<Type>& pType, const std::shared_ptr<Identifier>& pIdentifier);
private:
    VariableDeclaration(const std::shared_ptr<Type>& pType, const std::shared_ptr<Identifier>& pIdentifier);
};
