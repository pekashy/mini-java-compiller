#include <SymbolTree/Scope.h>
#include <SymbolTree/ScopeNode.h>
#include <stdexcept>

std::shared_ptr<Scope> Scope::Create(const std::shared_ptr<ScopeNode>& pCorrespondingScopeNode)
{
	return std::shared_ptr<Scope>(new Scope(pCorrespondingScopeNode));
}

void Scope::DeclareSymbol(const std::string& name)
{
	Symbol symbol(name, nullptr, m_symbols.size());
	if(FindScopeWhichContains(symbol) != nullptr)
	{
		throw std::runtime_error("symbol redeclaration attempt!");
	}

	m_symbols.insert(symbol);
}

void Scope::DeclareSymbol(const std::string& name, const Object::Ptr& value)
{
	Symbol symbol(name, value, m_symbols.size());
	auto pContainingScope = FindScopeWhichContains(symbol);
	if(pContainingScope == nullptr)
	{
		m_symbols.insert(symbol);
		return;
	}

	auto symbolIt = pContainingScope->m_symbols.find(symbol);
	symbolIt->SetCorrObj(value);
}


std::shared_ptr<const Scope> Scope::FindScopeWhichContains(const Symbol& symbol) const
{
	bool bThisContains = m_symbols.find(symbol) != std::end(m_symbols);
	if(bThisContains)
	{
		return shared_from_this();
	}

	// Search up on scope tree
	return m_pCorrespondingScopeNode->FindScopeWhichContains(symbol);
}


Scope::Scope(const std::shared_ptr<ScopeNode>& pCorrespondingScopeNode)
: m_pCorrespondingScopeNode(pCorrespondingScopeNode)
{}
