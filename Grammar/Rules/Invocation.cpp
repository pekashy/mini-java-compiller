#include "Invocation.h"
#include "Expression.h"

namespace
{
    class SimpleFieldInvocation : public FieldInvocation
    {
    public:
        explicit SimpleFieldInvocation(const Identifier::Ptr& pIdent)
        : m_pIdent(pIdent)
        {}
    private:
        Identifier::Ptr m_pIdent;
    };

    class ArrFieldInvocation : public FieldInvocation
    {
    public:
        ArrFieldInvocation(const Identifier::Ptr& pIdent, const Expression::Ptr& pExpr)
        : m_pIdent(pIdent)
        , m_pExpression(pExpr)
        {}
    private:
        Identifier::Ptr m_pIdent;
        Expression::Ptr m_pExpression;
    };
}

FieldInvocation::Ptr FieldInvocation::Create(const Identifier::Ptr& pIdent)
{
    return std::make_shared<SimpleFieldInvocation>(pIdent);
}


FieldInvocation::Ptr FieldInvocation::Create(const Identifier::Ptr& pIdent, const Expression::Ptr& pExpr)
{
    return std::make_shared<ArrFieldInvocation>(pIdent, pExpr);
}
