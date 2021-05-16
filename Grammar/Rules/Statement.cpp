#include <iostream>
#include "Statement.h"

#include "Identifier.h"
#include "Expression.h"
#include "Declarations.h"
#include "Lvalue.h"
#include "Invocation.h"

namespace
{
	class AssertionStatement : public Statement
	{
	 public:
		AssertionStatement(const Expression::Ptr& pExpression) : m_pExpr(pExpression)
		{
		}

		void Accept(const std::shared_ptr<PrintVisitor>& pVisitor) override
		{
			std::cout << "AssertionStatement Visited" << std::endl;
			GenericAccept<PrintVisitor::Ptr>(pVisitor);
		}

		void Accept(const std::shared_ptr<InterpreterVisitor>& pVisitor) override
		{
			GenericAccept<InterpreterVisitor::Ptr>(pVisitor);
		}

		template<class V> void GenericAccept(const V& pVisitor)
		{
			pVisitor->Visit(m_pExpr);
		}

	 private:
		Expression::Ptr m_pExpr;
	};

	class LocVarDeclStatement : public Statement
	{
	 public:
		LocVarDeclStatement(const VariableDeclaration::Ptr& pDeclaration) : m_pDecl(pDeclaration)
		{
		}

		void Accept(const std::shared_ptr<PrintVisitor>& pVisitor) override
		{
			std::cout << "LocalVarDeclStatement Visited" << std::endl;
			GenericAccept<PrintVisitor::Ptr>(pVisitor);
		}

		void Accept(const std::shared_ptr<InterpreterVisitor>& pVisitor) override
		{
			GenericAccept<InterpreterVisitor::Ptr>(pVisitor);
		}

		template<class V> void GenericAccept(const V& pVisitor)
		{
			pVisitor->Visit(m_pDecl);
		}

	 private:
		VariableDeclaration::Ptr m_pDecl;
	};

	class InnerStatement : public Statement
	{
	 public:
		InnerStatement(const Statement::Ptr& pStatement) : m_pStatement(pStatement)
		{
		}

		void Accept(const std::shared_ptr<PrintVisitor>& pVisitor) override
		{
			std::cout << "InnerStatement Visited" << std::endl;
			GenericAccept<PrintVisitor::Ptr>(pVisitor);
		}

		void Accept(const std::shared_ptr<InterpreterVisitor>& pVisitor) override
		{
			GenericAccept<InterpreterVisitor::Ptr>(pVisitor);
		}

		template<class V> void GenericAccept(const V& pVisitor)
		{
			pVisitor->Visit(m_pStatement);
		}

	 private:
		Statement::Ptr m_pStatement;
	};

	class IfStatement : public Statement
	{
	 public:
		IfStatement(const Expression::Ptr& pExpression, const Statement::Ptr& pStatement)
			: m_pExpression(pExpression), m_pStatement(pStatement)
		{
		}

		void Accept(const std::shared_ptr<PrintVisitor>& pVisitor) override
		{
			std::cout << "IfStatement Visited" << std::endl;
			GenericAccept<PrintVisitor::Ptr>(pVisitor);
		}

		void Accept(const std::shared_ptr<InterpreterVisitor>& pVisitor) override
		{
			GenericAccept<InterpreterVisitor::Ptr>(pVisitor);
		}

		template<class V> void GenericAccept(const V& pVisitor)
		{
			pVisitor->Visit(m_pExpression);
			pVisitor->Visit(m_pStatement);
		}

	 private:
		Expression::Ptr m_pExpression;
		Statement::Ptr m_pStatement;
	};

	class IfElseStatement : public Statement
	{
	 public:
		IfElseStatement(const Expression::Ptr& pExpression, const Statement::Ptr& pIfStatement, const Statement::Ptr& pElseStatement)
			: m_pExpression(pExpression), m_pIfStatement(pIfStatement), m_pElseStatement(pElseStatement)
		{
		}

		void Accept(const std::shared_ptr<PrintVisitor>& pVisitor) override
		{
			std::cout << "IfElseStatement Visited" << std::endl;
			GenericAccept<PrintVisitor::Ptr>(pVisitor);
		}

		void Accept(const std::shared_ptr<InterpreterVisitor>& pVisitor) override
		{
			GenericAccept<InterpreterVisitor::Ptr>(pVisitor);
		}

		template<class V> void GenericAccept(const V& pVisitor)
		{
			pVisitor->Visit(m_pExpression);
			pVisitor->Visit(m_pIfStatement);
			pVisitor->Visit(m_pElseStatement);
		}

	 private:
		Expression::Ptr m_pExpression;
		Statement::Ptr m_pIfStatement;
		Statement::Ptr m_pElseStatement;
	};

	class WhileStatement : public Statement
	{
	 public:
		WhileStatement(const Expression::Ptr& pExpression, const Statement::Ptr& pStatement)
			: m_pExpression(pExpression), m_pStatement(pStatement)
		{
		}

		void Accept(const std::shared_ptr<PrintVisitor>& pVisitor) override
		{
			std::cout << "WhileStatement Visited" << std::endl;
			GenericAccept<PrintVisitor::Ptr>(pVisitor);
		}

		void Accept(const std::shared_ptr<InterpreterVisitor>& pVisitor) override
		{
			GenericAccept<InterpreterVisitor::Ptr>(pVisitor);
		}

		template<class V> void GenericAccept(const V& pVisitor)
		{
			pVisitor->Visit(m_pExpression);
			pVisitor->Visit(m_pStatement);
		}

	 private:
		Expression::Ptr m_pExpression;
		Statement::Ptr m_pStatement;
	};

	class PrintStatement : public Statement
	{
	 public:
		explicit PrintStatement(const Expression::Ptr& pExpression) : m_pExpr(pExpression)
		{
		}

		void Accept(const std::shared_ptr<PrintVisitor>& pVisitor) override
		{
			std::cout << "PrintStatement Visited" << std::endl;
			GenericAccept<PrintVisitor::Ptr>(pVisitor);
		}

		void Accept(const std::shared_ptr<InterpreterVisitor>& pVisitor) override
		{
			GenericAccept<InterpreterVisitor::Ptr>(pVisitor);
		}

		template<class V> void GenericAccept(const V& pVisitor)
		{
			pVisitor->Visit(m_pExpr);
		}
	 private:
		Expression::Ptr m_pExpr;
	};

	class ReturnStatement : public Statement
	{
	 public:
		explicit ReturnStatement(const Expression::Ptr& pExpression) : m_pExpr(pExpression)
		{
		}

		void Accept(const std::shared_ptr<PrintVisitor>& pVisitor) override
		{
			std::cout << "ReturnStatement Visited" << std::endl;
			GenericAccept<PrintVisitor::Ptr>(pVisitor);
		}

		void Accept(const std::shared_ptr<InterpreterVisitor>& pVisitor) override
		{
			GenericAccept<InterpreterVisitor::Ptr>(pVisitor);
		}

		template<class V> void GenericAccept(const V& pVisitor)
		{
			pVisitor->Visit(m_pExpr);
		}

	 private:
		Expression::Ptr m_pExpr;
	};

	class AssignmentStatement : public Statement
	{
	 public:
		AssignmentStatement(const Expression::Ptr& pExpression, const Lvalue::Ptr& pLvalue)
			: m_pExpression(pExpression), m_pLvalue(pLvalue)
		{
		}

		void Accept(const std::shared_ptr<PrintVisitor>& pVisitor) override
		{
			std::cout << "AssignmentStatement Visited" << std::endl;
			GenericAccept<PrintVisitor::Ptr>(pVisitor);
		}

		void Accept(const std::shared_ptr<InterpreterVisitor>& pVisitor) override
		{
			GenericAccept<InterpreterVisitor::Ptr>(pVisitor);
		}

		template<class V> void GenericAccept(const V& pVisitor)
		{
			pVisitor->Visit(m_pExpression);
			pVisitor->Visit(m_pLvalue);
		}

	 private:
		Expression::Ptr m_pExpression;
		Lvalue::Ptr m_pLvalue;
	};

	class MethodInvocStatement : public Statement
	{
	 public:
		explicit MethodInvocStatement(const MethodInvocation::Ptr& pMethod) : m_pMethod(m_pMethod)
		{
		}

		void Accept(const std::shared_ptr<PrintVisitor>& pVisitor) override
		{
			std::cout << "MethodInvocStatement Visited" << std::endl;
			GenericAccept<PrintVisitor::Ptr>(pVisitor);
		}

		void Accept(const std::shared_ptr<InterpreterVisitor>& pVisitor) override
		{
			GenericAccept<InterpreterVisitor::Ptr>(pVisitor);
		}

		template<class V> void GenericAccept(const V& pVisitor)
		{
			pVisitor->Visit(m_pMethod);
		}

	 private:
		MethodInvocation::Ptr m_pMethod;
	};
}

Statement::Ptr Statement::CreateAssertion(const std::shared_ptr<Expression>& pExpression)
{
	return std::shared_ptr<AssertionStatement>(new AssertionStatement(pExpression));
}

Statement::Ptr Statement::CreateLocalVarDeclaration(const std::shared_ptr<VariableDeclaration>& pDeclaration)
{
	return std::shared_ptr<LocVarDeclStatement>(new LocVarDeclStatement(pDeclaration));
}

Statement::Ptr Statement::CreateInnerStatement(const Statement::Ptr& pStatement)
{
	return std::shared_ptr<InnerStatement>(new InnerStatement(pStatement));
}

Statement::Ptr Statement::CreateIf(const std::shared_ptr<Expression>& pExpression, const Statement::Ptr& pStatement)
{
	return std::shared_ptr<IfStatement>(new IfStatement(pExpression, pStatement));
}

Statement::Ptr Statement::CreateIfElse(const std::shared_ptr<Expression>& pExpression, const Statement::Ptr& pIfStatement, const Statement::Ptr& pElseStatement)
{
	return std::shared_ptr<IfElseStatement>(new IfElseStatement(pExpression, pIfStatement, pElseStatement));
}

Statement::Ptr Statement::CreateWhile(const std::shared_ptr<Expression>& pExpression, const Statement::Ptr& pStatement)
{
	return std::shared_ptr<WhileStatement>(new WhileStatement(pExpression, pStatement));
}

Statement::Ptr Statement::CreatePrint(const std::shared_ptr<Expression>& pExpression)
{
	return std::shared_ptr<PrintStatement>(new PrintStatement(pExpression));
}

Statement::Ptr Statement::CreateAssignment(const std::shared_ptr<Expression>& pExpression, const std::shared_ptr<Lvalue>& pLvalue)
{
	return std::shared_ptr<AssignmentStatement>(new AssignmentStatement(pExpression, pLvalue));
}

Statement::Ptr Statement::CreateReturn(const std::shared_ptr<Expression>& pExpression)
{
	return std::shared_ptr<ReturnStatement>(new ReturnStatement(pExpression));
}

Statement::Ptr Statement::CreateMethodInvoc(const std::shared_ptr<MethodInvocation>& pInvoc)
{
	return std::shared_ptr<MethodInvocStatement>(new MethodInvocStatement(pInvoc));
}
