#include "NodeFactory.h"
#include "assignments/Assignment.h"
#include "assignments/AssignmentList.h"
#include "expressions/ArythmExpression.h"
#include "expressions/NumberExpression.h"
#include "expressions/IdentExpression.h"

#include <memory>

Assignment::Ptr NodeFactory::CreateAssignment(const std::string& rVariable, const GrammarNode::Ptr& pExpression)
{
    return std::make_shared<Assignment>(rVariable, pExpression);
}

AssignmentList::Ptr NodeFactory::CreateAssignmentList() noexcept
{
    return std::make_shared<AssignmentList>();
}

GrammarNode::Ptr NodeFactory::CreateAddExpression(const GrammarNode::Ptr& pE1, const GrammarNode::Ptr& pE2)
{
    return std::make_shared<ArythmExpression>(pE1, pE2, '+');
}

GrammarNode::Ptr NodeFactory::CreateSubstractExpression(const GrammarNode::Ptr& pE1, const GrammarNode::Ptr& pE2)
{
    return std::make_shared<ArythmExpression>(pE1, pE2, '-');
}

GrammarNode::Ptr NodeFactory::CreateMulExpression(const GrammarNode::Ptr& pE1, const GrammarNode::Ptr& pE2)
{
    return std::make_shared<ArythmExpression>(pE1, pE2, '*');
}

GrammarNode::Ptr NodeFactory::CreateDivExpression(const GrammarNode::Ptr& pE1, const GrammarNode::Ptr& pE2)
{
    return std::make_shared<ArythmExpression>(pE1, pE2, '/');
}

GrammarNode::Ptr NodeFactory::CreateNumberExpression(int nValue) noexcept
{
    return std::make_shared<NumberExpression>(nValue);
}

GrammarNode::Ptr NodeFactory::CreateIdentExpression(const std::string& rIdent) noexcept
{
    return std::make_shared<IdentExpression>(rIdent);
}