#pragma once

#include "../GrammarNode.h"

class Identifier;

class Expression;

class FieldInvocation : public GrammarNode
{
public:
    using Ptr = std::shared_ptr<FieldInvocation>;
    virtual ~FieldInvocation() = default;
    static Ptr Create(const std::shared_ptr<Identifier>& pIdent);
    static Ptr Create(const std::shared_ptr<Identifier>& pIdent, const std::shared_ptr<Expression>& pExpr);
protected:
    FieldInvocation() = default;
};


// TODO: Implement
class MethodInvocation : public GrammarNode
{
public:
    using Ptr = std::shared_ptr<MethodInvocation>;
    virtual ~MethodInvocation() = default;
    //static Ptr Create(const std::shared_ptr<Expression>& pExpr1, const std::shared_ptr<Identifier>& pIdent);
protected:
    MethodInvocation() = default;
};
