#pragma once

#include "../expressions/Expression.h"
#include "../GrammarNode.h"

#include <string>
#include <memory>

class Assignment : public GrammarNode{
 public:
    using Ptr = std::shared_ptr<Assignment>;
    Assignment(const std::string& rVariable, const GrammarNode::Ptr& pNode);
 private:
    std::string m_rVar;
    Expression::Ptr  m_pExpression;
};