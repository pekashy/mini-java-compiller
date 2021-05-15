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
    void Accept(PrintVisitor::Ptr visitor) override;
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
    void Accept(PrintVisitor::Ptr visitor) override;
protected:
    Formals(const Formals::Ptr& pLine, const Formal::Ptr& pContent);
    Formals::Ptr m_pNextContent;
    Formal::Ptr m_pContent;
};


class Declaration : public GrammarNode
{
public:
    using Ptr = std::shared_ptr<Declaration>;
protected:
    Declaration(const std::shared_ptr<Identifier>& pIdentifier);
    std::shared_ptr<Identifier> m_pIdentifier;
};


class ClassDeclaration : public Declaration
{
public:
    using Ptr = std::shared_ptr<ClassDeclaration>;
    static Ptr Create(const std::shared_ptr<Identifier>& pClassId, const std::shared_ptr<Identifier>& pParentClassId,
        const Declaration::Ptr& pDeclaration);
    static Ptr Create(const std::shared_ptr<Identifier>& pClassId, const Chain<Declaration>::Ptr& pDeclarations);

    void Accept(PrintVisitor::Ptr visitor) override;
protected:
    ClassDeclaration(const std::shared_ptr<Identifier>& pClassId, const std::shared_ptr<Identifier>& pParentClassId,
                     const Declaration::Ptr& pDeclaration);

    ClassDeclaration(const std::shared_ptr<Identifier>& pClassId, const Chain<Declaration>::Ptr& pDeclarations);

    std::shared_ptr<Identifier> m_pParentClassId = nullptr;
    const Chain<Declaration>::Ptr m_pClassDeclarations;
};


class MethodDeclaration : public Declaration
{
public:
    using Ptr = std::shared_ptr<MethodDeclaration>;
    static Ptr Create(const std::shared_ptr<Type>& pType, const std::shared_ptr<Identifier>& pIdentifier,
                      const Chain<Statement>::Ptr& pStatements, const Formals::Ptr& pFormals);
    void Accept(PrintVisitor::Ptr visitor) override;
private:
    MethodDeclaration(const std::shared_ptr<Type>& pType, const std::shared_ptr<Identifier>& pIdentifier,
                         const Chain<Statement>::Ptr& pStatements, const Formals::Ptr& pFormals);
    Chain<Statement>::Ptr m_pStatements;
    std::shared_ptr<Type> m_pReturnType;
    Formals::Ptr m_pFormals;
};


class VariableDeclaration : public Declaration
{
public:
    using Ptr = std::shared_ptr<VariableDeclaration>;
    static Ptr Create(const std::shared_ptr<Type>& pType, const std::shared_ptr<Identifier>& pIdentifier);
    void Accept(PrintVisitor::Ptr visitor) override;
private:
    VariableDeclaration(const std::shared_ptr<Type>& pType, const std::shared_ptr<Identifier>& pIdentifier);
    std::shared_ptr<Type> m_pType;
};
