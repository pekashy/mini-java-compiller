#include "Types.h"
#include "Identifier.h"

Type::Ptr Type::Create(const Type::Ptr& pType)
{
    return std::shared_ptr<Type>(new Type(pType));
}


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


ArrayType::Ptr ArrayType::Create(const SimpleType::Ptr& pType)
{
    return std::shared_ptr<ArrayType>(new ArrayType(pType));
}


ArrayType::ArrayType(const SimpleType::Ptr& pType)
    : Type(pType)
{}
