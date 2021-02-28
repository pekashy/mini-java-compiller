#pragma once

#include "Visitor.h"
#include <memory>

class GrammarNode {
public:
    using Ptr = std::shared_ptr<GrammarNode>;
    // virtual void Visit(Visitor* visitor) = 0;

    virtual ~GrammarNode() = default;
};
