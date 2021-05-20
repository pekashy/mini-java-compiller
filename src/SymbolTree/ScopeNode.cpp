#include <SymbolTree/ScopeNode.h>

#include <SymbolTree/Scope.h>


std::shared_ptr<ScopeNode> ScopeNode::Create(const std::shared_ptr<ScopeNode>& pParentNode)
{
	return std::shared_ptr<ScopeNode>(new ScopeNode(pParentNode));
}

std::shared_ptr<ScopeNode> ScopeNode::CreateBasicOuterScope()
{
	return std::shared_ptr<ScopeNode>();
}

void ScopeNode::AddChild(const std::shared_ptr<ScopeNode>& pChild)
{
	m_arrChildred.push_back(pChild);
}

std::shared_ptr<ScopeNode> ScopeNode::GetParent() const
{
	return m_pParentNode;
}

std::shared_ptr<Scope> ScopeNode::Get() const
{
	return m_pScope;
}

ScopeNode::ScopeNode(const std::shared_ptr<ScopeNode>& pParentNode)
	: m_pParentNode(pParentNode)
{
	m_pParentNode->AddChild(shared_from_this());
	m_pScope = Scope::Create(shared_from_this());
}

ScopeNode::ScopeNode()
	: m_pParentNode(nullptr)
{
	m_pScope = Scope::Create(shared_from_this());
}

std::shared_ptr<const Scope> ScopeNode::FindScopeWhichContains(const Symbol& symbol) const
{
	if(m_pParentNode == nullptr)
	{
		return nullptr;
	}

	return m_pParentNode->Get()->FindScopeWhichContains(symbol);
}
