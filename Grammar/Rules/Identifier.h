#pragma once

#include "../GrammarNode.h"
#include <string>

class Identifier : public GrammarNode
{
public:
    explicit Identifier(const std::string& rName);
    using Ptr = std::shared_ptr<Identifier>;
private:
    const std::string m_rName;
};
