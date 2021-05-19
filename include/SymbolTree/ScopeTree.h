#pragma once

#include "ScopeNode.h"

class ScopeTree
{
 public:
	ScopeTree();
	[[nodiscard]] ScopeNode::Ptr GetRoot() const;

 private:
	ScopeNode::Ptr m_pRoot;
};