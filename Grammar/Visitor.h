#pragma once

#include <memory>

class GrammarNode;

class Visitor {
public:
    using Ptr = std::shared_ptr<Visitor>;

    virtual ~Visitor() = default;
    virtual void Visit(std::shared_ptr<GrammarNode> pNode) = 0;
protected:
    Visitor() = default;
};


class PrintVisitor : public Visitor, public std::enable_shared_from_this<PrintVisitor> {
public:
    using Ptr = std::shared_ptr<PrintVisitor>;
    static PrintVisitor::Ptr Create();
    void Visit(std::shared_ptr<GrammarNode> pNode) override;
private:
    PrintVisitor() = default;
};


class InterpreterVisitor : public Visitor, public std::enable_shared_from_this<InterpreterVisitor> {
public:
    using Ptr = std::shared_ptr<InterpreterVisitor>;
    static InterpreterVisitor::Ptr Create();
    void Visit(std::shared_ptr<GrammarNode> pNode) override;
private:
    InterpreterVisitor() = default;
};
