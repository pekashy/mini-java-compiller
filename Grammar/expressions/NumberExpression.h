#pragma once
#include "Expression.h"

class NumberExpression: public Expression {
public:
    explicit NumberExpression(int value) noexcept;
    [[nodiscard]] int Eval() const noexcept override;
private:
    int m_nValue;
};