#pragma once

#include "GrammarNode.h"
#include <memory>

class Identifier;
class SimpleType;
class Type;
class MethodInvocation;
class FieldInvocation;



class Evaluable : public Interpretable
{
 public:
	using Ptr = std::shared_ptr<Evaluable>;
	[[nodiscard]] virtual int Eval() const = 0;
	virtual ~Evaluable() = default;

 protected:
	std::string GetInterpretation() const override
	{
		return std::to_string(Eval());
	}
};

class Expression : public GrammarNode
{
 public:
	using Ptr = std::shared_ptr<Expression>;
	static Ptr CreateIdentExpression(const std::shared_ptr<Identifier>& pIdent) noexcept;
	static Ptr CreateThisExpression() noexcept;
	static Ptr CreateLengthExpression(const Ptr& pExpression) noexcept;
	static Ptr CreateStackVarCreationExpression(const std::shared_ptr<SimpleType> pType, const Ptr& pExpr) noexcept;
	static Ptr CreateHeapVarCreationExpression(const std::shared_ptr<Identifier>& pIdent) noexcept;
	static Ptr CreateMethodInvocationExpression(const std::shared_ptr<MethodInvocation>& pInvoc) noexcept;
	static Ptr CreateFieldInvocationExpression(const std::shared_ptr<FieldInvocation>& pInvoc) noexcept;

	virtual ~Expression() = default;
 protected:
	Expression() = default;
};

class ArythmExpression : public Expression, public Evaluable
{
 public:
	using Ptr = std::shared_ptr<ArythmExpression>;

	static Ptr CreateAddExpression(const Expression::Ptr& pE1, const Expression::Ptr& pE2);
	static Ptr CreateSubstractExpression(const Expression::Ptr& pE1, const Expression::Ptr& pE2);
	static Ptr CreateMulExpression(const Expression::Ptr& pE1, const Expression::Ptr& pE2);
	static Ptr CreateDivExpression(const Expression::Ptr& pE1, const Expression::Ptr& pE2);
	static Ptr CreateNumberExpression(int nValue) noexcept;

	virtual ~ArythmExpression() = default;
};

class BooleanExpression : public Expression, public Evaluable
{
 public:
	using Ptr = std::shared_ptr<BooleanExpression>;

	static Ptr CreateInverseExpression(const Expression::Ptr& pExpression);
	static Ptr CreateComparasmentExpression(const Expression::Ptr& pExpression1, std::string action, const Expression::Ptr& pExpression2);
	static Ptr CreateBoolExpression(bool bValue) noexcept;

	virtual ~BooleanExpression() = default;
};