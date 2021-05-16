#pragma once

#include "../GrammarNode.h"

#include <string>
#include <memory>

class ArythmExpression;
class Expression;

class Assignment : public GrammarNode, std::enable_shared_from_this<Assignment> {
 public:
    using Ptr = std::shared_ptr<Assignment>;
    static Ptr Create(const std::string& rVariable, const std::shared_ptr<Expression>& pExpr);
    void Accept(const std::shared_ptr<PrintVisitor> &pVisitor) override;
    void
    Accept(const std::shared_ptr<InterpreterVisitor> &pVisitor) override;
private:
    Assignment(const std::string& rVariable, const std::shared_ptr<ArythmExpression>& pExpr);

    template<class V>
    void GenericAccept(const V& pVisitor);

    std::string m_rVar;
    std::shared_ptr<ArythmExpression> m_pExpression;
};