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

bool ScopeNode::Contains(const Symbol& symbol)
{
	if(m_pParentNode == nullptr)
	{
		return false;
	}

	return m_pParentNode->Get()->Contains(symbol);
}
