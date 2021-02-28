#include "Assignment.h"
#include <iostream>

Assignment::Assignment(const std::string& rVariable, const GrammarNode::Ptr& pNode)
    : m_rVar(rVariable)
{
    auto pAssignment = std::dynamic_pointer_cast<Expression>(pNode);
    if(pAssignment)
    {
        m_pExpression = pAssignment;
    }
    else
    {
        throw std::runtime_error("Tried to add non-expression type to assignment!");
    }
    std::cout << "\nAssigned value '" << m_pExpression->Eval() << "' to variable '" << m_rVar << "'\n";
}