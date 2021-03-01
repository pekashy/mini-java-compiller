#pragma once

#include "../GrammarNode.h"

class Identifier;

enum class Types
{
    None,
    Int,
    Boolean,
    Void
};


class Type : public GrammarNode
{
public:
    using Ptr = std::shared_ptr<Type>;
    static Ptr Create(const Ptr& pType);
protected:
    explicit Type(const Ptr& pType);
    Type() = default;
    Ptr m_pAssociatedType;
};


class SimpleType : public Type
{
public:
    using Ptr = std::shared_ptr<SimpleType>;
    static Ptr Create(Types m_eIdentKW);
    static Ptr Create(const std::shared_ptr<Identifier>& pIdentifier);
private:
    explicit SimpleType(Types m_eIdentKW);
    explicit SimpleType(const std::shared_ptr<Identifier>& pIdentifier);
    const Types m_eIdentKW = Types::None;
    const std::shared_ptr<Identifier> m_pIdentifier = nullptr;
};


class ArrayType : public Type
{
public:
    using Ptr = std::shared_ptr<ArrayType>;
    static Ptr Create(const SimpleType::Ptr& m_pType);
private:
    explicit ArrayType(const SimpleType::Ptr& m_pType);
};




