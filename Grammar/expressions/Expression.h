#pragma once

#include "../GrammarNode.h"
#include <memory>

class Expression : public GrammarNode{
public:
    using Ptr = std::shared_ptr<Expression>;
    [[nodiscard]] virtual int Eval() const noexcept = 0;
};