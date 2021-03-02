#pragma once

#include "../GrammarNode.h"

#include <string>
#include <memory>

class Expression;

class Assignment : public GrammarNode{
 public:
    using Ptr = std::shared_ptr<Assignment>;
    static Ptr Create(const std::string& rVariable, const std::shared_ptr<Expression>& pExpr);
 private:
    Assignment(const std::string& rVariable, const std::shared_ptr<Expression>& pExpr);
    std::string m_rVar;
    std::shared_ptr<Expression> m_pExpression;
};