#pragma once

#include "Declarations.h"

class MainClassDeclaration : public GrammarNode
{
public:
    using Ptr = std::shared_ptr<MainClassDeclaration>;
    static Ptr Create(const Statement::Ptr& pStatement, const Identifier::Ptr& pClassName);
private:
    MainClassDeclaration(const Statement::Ptr& pMainClassStatement, const Identifier::Ptr& pMainClassName);
    Statement::Ptr m_pMainClassStatement;
    Identifier::Ptr m_pMainClassName;
};


// TODO: allow to create multiple classes
class Program : public GrammarNode
{
public:
    using Ptr = std::shared_ptr<Program>;
    static Ptr Create(const MainClassDeclaration::Ptr& pMainClass, const ClassDeclaration::Ptr& pMainClassDeclaration);
private:
    Program(const MainClassDeclaration::Ptr& pMainClass, const ClassDeclaration::Ptr& pMainClassDeclaration);
    MainClassDeclaration::Ptr m_pMainClass;
    ClassDeclaration::Ptr m_pMainClassDeclaration;
};
