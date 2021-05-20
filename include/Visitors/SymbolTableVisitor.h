#pragma once
#include "Visitor.h"

#include <SymbolTree/ScopeTree.h>
#include <stack>
#include <utility>
#include <boost/core/noncopyable.hpp>

#include <stdexcept>

class Scope;
class ScopeNode;

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

	void AddVarType(const std::string& varType);
	void AddVarName(const std::string& varName);
	void EnterNewScope();
	void ExitCurrentScope();

 private:
	std::stack<std::string> m_varTypeStack;
	std::stack<std::string> m_varNameStack;
	std::stack<std::string> m_methodRetValueStack;
	std::stack<std::string> m_methodNameStack;
	std::stack<std::pair<std::string, std::string>> m_methodArgStack;
	std::stack<std::string> m_classNameStack;

	std::stack<std::shared_ptr<ScopeNode>> m_scopeStack;
	std::shared_ptr<Scope> m_pCurrentScope;

	SymbolTableVisitor();
	ScopeTree scopeTree;
};

class ScopeIncrementer : public boost::noncopyable
{
 public:
	ScopeIncrementer(const SymbolTableVisitor::Ptr& pVisitor);
	~ScopeIncrementer();
 private:
	SymbolTableVisitor::Ptr m_pVisitor;
};