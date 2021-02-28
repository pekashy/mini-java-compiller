#pragma once

#include "GrammarNode.h"
#include "assignments/Assignment.h"
#include "assignments/AssignmentList.h"

namespace NodeFactory
{
    Assignment::Ptr CreateAssignment(const std::string& rVariable, const GrammarNode::Ptr& pExpression);
    AssignmentList::Ptr CreateAssignmentList() noexcept;
    GrammarNode::Ptr CreateAddExpression(const GrammarNode::Ptr& pE1, const GrammarNode::Ptr& pE2);
    GrammarNode::Ptr CreateSubstractExpression(const GrammarNode::Ptr& pE1, const GrammarNode::Ptr& pE2);
    GrammarNode::Ptr CreateMulExpression(const GrammarNode::Ptr& pE1, const GrammarNode::Ptr& pE2);
    GrammarNode::Ptr CreateDivExpression(const GrammarNode::Ptr& pE1, const GrammarNode::Ptr& pE2);
    GrammarNode::Ptr CreateNumberExpression(int nValue) noexcept;
    GrammarNode::Ptr CreateIdentExpression(const std::string& rIdent) noexcept;

};

