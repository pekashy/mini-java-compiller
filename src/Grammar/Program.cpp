#include <iostream>

#include <Grammar/Program.h>
#include <Grammar/Statement.h>
#include <Grammar/Identifier.h>
#include <Grammar/Declarations.h>


MainClassDeclaration::Ptr MainClassDeclaration::Create(const Statement::Ptr& pStatement, const Identifier::Ptr& pClassName)
{
	return std::shared_ptr<MainClassDeclaration>(new MainClassDeclaration(pStatement, pClassName));
}

MainClassDeclaration::MainClassDeclaration(const Statement::Ptr& pStatement, const Identifier::Ptr& pMainClassName)
	: m_pMainClassStatement(pStatement), m_pMainClassName(pMainClassName)
{

}

void MainClassDeclaration::Accept(const std::shared_ptr<PrintVisitor>& pVisitor)
{
	std::cout << "Main class Visited" << std::endl;
	GenericAccept<PrintVisitor::Ptr>(pVisitor);
	pVisitor->Visit(m_pMainClassName);
}

void MainClassDeclaration::Accept(const std::shared_ptr<InterpreterVisitor>& pVisitor)
{
	GenericAccept<InterpreterVisitor::Ptr>(pVisitor);
	InterpretationLocker locker(pVisitor);
	pVisitor->Visit(m_pMainClassName);
}

template<class V> void MainClassDeclaration::GenericAccept(const V& pVisitor)
{
	pVisitor->Visit(m_pMainClassStatement);
}

Program::Ptr Program::Create(const MainClassDeclaration::Ptr& pMainClass, const Chain<ClassDeclaration>::Ptr& pClassDeclarations)
{
	return std::shared_ptr<Program>(new Program(pMainClass, pClassDeclarations));
}

Program::Program(const MainClassDeclaration::Ptr& pMainClass, const Chain<ClassDeclaration>::Ptr& pClassDeclarations)
	: m_pMainClass(pMainClass), m_pClassDeclarations(pClassDeclarations)
{
}

void Program::Accept(const std::shared_ptr<PrintVisitor>& pVisitor)
{
	std::cout << "Program Visited" << std::endl;
	GenericAccept<PrintVisitor::Ptr>(pVisitor);
}

void Program::Accept(const std::shared_ptr<InterpreterVisitor>& pVisitor)
{
	GenericAccept<InterpreterVisitor::Ptr>(pVisitor);
}

template<class V> void Program::GenericAccept(const V& pVisitor)
{
	pVisitor->Visit(m_pMainClass);
	m_pClassDeclarations->Accept(pVisitor);
}
