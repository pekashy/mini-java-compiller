#include "Expression.h"

#include <functional>
#include <string>
#include <stdexcept>


namespace
{
    class ArythmExpression: public Expression {
    public:
        ArythmExpression(const Ptr& e1, const Ptr& e2, char action);
        [[nodiscard]] int Eval() const noexcept override;
    private:
        Expression::Ptr m_pFirst;
        Expression::Ptr m_pSecond;
        std::function<int(const Expression::Ptr& e1, const Expression::Ptr& e2)> m_fnAction;
    };

    class IdentExpression: public Expression {
    public:
        explicit IdentExpression(const std::string& rIdent)  noexcept;
        [[nodiscard]] int Eval() const noexcept override;
    private:
        std::string m_rIdent;
    };

    class NumberExpression: public Expression {
    public:
        explicit NumberExpression(int value) noexcept;
        [[nodiscard]] int Eval() const noexcept override;
    private:
        int m_nValue;
    };
}


ArythmExpression::ArythmExpression(const Ptr& pN1, const Ptr& pN2, char action)
    : m_pFirst(pN1)
    , m_pSecond(pN2)
{
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


IdentExpression::IdentExpression(const std::string& rIdent) noexcept
    : m_rIdent(rIdent)
{}


int IdentExpression::Eval() const noexcept {
    return 0;
}


NumberExpression::NumberExpression(int value) noexcept {
    m_nValue = value;
}


int NumberExpression::Eval() const noexcept {
    return m_nValue;
}


Expression::Ptr Expression::CreateAddExpression(const Ptr& pE1, const Ptr& pE2)
{
    return std::make_shared<ArythmExpression>(pE1, pE2, '+');
}


Expression::Ptr Expression::CreateSubstractExpression(const Ptr& pE1, const Ptr& pE2)
{
    return std::make_shared<ArythmExpression>(pE1, pE2, '-');
}


Expression::Ptr Expression::CreateMulExpression(const Ptr& pE1, const Ptr& pE2)
{
    return std::make_shared<ArythmExpression>(pE1, pE2, '*');
}


Expression::Ptr Expression::CreateDivExpression(const Ptr& pE1, const Ptr& pE2)
{
    return std::make_shared<ArythmExpression>(pE1, pE2, '/');
}


Expression::Ptr Expression::CreateNumberExpression(int nValue) noexcept
{
    return std::make_shared<NumberExpression>(nValue);
}


Expression::Ptr Expression::CreateIdentExpression(const std::string& rIdent) noexcept
{
    return std::make_shared<IdentExpression>(rIdent);
}
