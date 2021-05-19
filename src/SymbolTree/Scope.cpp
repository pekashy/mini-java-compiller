#include <SymbolTree/Scope.h>
#include <SymbolTree/ScopeNode.h>
#include <stdexcept>

std::shared_ptr<Scope> Scope::Create(const std::shared_ptr<ScopeNode>& pCorrespondingScopeNode)
{
	return std::shared_ptr<Scope>(new Scope(pCorrespondingScopeNode));
}

void Scope::DeclareSymbol(const Symbol& symbol)
{
	if(Contains(symbol))
	{
		throw std::runtime_error("variable redeclaration attempt!");
	}

	m_symbols.insert(symbol);
}

bool Scope::Contains(const Symbol& symbol) const
{
	bool bThisContains = m_symbols.find(symbol) != std::end(m_symbols);
	if(bThisContains)
	{
		return true;
	}

	// Search up on scope tree
	return m_pCorrespondingScopeNode->Contains(symbol);
}

Scope::Scope(const std::shared_ptr<ScopeNode>& pCorrespondingScopeNode)
: m_pCorrespondingScopeNode(pCorrespondingScopeNode)
{}
