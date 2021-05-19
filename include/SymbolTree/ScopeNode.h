#pragma once

#include "Scope.h"

#include <vector>

class ScopeNode : public std::enable_shared_from_this<ScopeNode>
{
 public:
	using Ptr = std::shared_ptr<ScopeNode>;
	static Ptr Create(const Ptr& pParentNode);
	static Ptr CreateBasicOuterScope();

	void AddChild(const Ptr& pChild);
	Ptr GetParent() const;

	Scope::Ptr Get() const;

	// Utility:
	bool Contains(const Symbol& symbol);

 private:
	ScopeNode(const Ptr& pParentNode);
	ScopeNode();

	std::shared_ptr<Scope> m_pScope;

	std::vector<Ptr> m_arrChildred;
	const Ptr m_pParentNode;
};
