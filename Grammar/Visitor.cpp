#include "Visitor.h"
#include "GrammarNode.h"


void PrintVisitor::Visit(GrammarNode::Ptr pNode)
{
    pNode->Accept(Ptr(this));
}

PrintVisitor::Ptr PrintVisitor::Create()
{
    return std::shared_ptr<PrintVisitor>(new PrintVisitor());
}

void InterpreterVisitor::Visit(GrammarNode::Ptr pNode)
{
    pNode->Accept(Ptr(this));
}

InterpreterVisitor::Ptr InterpreterVisitor::Create()
{
    return std::shared_ptr<InterpreterVisitor>(new InterpreterVisitor());
}
