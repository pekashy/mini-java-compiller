#include <Grammar/Assignment.h>
#include <Grammar/Expression.h>


#include <iostream>

Assignment::Assignment(const std::string& rVariable, const ArythmExpression::Ptr& pExpr)
    : m_rVar(rVariable)
    , m_pExpression(pExpr)
{}

Assignment::Ptr Assignment::Create(const std::string &rVariable, const Expression::Ptr &pExpr)
{
    return std::shared_ptr<Assignment>(new Assignment(rVariable,
                                                      std::dynamic_pointer_cast<ArythmExpression>(pExpr)));
}

void Assignment::Accept(const std::shared_ptr<PrintVisitor> &pVisitor)
{
    std::cout << "Assignment with value '" << m_pExpression->Eval() << "' and variable '" << m_rVar << "' Visited\n";
    GenericAccept<PrintVisitor::Ptr>(pVisitor);
}

void Assignment::Accept(const std::shared_ptr<InterpreterVisitor> &pVisitor)
{

}

template<class V>
void Assignment::GenericAccept(const V& pVisitor)
{
    pVisitor->Visit(m_pExpression);
}


