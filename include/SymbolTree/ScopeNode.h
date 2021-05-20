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
	std::shared_ptr<const Scope> FindScopeWhichContains(const Symbol& symbol) const;

 private:
	ScopeNode(const Ptr& pParentNode);
	ScopeNode();
	void Init();

	std::shared_ptr<Scope> m_pScope;

	std::vector<Ptr> m_arrChildred;
	const Ptr m_pParentNode;
};
