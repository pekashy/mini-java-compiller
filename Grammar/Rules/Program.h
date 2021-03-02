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
private:
    MainClassDeclaration(const std::shared_ptr<Statement>& pMainClassStatement, const std::shared_ptr<Identifier>& pMainClassName);
    std::shared_ptr<Statement> m_pMainClassStatement;
    std::shared_ptr<Identifier> m_pMainClassName;
};


// TODO: allow to create multiple classes
class Program : public GrammarNode
{
public:
    using Ptr = std::shared_ptr<Program>;
    static Ptr Create(const MainClassDeclaration::Ptr& pMainClass, const std::shared_ptr<ClassDeclaration>& pMainClassDeclaration);
private:
    Program(const MainClassDeclaration::Ptr& pMainClass, const std::shared_ptr<ClassDeclaration>& pMainClassDeclaration);
    MainClassDeclaration::Ptr m_pMainClass;
    std::shared_ptr<ClassDeclaration> m_pMainClassDeclaration;
};
