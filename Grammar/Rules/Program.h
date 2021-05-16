#pragma once

#include "../GrammarNode.h"

class Statement;
class Identifier;
class ClassDeclaration;

class MainClassDeclaration : public GrammarNode
{
public:
    using Ptr = std::shared_ptr<MainClassDeclaration>;
    static Ptr Create(const std::shared_ptr<Statement>& pStatement, const std::shared_ptr<Identifier>& pClassName);
    void Accept(const std::shared_ptr<PrintVisitor> &pVisitor) override;
    void
    Accept(const std::shared_ptr<InterpreterVisitor> &pVisitor) override;
private:
    MainClassDeclaration(const std::shared_ptr<Statement>& pMainClassStatement, const std::shared_ptr<Identifier>& pMainClassName);

    template<class V>
    void GenericAccept(const V& pVisitor);

    std::shared_ptr<Statement> m_pMainClassStatement;
    std::shared_ptr<Identifier> m_pMainClassName;
};


class Program : public GrammarNode
{
public:
    using Ptr = std::shared_ptr<Program>;
    static Ptr Create(const MainClassDeclaration::Ptr& pMainClass, const Chain<ClassDeclaration>::Ptr& pClassDeclarations);
    void
    Accept(const std::shared_ptr<PrintVisitor> &pVisitor) override;
    void
    Accept(const std::shared_ptr<InterpreterVisitor> &pVisitor) override;
private:
    Program(const MainClassDeclaration::Ptr& pMainClass, const Chain<ClassDeclaration>::Ptr& pClassDeclarations);

    template<class V>
    void GenericAccept(const V& pVisitor);

    MainClassDeclaration::Ptr m_pMainClass;
    const Chain<ClassDeclaration>::Ptr m_pClassDeclarations;
};
