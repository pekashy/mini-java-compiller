#pragma once

#include "GrammarNode.h"

class Identifier;
class Expression;

class FieldInvocation : public GrammarNode
{
 public:
	using Ptr = std::shared_ptr<FieldInvocation>;
	static Ptr Create(const std::shared_ptr<Identifier>& pIdent);
	static Ptr Create(const std::shared_ptr<Identifier>& pIdent, const std::shared_ptr<Expression>& pExpr);
	virtual ~FieldInvocation() = default;
 protected:
	FieldInvocation() = default;
};

class MethodInvocation : public GrammarNode
{
 public:
	using Ptr = std::shared_ptr<MethodInvocation>;
	static Ptr Create(const std::shared_ptr<Expression>& caleeExpr, const std::shared_ptr<Identifier>& pIdent, const std::shared_ptr<
		Expression>& arg);
	virtual ~MethodInvocation() = default;
 protected:
	MethodInvocation() = default;
};
