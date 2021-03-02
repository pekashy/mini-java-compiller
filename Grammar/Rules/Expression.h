#pragma once

#include "../GrammarNode.h"
#include <memory>

class Identifier;

class Expression : public GrammarNode
{
public:
    using Ptr = std::shared_ptr<Expression>;
    [[nodiscard]] virtual int Eval() const noexcept = 0;
    static Ptr CreateAddExpression(const Ptr& pE1, const Ptr& pE2);
    static Ptr CreateSubstractExpression(const Ptr& pE1, const Ptr& pE2);
    static Ptr CreateMulExpression(const Ptr& pE1, const Ptr& pE2);
    static Ptr CreateDivExpression(const Ptr& pE1, const Ptr& pE2);
    static Ptr CreateNumberExpression(int nValue) noexcept;
    static Ptr CreateIdentExpression(const std::shared_ptr<Identifier>& pIdent) noexcept;
protected:
    Expression() = default;
};
