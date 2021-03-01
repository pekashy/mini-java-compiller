#include "Lvalue.h"
#include "Invocation.h"

namespace
{
    class IdentifierLvalue : public Lvalue
    {
    public:
        IdentifierLvalue(const Identifier::Ptr& pIdent)
        : m_pIdentifier(pIdent)
        {}
    private:
        Identifier::Ptr m_pIdentifier;
    };

    class EpressionLvalue : public Lvalue
    {
    public:
        EpressionLvalue(const Identifier::Ptr& pIdent, const Expression::Ptr& pExpression)
            : m_pIdentifier(pIdent)
            , m_pExpression(pExpression)
        {}
    private:
        Identifier::Ptr m_pIdentifier;
        Expression::Ptr m_pExpression;
    };


    class FieldLvalue : public Lvalue
    {
    public:
        FieldLvalue(const FieldInvocation::Ptr& pInvoc)
            : m_pInvocation(pInvoc)
        {}
    private:
        FieldInvocation::Ptr m_pInvocation;
    };
}


Lvalue::Ptr Lvalue::Create(const Identifier::Ptr& pIdent)
{
    return std::make_shared<IdentifierLvalue>(pIdent);
}


Lvalue::Ptr Lvalue::Create(const Identifier::Ptr& pIdent, const Expression::Ptr& pExpr)
{
    return std::make_shared<EpressionLvalue>(pIdent, pExpr);
}


Lvalue::Ptr Lvalue::Create(const FieldInvocation::Ptr& pFieldInvoc)
{
    return std::make_shared<FieldLvalue>(pFieldInvoc);
}
