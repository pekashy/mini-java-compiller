#pragma once

#include "Expression.h"
#include "../GrammarNode.h"

#include <string>
#include <memory>

class Assignment : public GrammarNode{
 public:
    using Ptr = std::shared_ptr<Assignment>;
    static Ptr Create(const std::string& rVariable, const Expression::Ptr& pExpr);
 private:
    Assignment(const std::string& rVariable, const Expression::Ptr& pExpr);
    std::string m_rVar;
    Expression::Ptr m_pExpression;
};