#pragma once

#include "../GrammarNode.h"

class Statement : public GrammarNode {
public:
    virtual ~Statement() = default;
};