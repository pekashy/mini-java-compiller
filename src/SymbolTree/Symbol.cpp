#include <SymbolTree/Symbol.h>

const std::string& Symbol::GetId() const
{
	return m_Id;
}

bool Symbol::operator==(const Symbol& other) const {
	return GetId() == other.GetId();
}

bool Symbol::operator!=(const Symbol& other) const {
	return GetId() != other.GetId();
}


Symbol::Symbol(const std::string& symbolId, const Object::Ptr& pCorrespondingObject, int symbolOffset)
: m_Id(symbolId), m_pObject(pCorrespondingObject), m_offset(symbolOffset)
{}


Symbol::Symbol(const Symbol& symbol)
: m_Id(symbol.m_Id), m_pObject(symbol.m_pObject), m_offset(symbol.m_offset)
{}

void Symbol::SetCorrObj(const Object::Ptr& pCorrespondingObject) const
{
	m_pObject = pCorrespondingObject;
}
