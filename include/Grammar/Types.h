#pragma once

#include "GrammarNode.h"

class Identifier;

enum class Types
{
	None, Int, Boolean, Void
};

class Type : public GrammarNode
{
 public:
	using Ptr = std::shared_ptr<Type>;
	virtual ~Type() = default;
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
	void Accept(const std::shared_ptr<PrintVisitor>& pVisitor) override;
	void Accept(const std::shared_ptr<InterpreterVisitor>& pVisitor) override;
	void Accept(const std::shared_ptr<SymbolTableVisitor> &pVisitor) override;
 private:
	explicit SimpleType(Types m_eIdentKW);
	explicit SimpleType(const std::shared_ptr<Identifier>& pIdentifier);

	template<class V> void GenericAccept(const V& pVisitor);

	const Types m_eIdentKW = Types::None;
	const std::shared_ptr<Identifier> m_pIdentifier = nullptr;
};

class ArrayType : public Type
{
 public:
	using Ptr = std::shared_ptr<ArrayType>;
	static Ptr Create(const SimpleType::Ptr& m_pType);
	void Accept(const std::shared_ptr<PrintVisitor>& pVisitor) override;
	void Accept(const std::shared_ptr<InterpreterVisitor>& pVisitor) override;
	void Accept(const std::shared_ptr<SymbolTableVisitor> &pVisitor) override;
 private:
	explicit ArrayType(const SimpleType::Ptr& m_pType);

	template<class V> void GenericAccept(const V& pVisitor);
};




