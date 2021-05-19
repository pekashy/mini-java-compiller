#pragma once
#include "Visitor.h"

class SymbolTableVisitor : public Visitor, public std::enable_shared_from_this<SymbolTableVisitor>
{
 public:
	using Ptr = std::shared_ptr<SymbolTableVisitor>;
	static SymbolTableVisitor::Ptr Create();
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
	SymbolTableVisitor() = default;
};