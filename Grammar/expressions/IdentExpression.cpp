#include "IdentExpression.h"

IdentExpression::IdentExpression(const std::string& rIdent) noexcept
    : m_rIdent(rIdent)
    {}

int IdentExpression::Eval() const noexcept {
    return 0;
}