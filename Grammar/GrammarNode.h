#pragma once

#include "Visitor.h"
#include <memory>

class GrammarNode {
public:
    using Ptr = std::shared_ptr<GrammarNode>;
    virtual void Accept(PrintVisitor::Ptr visitor) = 0;

    virtual ~GrammarNode() = default;
};


template <class T>
class Chain : public GrammarNode{
public:
    using Ptr = std::shared_ptr<Chain<T>>;
    static Ptr Create(Ptr pNext, const std::shared_ptr<T> pContent)
    {
        return Ptr(new Chain<T>(pContent, pNext));
    }

    static Ptr Create()
    {
        return Ptr(new Chain<T>());
    }

    void Accept(PrintVisitor::Ptr visitor) override
    {
        if(!m_bEmpty)
        {
            m_pContent->Accept(visitor);
            m_pNext->Accept(visitor);
        }
    }

private:
    Chain(const std::shared_ptr<T> pContent, Ptr pNext)
    : m_pContent(pContent), m_pNext(pNext)
    , m_bEmpty(false)
    {}

    Chain()
        : m_bEmpty(true)
    {}

    std::shared_ptr<T> m_pContent;
    Ptr m_pNext;

    const bool m_bEmpty;
};
