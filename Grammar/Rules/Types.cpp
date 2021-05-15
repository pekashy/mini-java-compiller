#include <iostream>
#include "Types.h"
#include "Identifier.h"


Type::Type(const Type::Ptr& pType)
    : m_pAssociatedType(pType)
{}


SimpleType::Ptr SimpleType::Create(Types m_eIdentKW)
{
    return std::shared_ptr<SimpleType>(new SimpleType(m_eIdentKW));
}


SimpleType::Ptr SimpleType::Create(const Identifier::Ptr& pIdentifier)
{
    return std::shared_ptr<SimpleType>(new SimpleType(pIdentifier));
}


SimpleType::SimpleType(Types eIdentKW)
    : m_eIdentKW(eIdentKW)
{}


SimpleType::SimpleType(const Identifier::Ptr& pIdentifier)
    : m_pIdentifier(pIdentifier)
{}


void SimpleType::Accept(PrintVisitor::Ptr visitor)
{
    std::cout << "SimpleType '" << static_cast<int>(m_eIdentKW) << "' Visited" << std::endl;
    if(m_pIdentifier)
    {
        m_pIdentifier->Accept(visitor);
    }
}


ArrayType::Ptr ArrayType::Create(const SimpleType::Ptr& pType)
{
    return std::shared_ptr<ArrayType>(new ArrayType(pType));
}


ArrayType::ArrayType(const SimpleType::Ptr& pType)
    : Type(pType)
{}


void ArrayType::Accept(PrintVisitor::Ptr visitor)
{
    std::cout << "ArrayType Visited" << std::endl;
    if(m_pAssociatedType)
    {
        m_pAssociatedType->Accept(visitor);
    }
}
