#include <stdexcept>
#include "ArythmExpression.h"

ArythmExpression::ArythmExpression(const GrammarNode::Ptr& pN1, const GrammarNode::Ptr& pN2, char action)
{
    auto pE1 = std::dynamic_pointer_cast<Expression>(pN1);
    auto pE2 = std::dynamic_pointer_cast<Expression>(pN2);

    if(pE1 && pE2)
    {
        m_pFirst = pE1;
        m_pSecond = pE2;
    }
    else
    {
        throw std::runtime_error("Tried to make arithmetic operation on non-expression types!");
    }


    switch(action)
    {
        case '+':
            m_fnAction = [](const Expression::Ptr& pE1, const Expression::Ptr& pE2) -> int
            { return pE1->Eval() + pE2->Eval(); };
            break;
        case '-':
            m_fnAction = [](const Expression::Ptr& pE1, const Expression::Ptr& pE2) -> int
            { return pE1->Eval() - pE2->Eval(); };
            break;
        case '*':
            m_fnAction = [](const Expression::Ptr& pE1, const Expression::Ptr& pE2) -> int
            { return pE1->Eval() * pE2->Eval(); };
            break;
        case '/':
            m_fnAction = [](const Expression::Ptr& pE1, const Expression::Ptr& pE2) -> int
            { return pE1->Eval() / pE2->Eval(); };
            break;
        default:
            throw std::runtime_error("Unsupported arythmetic operator!");
    }
}

int ArythmExpression::Eval() const noexcept {
    return m_fnAction(m_pFirst, m_pSecond);
}