#pragma once

#include <Visitors/Visitor.h>
#include <memory>

class GrammarNode
{
public:
    using Ptr = std::shared_ptr<GrammarNode>;
    virtual void
    Accept(const std::shared_ptr<PrintVisitor> &pVisitor) = 0;
    virtual void
    Accept(const std::shared_ptr<InterpreterVisitor> &pVisitor) = 0;

    virtual ~GrammarNode() = default;
};

template<class T>
class Chain : public GrammarNode
{
public:
    using Ptr = std::shared_ptr<Chain<T>>;
    static Ptr
    Create(Ptr pNext, const std::shared_ptr<T> pContent)
    {
        return Ptr(new Chain<T>(pContent, pNext));
    }

    static Ptr
    Create()
    {
        return Ptr(new Chain<T>());
    }

    void
    Accept(const PrintVisitor::Ptr &visitor) override
    {
        GenericAccept<PrintVisitor::Ptr>(visitor);
    }

    void
    Accept(const InterpreterVisitor::Ptr &visitor) override
    {
        GenericAccept<InterpreterVisitor::Ptr>(visitor);
    }

    template<class V>
    void
    GenericAccept(const V &pVisitor)
    {
        if (!m_bEmpty)
        {
            pVisitor->Visit(m_pContent);
            m_pNext->Accept(pVisitor);
        }
    }

private:
    Chain(const std::shared_ptr<T> pContent, Ptr pNext)
        : m_pContent(pContent), m_pNext(pNext), m_bEmpty(false) {}

    Chain()
        : m_bEmpty(true) {}

    std::shared_ptr<T> m_pContent;
    Ptr m_pNext;

    const bool m_bEmpty;
};
