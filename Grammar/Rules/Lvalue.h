#pragma once

#include "../GrammarNode.h"
#include "Identifier.h"
#include "Expression.h"

class FieldInvocation;

class Lvalue : public GrammarNode
{
public:
    using Ptr = std::shared_ptr<Lvalue>;
    static Ptr Create(const Identifier::Ptr& pIdent);
    static Ptr Create(const Identifier::Ptr& pIdent, const Expression::Ptr& pExpr);
    static Ptr Create(const std::shared_ptr<FieldInvocation>& pFieldInvoc);
protected:
    Lvalue() = default;
};

