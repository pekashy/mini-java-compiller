#pragma once

#include "Visitor.h"
#include <memory>

class GrammarNode {
public:
    using Ptr = std::shared_ptr<GrammarNode>;
    // virtual void Visit(Visitor* visitor) = 0;

    virtual ~GrammarNode() = default;
};


template <class T>
class Chain {
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
