#pragma once
#include "Expression.h"

#include <functional>

class ArythmExpression: public Expression {
public:
    ArythmExpression(const GrammarNode::Ptr& e1, const GrammarNode::Ptr& e2, char action);
    [[nodiscard]] int Eval() const noexcept override;
private:
    Expression::Ptr m_pFirst;
    Expression::Ptr m_pSecond;
    std::function<int(const Expression::Ptr& e1, const Expression::Ptr& e2)> m_fnAction;
};