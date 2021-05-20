#pragma once

#include "GrammarNode.h"

class Type;
class Identifier;
class Statement;


class Formal : public GrammarNode, std::enable_shared_from_this<Formal>
{
public:
    using Ptr = std::shared_ptr<Formal>;
    static Ptr Create(const std::shared_ptr<Type>& pType, const std::shared_ptr<Identifier>& pIdentifier);
    void Accept(const std::shared_ptr<PrintVisitor> &pVisitor) override;
    void Accept(const std::shared_ptr<InterpreterVisitor> &pVisitor) override;
	void Accept(const std::shared_ptr<SymbolTableVisitor> &pVisitor) override;
 private:
    Formal(const std::shared_ptr<Type>& pType, const std::shared_ptr<Identifier>& pIdentifier);
    template<class V>
    void GenericAccept(const V& pVisitor);

    std::shared_ptr<Type> m_pType;
    std::shared_ptr<Identifier> m_pIdentifier;
};


class Formals : public GrammarNode, std::enable_shared_from_this<Formals>
{
public:
    using Ptr = std::shared_ptr<Formals>;
    static Ptr Create(const Formals::Ptr& pLine, const Formal::Ptr& pContent);
    static Ptr Create();
    void Accept(const std::shared_ptr<PrintVisitor> &pVisitor) override;
    void Accept(const std::shared_ptr<InterpreterVisitor> &pVisitor) override;
	void Accept(const std::shared_ptr<SymbolTableVisitor> &pVisitor) override;
protected:
    Formals(const Formals::Ptr& pLine, const Formal::Ptr& pContent);
    template<class V>
    void GenericAccept(const V& pVisitor);

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


class ClassDeclaration : public Declaration, std::enable_shared_from_this<ClassDeclaration>
{
public:
    using Ptr = std::shared_ptr<ClassDeclaration>;
    static Ptr Create(const std::shared_ptr<Identifier>& pClassId, const std::shared_ptr<Identifier>& pParentClassId,
        const Declaration::Ptr& pDeclaration);
    static Ptr Create(const std::shared_ptr<Identifier>& pClassId, const Chain<Declaration>::Ptr& pDeclarations);

    void Accept(const std::shared_ptr<PrintVisitor> &pVisitor) override;
    void Accept(const std::shared_ptr<InterpreterVisitor> &pVisitor) override;
	void Accept(const std::shared_ptr<SymbolTableVisitor> &pVisitor) override;
protected:
    ClassDeclaration(const std::shared_ptr<Identifier>& pClassId, const std::shared_ptr<Identifier>& pParentClassId,
                     const Declaration::Ptr& pDeclaration);

    ClassDeclaration(const std::shared_ptr<Identifier>& pClassId, const Chain<Declaration>::Ptr& pDeclarations);

    template<class V>
    void GenericAccept(const V& pVisitor);

    std::shared_ptr<Identifier> m_pParentClassId;
    const Chain<Declaration>::Ptr m_pClassDeclarations;
};


class MethodDeclaration : public Declaration
{
public:
    using Ptr = std::shared_ptr<MethodDeclaration>;
    static Ptr Create(const std::shared_ptr<Type>& pType, const std::shared_ptr<Identifier>& pIdentifier,
                      const Chain<Statement>::Ptr& pStatements, const Formals::Ptr& pFormals);
    void Accept(const std::shared_ptr<PrintVisitor> &pVisitor) override;
    void Accept(const std::shared_ptr<InterpreterVisitor> &pVisitor) override;
	void Accept(const std::shared_ptr<SymbolTableVisitor> &pVisitor) override;
private:
    MethodDeclaration(const std::shared_ptr<Type>& pType, const std::shared_ptr<Identifier>& pIdentifier,
                         const Chain<Statement>::Ptr& pStatements, const Formals::Ptr& pFormals);
    template<class V>
    void GenericAccept(const V& pVisitor);

    Chain<Statement>::Ptr m_pStatements;
    std::shared_ptr<Type> m_pReturnType;
    Formals::Ptr m_pFormals;
};


class VariableDeclaration : public Declaration
{
public:
    using Ptr = std::shared_ptr<VariableDeclaration>;
    static Ptr Create(const std::shared_ptr<Type>& pType, const std::shared_ptr<Identifier>& pIdentifier);
    void Accept(const std::shared_ptr<PrintVisitor> &pVisitor) override;
    void Accept(const std::shared_ptr<InterpreterVisitor> &pVisitor) override;
	void Accept(const std::shared_ptr<SymbolTableVisitor> &pVisitor) override;
private:
    VariableDeclaration(const std::shared_ptr<Type>& pType, const std::shared_ptr<Identifier>& pIdentifier);
    template<class V>
    void GenericAccept(const V& pVisitor);

    std::shared_ptr<Type> m_pType;
};
