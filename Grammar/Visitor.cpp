//
// Created by pekashy on 28.02.2021.
//

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
