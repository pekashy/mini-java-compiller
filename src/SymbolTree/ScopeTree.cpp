#include <SymbolTree/ScopeTree.h>

ScopeTree::ScopeTree()
{
	m_pRoot = ScopeNode::CreateBasicOuterScope();
}

ScopeNode::Ptr ScopeTree::GetRoot() const
{
	return m_pRoot;
}
