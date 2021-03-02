//
// Created by pekashy on 01.03.2021.
//

#include "Identifier.h"

Identifier::Identifier(const std::string &rName)
    : m_rName(rName)
{}

Identifier::Ptr Identifier::Create(const std::string &rName)
{
    return std::shared_ptr<Identifier>(new Identifier(rName));
}
