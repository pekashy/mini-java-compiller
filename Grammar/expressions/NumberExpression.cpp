#include "NumberExpression.h"

NumberExpression::NumberExpression(int value) noexcept {
    m_nValue = value;
}

int NumberExpression::Eval() const noexcept {
    return m_nValue;
}