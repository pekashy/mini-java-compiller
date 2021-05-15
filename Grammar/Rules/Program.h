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
    void Accept(PrintVisitor::Ptr visitor) override;
private:
    MainClassDeclaration(const std::shared_ptr<Statement>& pMainClassStatement, const std::shared_ptr<Identifier>& pMainClassName);
    std::shared_ptr<Statement> m_pMainClassStatement;
    std::shared_ptr<Identifier> m_pMainClassName;
};


class Program : public GrammarNode
{
public:
    using Ptr = std::shared_ptr<Program>;
    static Ptr Create(const MainClassDeclaration::Ptr& pMainClass, const Chain<ClassDeclaration>::Ptr& pClassDeclarations);
    void
    Accept(PrintVisitor::Ptr visitor) override;
private:
    Program(const MainClassDeclaration::Ptr& pMainClass, const Chain<ClassDeclaration>::Ptr& pClassDeclarations);
    MainClassDeclaration::Ptr m_pMainClass;
    const Chain<ClassDeclaration>::Ptr m_pClassDeclarations;
};
