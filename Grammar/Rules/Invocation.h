#pragma once

#include "../GrammarNode.h"
#include "Identifier.h"

class Expression;

class FieldInvocation : public GrammarNode
{
public:
    using Ptr = std::shared_ptr<FieldInvocation>;
    virtual ~FieldInvocation() = default;
    static Ptr Create(const Identifier::Ptr& pIdent);
    static Ptr Create(const Identifier::Ptr& pIdent, const std::shared_ptr<Expression>& pExpr);
protected:
    FieldInvocation() = default;
};


// TODO: Implement
class MethodInvocation : public GrammarNode
{
public:
    using Ptr = std::shared_ptr<MethodInvocation>;
    virtual ~MethodInvocation() = default;
    //static Ptr Create(const std::shared_ptr<Expression>& pExpr1, const Identifier::Ptr& pIdent);
protected:
    MethodInvocation() = default;
};
