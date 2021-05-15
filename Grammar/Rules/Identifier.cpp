#include "Identifier.h"

#include <iostream>

Identifier::Identifier(const std::string &rName)
    : m_rName(rName)
{}

Identifier::Ptr Identifier::Create(const std::string &rName)
{
    return std::shared_ptr<Identifier>(new Identifier(rName));
}


void Identifier::Accept(PrintVisitor::Ptr visitor)
{
    std::cout << "Identifier '" << m_rName << "' Visited" << std::endl;
}
