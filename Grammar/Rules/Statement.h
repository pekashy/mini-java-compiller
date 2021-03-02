#pragma once

#include "../GrammarNode.h"

class Expression;
class Lvalue;
class MethodInvocation;
class VariableDeclaration;

class Statement : public GrammarNode
{
public:
    using Ptr = std::shared_ptr<Statement>;

    static Ptr CreateAssertion(const std::shared_ptr<Expression>& pExpression);
    // TODO: Implemet
    static Ptr CreateLocalVarDeclaration(const std::shared_ptr<VariableDeclaration>& pDeclaration);
    static Ptr CreateInnerStatement(const Ptr& pStatement);
    static Ptr CreateIf(const std::shared_ptr<Expression>& pExpression, const Ptr& pStatement);
    static Ptr CreateIfElse(const std::shared_ptr<Expression>& pExpression, const Ptr& pIfStatement, const Ptr& pElseStatement);
    static Ptr CreateWhile(const std::shared_ptr<Expression>& pExpression, const Ptr& pStatement);
    static Ptr CreatePrint(const std::shared_ptr<Expression>& pExpression);
    static Ptr CreateAssignment(const std::shared_ptr<Expression>& pExpression, const std::shared_ptr<Lvalue>& pLvalue);
    static Ptr CreateReturn(const std::shared_ptr<Expression>& pExpression);
    static Ptr CreateMethodInvoc(const std::shared_ptr<MethodInvocation>& pInvoc);
protected:
    Statement() = default;
};
