#pragma once
#include "Visitor.h"

#include <boost/core/noncopyable.hpp>

class Interpretable
{
 public:
	virtual ~Interpretable() = default;
 protected:
	virtual std::string GetInterpretation() const = 0;
};


class InterpreterVisitor : public Visitor, public std::enable_shared_from_this<InterpreterVisitor>
{
 public:
	using Ptr = std::shared_ptr<InterpreterVisitor>;
	static InterpreterVisitor::Ptr Create();
	void Visit(const std::shared_ptr<Assignment>& pNode) override;
	void Visit(const std::shared_ptr<BooleanExpression>& pNode) override;
	void Visit(const std::shared_ptr<Program>& pNode) override;
	void Visit(const std::shared_ptr<Lvalue>& pNode) override;
	void Visit(const std::shared_ptr<FieldInvocation>& pNode) override;
	void Visit(const std::shared_ptr<ClassDeclaration>& pNode) override;
	void Visit(const std::shared_ptr<Declaration>& pNode) override;
	void Visit(const std::shared_ptr<VariableDeclaration>& pNode) override;
	void Visit(const std::shared_ptr<SimpleType>& pNode) override;
	void Visit(const std::shared_ptr<ArrayType>& pNode) override;
	void Visit(const std::shared_ptr<Identifier>& pNode) override;
	void Visit(const std::shared_ptr<Formals>& pNode) override;
	void Visit(const std::shared_ptr<Formal>& pNode) override;
	void Visit(const std::shared_ptr<Statement>& pNode) override;
	void Visit(const std::shared_ptr<MethodInvocation>& pNode) override;
	void Visit(const std::shared_ptr<MainClassDeclaration>& pNode) override;
	void Visit(const std::shared_ptr<MethodDeclaration>& pNode) override;
	void Visit(const std::shared_ptr<Expression>& pNode) override;
	void Visit(const std::shared_ptr<Type>& pNode) override;

	void AddToResult(const std::string& rPart);
	std::string GetInterpreterResult() const;

	void LockInterpretation();
	void UnlockInterpretation();
 private:
	InterpreterVisitor();
	std::string m_rInterpreterResult;
	bool m_bInterpretationLocked;
};

class InterpretationLocker : public boost::noncopyable
{
 public:
	InterpretationLocker(const InterpreterVisitor::Ptr& pVisitor);
	~InterpretationLocker();
 private:
	InterpreterVisitor::Ptr m_pVisitor;
};
