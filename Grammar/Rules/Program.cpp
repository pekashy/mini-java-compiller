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


Program::Ptr Program::Create(const MainClassDeclaration::Ptr &pMainClass,
    const ClassDeclaration::Ptr &pMainClassDeclaration)
{
    return std::shared_ptr<Program>(new Program(pMainClass, pMainClassDeclaration));
}


Program::Program(const MainClassDeclaration::Ptr &pMainClass, const ClassDeclaration::Ptr &pMainClassDeclaration)
    : m_pMainClass(pMainClass)
    , m_pMainClassDeclaration(pMainClassDeclaration)
{}
