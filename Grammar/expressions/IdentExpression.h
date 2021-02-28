#pragma once
#include "Expression.h"

#include <string>

class IdentExpression: public Expression {
 public:
    explicit IdentExpression(const std::string& rIdent)  noexcept;
    [[nodiscard]] int Eval() const noexcept override;
 private:
    std::string m_rIdent;
};