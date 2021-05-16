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



void SimpleType::Accept(const std::shared_ptr<PrintVisitor> &pVisitor)
{
    std::cout << "SimpleType '" << static_cast<int>(m_eIdentKW) << "' Visited" << std::endl;
    GenericAccept<PrintVisitor::Ptr>(pVisitor);
}

void SimpleType::Accept(const std::shared_ptr<InterpreterVisitor> &pVisitor)
{
    GenericAccept<InterpreterVisitor::Ptr>(pVisitor);
}

template<class V>
void SimpleType::GenericAccept(const V& pVisitor)
{
    if(m_pIdentifier)
    {
        m_pIdentifier->Accept(pVisitor);
    }
}


ArrayType::Ptr ArrayType::Create(const SimpleType::Ptr& pType)
{
    return std::shared_ptr<ArrayType>(new ArrayType(pType));
}


ArrayType::ArrayType(const SimpleType::Ptr& pType)
    : Type(pType)
{}


void ArrayType::Accept(const std::shared_ptr<PrintVisitor> &pVisitor)
{
    std::cout << "ArrayType Visited" << std::endl;
    GenericAccept<PrintVisitor::Ptr>(pVisitor);
}

void ArrayType::Accept(const std::shared_ptr<InterpreterVisitor> &pVisitor)
{
    GenericAccept<InterpreterVisitor::Ptr>(pVisitor);
}

template<class V>
void ArrayType::GenericAccept(const V& pVisitor)
{
    if(m_pAssociatedType)
    {
        m_pAssociatedType->Accept(pVisitor);
    }
}
