#include <iostream>
#include "Program.h"

#include "Identifier.h"
#include "Statement.h"
#include "Declarations.h"

MainClassDeclaration::Ptr MainClassDeclaration::Create(const Statement::Ptr &pStatement,
    const Identifier::Ptr &pClassName)
{
    return std::shared_ptr<MainClassDeclaration>(new MainClassDeclaration(pStatement, pClassName));
}


MainClassDeclaration::MainClassDeclaration(const Statement::Ptr &pStatement, const Identifier::Ptr &pMainClassName)
    : m_pMainClassStatement(pStatement)
    , m_pMainClassName(pMainClassName)
{

}


void MainClassDeclaration::Accept(PrintVisitor::Ptr visitor)
{
    std::cout << "Main class Visited" << std::endl;
    m_pMainClassStatement->Accept(visitor);
    m_pMainClassName->Accept(visitor);
}


Program::Ptr Program::Create(const MainClassDeclaration::Ptr &pMainClass,
                             const Chain<ClassDeclaration>::Ptr& pClassDeclarations)
{
    return std::shared_ptr<Program>(new Program(pMainClass, pClassDeclarations));
}


Program::Program(const MainClassDeclaration::Ptr &pMainClass, const Chain<ClassDeclaration>::Ptr& pClassDeclarations)
    : m_pMainClass(pMainClass)
    , m_pClassDeclarations(pClassDeclarations)
{}


void Program::Accept(PrintVisitor::Ptr visitor)
{
    std::cout << "Program Visited" << std::endl;
    m_pMainClass->Accept(visitor);
    m_pClassDeclarations->Accept(visitor);
}
