#include "Assignment.h"
#include "Expression.h"


#include <iostream>

Assignment::Assignment(const std::string& rVariable, const ArythmExpression::Ptr& pExpr)
    : m_rVar(rVariable)
    , m_pExpression(pExpr)
{
    std::cout << "\nAssigned value '" << m_pExpression->Eval() << "' to variable '" << m_rVar << "'\n";
}

Assignment::Ptr Assignment::Create(const std::string &rVariable, const Expression::Ptr &pExpr)
{
    return std::shared_ptr<Assignment>(new Assignment(rVariable,
                                                      std::dynamic_pointer_cast<ArythmExpression>(pExpr)));
}
