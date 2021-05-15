#include "Expression.h"
#include "Identifier.h"
#include "Types.h"
#include "Invocation.h"

#include <functional>
#include <stdexcept>
#include <iostream>

namespace
{
    class ArythmExpressionImpl: public ArythmExpression {
    public:
        ArythmExpressionImpl(const Expression::Ptr& e1, const Expression::Ptr& e2, char action);
        [[nodiscard]] int Eval() const noexcept;
        
        void Accept(PrintVisitor::Ptr pVisitor)
        {
            std::cout << "Arythm expression Visited" << std::endl;
            m_pFirst->Accept(pVisitor);
            m_pSecond->Accept(pVisitor);
        }
        
    private:
        Expression::Ptr m_pFirst;
        Expression::Ptr m_pSecond;
        std::function<int(const Ptr& e1, const Ptr& e2)> m_fnAction;
    };

    class IdentExpression: public Expression {
    public:
        explicit IdentExpression(const std::shared_ptr<Identifier>& pIdent)  noexcept;
        void Accept(PrintVisitor::Ptr pVisitor)
        {
            std::cout << "Ident expression Visited" << std::endl;
            m_pIdent->Accept(pVisitor);
        }

    private:
        Identifier::Ptr m_pIdent;
    };

    class ThisExpression: public Expression {
    public:
        explicit ThisExpression()  noexcept = default;
        
        void Accept(PrintVisitor::Ptr pVisitor)
        {
            std::cout << "This expression Visited" << std::endl;
        }
    };


class NumberExpression: public ArythmExpression {
    public:
        explicit NumberExpression(int value) noexcept;
        int Eval() const noexcept override;

        void Accept(PrintVisitor::Ptr pVisitor)
        {
            std::cout << "Number expression: '" << m_nValue << "' Visited" << std::endl;
        }
private:
        int m_nValue;
    };


    class LengthExpression: public Expression
    {
    public:
        explicit LengthExpression(const Expression::Ptr& pExpr) noexcept
        : m_pExpr(pExpr)
        {}

        void Accept(PrintVisitor::Ptr pVisitor)
        {
            std::cout << "Length expression Visited" << std::endl;
            m_pExpr->Accept(pVisitor);
        }

    private:
        Expression::Ptr m_pExpr;
    };


    class StackVarCreationExpression: public Expression
    {
    public:
        explicit StackVarCreationExpression(const SimpleType::Ptr pType, const Ptr& pExpr) noexcept
            : m_pType(pType)
            , m_pExpr(pExpr)
        {}

        void Accept(PrintVisitor::Ptr pVisitor)
        {
            std::cout << "Stack var creation expression Visited" << std::endl;
            m_pType->Accept(pVisitor);
            m_pExpr->Accept(pVisitor);
        }

    private:
        SimpleType::Ptr m_pType;
        Expression::Ptr m_pExpr;
    };


    class HeapVarCreationExpression: public Expression
    {
    public:
        explicit HeapVarCreationExpression(const Identifier::Ptr& pType) noexcept
            : m_pType(pType)
        {}

        void Accept(PrintVisitor::Ptr pVisitor)
        {
            std::cout << "Heap var creation expression Visited" << std::endl;
            m_pType->Accept(pVisitor);
        }

    private:
        Identifier::Ptr m_pType;
    };


    class SimplyTypeExpression: public Expression
    {
    public:
        explicit SimplyTypeExpression(const SimpleType::Ptr& pType) noexcept
            : m_pType(pType)
        {}

        void Accept(PrintVisitor::Ptr pVisitor)
        {
            std::cout << "Simple type expression Visited" << std::endl;
            m_pType->Accept(pVisitor);
        }

    private:
        SimpleType::Ptr m_pType;
    };


    class TypeIdentExpression: public Expression
    {
    public:
        explicit TypeIdentExpression(const Identifier::Ptr& pType) noexcept
            : m_pTypeIdentifier(pType)
        {}

        void Accept(PrintVisitor::Ptr pVisitor)
        {
            std::cout << "Simple type identifier expression Visited" << std::endl;
            m_pTypeIdentifier->Accept(pVisitor);
        }

    private:
        Identifier::Ptr m_pTypeIdentifier;
    };


    class FieldInvocationExpression: public Expression
    {
    public:
        explicit FieldInvocationExpression(const FieldInvocation::Ptr& pType) noexcept
            : m_pFieldInvocation(pType)
        {}

        void Accept(PrintVisitor::Ptr pVisitor)
        {
            std::cout << "Field invocation expression Visited" << std::endl;
            m_pFieldInvocation->Accept(pVisitor);
        }

    private:
        FieldInvocation::Ptr m_pFieldInvocation;
    };


    class MethodInvocationExpression: public Expression
    {
    public:
        explicit MethodInvocationExpression(const MethodInvocation::Ptr& pInvoc) noexcept
            : m_pMethodInvocation(pInvoc)
        {}

        void Accept(PrintVisitor::Ptr pVisitor)
        {
            std::cout << "Method invocation expression Visited" << std::endl;
            m_pMethodInvocation->Accept(pVisitor);
        }

    private:
        MethodInvocation::Ptr m_pMethodInvocation;
    };


    class SimpleBooleanExpression: public BooleanExpression {
    public:
        explicit SimpleBooleanExpression(bool bValue) noexcept
        : m_bValue(bValue)
        {}

        bool Eval() const noexcept override
        {
            return m_bValue;
        }

        void Accept(PrintVisitor::Ptr pVisitor)
        {
            std::cout << "Simple Boolean expression: '" << m_bValue << "' Visited" << std::endl;
        }

    private:
        bool m_bValue;
    };


    class ComplexBooleanExpression: public BooleanExpression {
    public:
        explicit ComplexBooleanExpression(const Expression::Ptr& pExpression1, std::string action,
                                          const Expression::Ptr& pExpression2) noexcept
            : m_pExpression1(pExpression1)
            , m_pExpression2(pExpression2)
            , m_action(action)
        {}

        [[nodiscard]] bool Eval() const noexcept override
        {
            return false; // TODO : implement;
        }

        void Accept(PrintVisitor::Ptr pVisitor)
        {
            std::cout << "Complex Boolean expression: '" << m_action << "' Visited" << std::endl;
            m_pExpression1->Accept(pVisitor);
            m_pExpression2->Accept(pVisitor);
        }

    private:
        std::string m_action;
        Expression::Ptr m_pExpression1;
        Expression::Ptr m_pExpression2;

    };


class InverseBooleanExpression: public BooleanExpression {
    public:
        explicit InverseBooleanExpression(const Expression::Ptr& pExpr)
            : m_pExpression(std::dynamic_pointer_cast<BooleanExpression>(pExpr))
        {}

        bool Eval() const noexcept override
        {
            return !m_pExpression->Eval();
        }

    void Accept(PrintVisitor::Ptr pVisitor)
    {
        std::cout << "InverseBooleanExpression Boolean expression with result: '" << m_pExpression->Eval() << "' Visited" << std::endl;
        m_pExpression->Accept(pVisitor);
    }

private:
        BooleanExpression::Ptr m_pExpression;
    };
}

ArythmExpressionImpl::ArythmExpressionImpl(const Expression::Ptr& pN1, const Expression::Ptr& pN2, char action)
    : m_pFirst(pN1)
    , m_pSecond(pN2)
{
    switch(action)
    {
        case '+':
            m_fnAction = [](const ArythmExpressionImpl::Ptr& pE1, const ArythmExpressionImpl::Ptr& pE2) -> int
            { return pE1->Eval() + pE2->Eval(); };
            break;
        case '-':
            m_fnAction = [](const ArythmExpressionImpl::Ptr& pE1, const ArythmExpressionImpl::Ptr& pE2) -> int
            { return pE1->Eval() - pE2->Eval(); };
            break;
        case '*':
            m_fnAction = [](const ArythmExpressionImpl::Ptr& pE1, const ArythmExpressionImpl::Ptr& pE2) -> int
            { return pE1->Eval() * pE2->Eval(); };
            break;
        case '/':
            m_fnAction = [](const ArythmExpressionImpl::Ptr& pE1, const ArythmExpressionImpl::Ptr& pE2) -> int
            { return pE1->Eval() / pE2->Eval(); };
            break;
        default:
            throw std::runtime_error("Unsupported arythmetic operator!");
    }
}


int ArythmExpressionImpl::Eval() const noexcept {
    return 0;
}


IdentExpression::IdentExpression(const std::shared_ptr<Identifier>& pIdent) noexcept
    : m_pIdent(pIdent)
{}



NumberExpression::NumberExpression(int value) noexcept {
    m_nValue = value;
}


int NumberExpression::Eval() const noexcept {
    return m_nValue;
}


Expression::Ptr Expression::CreateLengthExpression(const Expression::Ptr& pExpression) noexcept
{
    return std::make_shared<LengthExpression>(pExpression);
}

Expression::Ptr Expression::CreateStackVarCreationExpression(const std::shared_ptr<SimpleType> pType,
                                                             const Expression::Ptr& pExpr) noexcept
{
    return std::make_shared<StackVarCreationExpression>(pType, pExpr);
}

Expression::Ptr Expression::CreateHeapVarCreationExpression(const std::shared_ptr<Identifier>& pIdent) noexcept
{
    return std::make_shared<HeapVarCreationExpression>(pIdent);
}


Expression::Ptr Expression::CreateMethodInvocationExpression(const std::shared_ptr<MethodInvocation>& pInvoc) noexcept
{
    return std::make_shared<MethodInvocationExpression>(pInvoc);
}

Expression::Ptr Expression::CreateFieldInvocationExpression(const std::shared_ptr<FieldInvocation>& pInvoc) noexcept
{
    return std::make_shared<FieldInvocationExpression>(pInvoc);
}


ArythmExpression::Ptr ArythmExpression::CreateAddExpression(const Expression::Ptr& pE1, const Expression::Ptr& pE2)
{
    return std::make_shared<ArythmExpressionImpl>(pE1 ,pE2, '+');
}


ArythmExpression::Ptr ArythmExpression::CreateSubstractExpression(const Expression::Ptr& pE1, const Expression::Ptr& pE2)
{
    return std::make_shared<ArythmExpressionImpl>(pE1 ,pE2, '-');
}


ArythmExpression::Ptr ArythmExpression::CreateMulExpression(const Expression::Ptr& pE1, const Expression::Ptr& pE2)
{
    return std::make_shared<ArythmExpressionImpl>(pE1 ,pE2, '*');
}


ArythmExpression::Ptr ArythmExpression::CreateDivExpression(const Expression::Ptr& pE1, const Expression::Ptr& pE2)
{
    return std::make_shared<ArythmExpressionImpl>(pE1 ,pE2, '/');
}


ArythmExpression::Ptr ArythmExpression::CreateNumberExpression(int nValue) noexcept
{
    return std::make_shared<NumberExpression>(nValue);
}


Expression::Ptr Expression::CreateIdentExpression(const std::shared_ptr<Identifier>& pIdent) noexcept
{
    return std::make_shared<IdentExpression>(pIdent);
}


BooleanExpression::Ptr BooleanExpression::CreateInverseExpression(const Expression::Ptr& pExpression)
{
    return std::make_shared<InverseBooleanExpression>(pExpression);
}


BooleanExpression::Ptr BooleanExpression::CreateBoolExpression(bool bValue) noexcept
{
    return std::make_shared<SimpleBooleanExpression>(bValue);
}

BooleanExpression::Ptr BooleanExpression::CreateComparasmentExpression(const Expression::Ptr& pExpression1,
                                                                       std::string action,
                                                                       const Expression::Ptr& pExpression2)
{
    return std::make_shared<ComplexBooleanExpression>(pExpression1, action, pExpression2);
}

Expression::Ptr Expression::CreateThisExpression() noexcept
{
    return std::make_shared<ThisExpression>();
}

