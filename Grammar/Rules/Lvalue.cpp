#include <iostream>
#include "Lvalue.h"
#include "Invocation.h"
#include "Identifier.h"
#include "Expression.h"

namespace
{
    class IdentifierLvalue : public Lvalue
    {
    public:
        IdentifierLvalue(const Identifier::Ptr& pIdent)
        : m_pIdentifier(pIdent)
        {}

        void Accept(PrintVisitor::Ptr pVisitor)
        {
            std::cout << "Identifier Lvalue Visited" << std::endl;
            m_pIdentifier->Accept(pVisitor);
        }

    private:
        Identifier::Ptr m_pIdentifier;
    };

    class ExpressionLvalue : public Lvalue
    {
    public:
        ExpressionLvalue(const Identifier::Ptr& pIdent, const Expression::Ptr& pExpression)
            : m_pIdentifier(pIdent)
            , m_pExpression(pExpression)
        {}


        void Accept(PrintVisitor::Ptr pVisitor)
        {
            std::cout << "Expression Lvalue Visited" << std::endl;
            m_pIdentifier->Accept(pVisitor);
            m_pExpression->Accept(pVisitor);
        }

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

        void Accept(PrintVisitor::Ptr visitor) override
        {
            std::cout << "Field Lvalue Visited" << std::endl;
            m_pInvocation->Accept(visitor);
        }
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
    return std::make_shared<ExpressionLvalue>(pIdent, pExpr);
}


Lvalue::Ptr Lvalue::Create(const FieldInvocation::Ptr& pFieldInvoc)
{
    return std::make_shared<FieldLvalue>(pFieldInvoc);
}
