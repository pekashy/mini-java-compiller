#pragma once

#include "Symbol.h"

#include <Objects/Object.h>
#include <unordered_set>

class ScopeNode;

class Scope : public std::enable_shared_from_this<Scope>
{
 public:
	using Ptr = std::shared_ptr<Scope>;
	static Ptr Create(const std::shared_ptr<ScopeNode>& pCorrespondingScopeNode);

	void DeclareSymbol(const Symbol& symbol);
	bool Contains(const Symbol& symbol) const;
 private:
	Scope(const std::shared_ptr<ScopeNode>& pCorrespondingScopeNode);
	std::shared_ptr<ScopeNode> m_pCorrespondingScopeNode;
	std::unordered_set<Symbol> m_symbols;
};