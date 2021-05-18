#pragma once

#include "GrammarNode.h"

class FieldInvocation;
class Identifier;
class Expression;

class Lvalue : public GrammarNode
{
 public:
	using Ptr = std::shared_ptr<Lvalue>;
	static Ptr Create(const std::shared_ptr<Identifier>& pIdent);
	static Ptr Create(const std::shared_ptr<Identifier>& pIdent, const std::shared_ptr<Expression>& pExpr);
	static Ptr Create(const std::shared_ptr<FieldInvocation>& pFieldInvoc);
	virtual ~Lvalue() = default;
 protected:
	Lvalue() = default;
};

