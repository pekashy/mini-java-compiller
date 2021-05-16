#include <iostream>
#include "Invocation.h"
#include "Expression.h"
#include "Identifier.h"

namespace
{
    class SimpleFieldInvocation : public FieldInvocation
    {
    public:
        explicit SimpleFieldInvocation(const Identifier::Ptr& pIdent)
        : m_pIdent(pIdent)
        {}

        void Accept(const std::shared_ptr<PrintVisitor> &pVisitor) override
        {
            std::cout << "Simple Field Invocation Visited" << std::endl;
            GenericAccept<PrintVisitor::Ptr>(pVisitor);
        }

        void Accept(const std::shared_ptr<InterpreterVisitor> &pVisitor) override
        {
            GenericAccept<InterpreterVisitor::Ptr>(pVisitor);
        }

        template<class V>
        void GenericAccept(const V& pVisitor)
        {
            pVisitor->Visit(m_pIdent);
        }


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


        void Accept(const std::shared_ptr<PrintVisitor> &pVisitor) override
        {
            std::cout << "Arr Field Invocation Visited" << std::endl;
            GenericAccept<PrintVisitor::Ptr>(pVisitor);
        }


        void Accept(const std::shared_ptr<InterpreterVisitor> &pVisitor) override
        {
            GenericAccept<InterpreterVisitor::Ptr>(pVisitor);
        }

        template<class V>
        void GenericAccept(const V& pVisitor)
        {
            pVisitor->Visit(m_pExpression);
            pVisitor->Visit(m_pIdent);
        }

    private:
        Identifier::Ptr m_pIdent;
        Expression::Ptr m_pExpression;
    };


    class MethodInvocationImpl : public MethodInvocation
    {
    public:
        MethodInvocationImpl(const std::shared_ptr<Expression>& calleeExpr, const std::shared_ptr<Identifier>& pIdent,
                           const std::shared_ptr<Expression>& pArgExpr)
            : m_pCalleeExpression(calleeExpr)
            , m_pIdent(pIdent)
            , m_pArgExpression(pArgExpr)
        {}

        void Accept(const std::shared_ptr<PrintVisitor> &pVisitor) override
        {
            std::cout << "Method Invocation Visited" << std::endl;
            GenericAccept<PrintVisitor::Ptr>(pVisitor);
        }

        void Accept(const std::shared_ptr<InterpreterVisitor> &pVisitor) override
        {
            GenericAccept<InterpreterVisitor::Ptr>(pVisitor);
        }

        template<class V>
        void GenericAccept(const V& pVisitor)
        {
            pVisitor->Visit(m_pArgExpression);
            //pVisitor->Visit(m_pIdent);
            //pVisitor->Visit(m_pCalleeExpression);
        }

    private:
        Expression::Ptr m_pCalleeExpression;
        Identifier::Ptr m_pIdent;
        Expression::Ptr m_pArgExpression;
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

MethodInvocation::Ptr MethodInvocation::Create(const std::shared_ptr<Expression>& caleeExpr,
    const std::shared_ptr<Identifier>& pIdent, const std::shared_ptr<Expression>& pArg)
{
    return std::make_shared<MethodInvocationImpl>(caleeExpr, pIdent, pArg);
}
