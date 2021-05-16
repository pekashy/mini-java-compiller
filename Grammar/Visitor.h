#pragma once

#include <memory>

class Assignment;
class Expression;
class BooleanExpression;
class GrammarNode;
class Location;
class Scanner;
class CompilerDriver;
class Program;
class Lvalue;
class FieldInvocation;
class ClassDeclaration;
class Declaration;
class VariableDeclaration;
class Type;
class SimpleType;
class ArrayType;
class Identifier;
class Formals;
class Formal;
class Statement;
class MethodInvocation;
class MainClassDeclaration;
class MethodDeclaration;
class Type;

class Visitor
{
 public:
	virtual ~Visitor() = default;
	virtual void Visit(const std::shared_ptr<Expression>& pNode) = 0;
	virtual void Visit(const std::shared_ptr<Assignment>& pNode) = 0;
	virtual void Visit(const std::shared_ptr<BooleanExpression>& pNode) = 0;
	virtual void Visit(const std::shared_ptr<Program>& pNode) = 0;
	virtual void Visit(const std::shared_ptr<Lvalue>& pNode) = 0;
	virtual void Visit(const std::shared_ptr<FieldInvocation>& pNode) = 0;
	virtual void Visit(const std::shared_ptr<ClassDeclaration>& pNode) = 0;
	virtual void Visit(const std::shared_ptr<Declaration>& pNode) = 0;
	virtual void Visit(const std::shared_ptr<VariableDeclaration>& pNode) = 0;
	virtual void Visit(const std::shared_ptr<SimpleType>& pNode) = 0;
	virtual void Visit(const std::shared_ptr<ArrayType>& pNode) = 0;
	virtual void Visit(const std::shared_ptr<Identifier>& pNode) = 0;
	virtual void Visit(const std::shared_ptr<Formals>& pNode) = 0;
	virtual void Visit(const std::shared_ptr<Formal>& pNode) = 0;
	virtual void Visit(const std::shared_ptr<Statement>& pNode) = 0;
	virtual void Visit(const std::shared_ptr<MethodInvocation>& pNode) = 0;
	virtual void Visit(const std::shared_ptr<MainClassDeclaration>& pNode) = 0;
	virtual void Visit(const std::shared_ptr<MethodDeclaration>& pNode) = 0;
	virtual void Visit(const std::shared_ptr<Type>& pNode) = 0;

 protected:
	Visitor() = default;
};

class PrintVisitor : public Visitor, public std::enable_shared_from_this<PrintVisitor>
{
 public:
	using Ptr = std::shared_ptr<PrintVisitor>;
	static PrintVisitor::Ptr Create();
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
 private:
	PrintVisitor() = default;
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
 private:
	InterpreterVisitor() = default;
};
