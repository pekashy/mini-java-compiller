#include <Objects/VariableObject.h>

VariableObject::Ptr VariableObject::Create(const std::string& type, const std::string& name)
{
	return VariableObject::Ptr(new VariableObject(type, name));
}

[[nodiscard]] ObjectType VariableObject::GetType() const
{
return ObjectType::Variable;
}

void VariableObject::SetCorrespondingClass(const std::shared_ptr<ClassObject>& pClass)
{
	m_pCorrespondingClass = pClass;
}

VariableObject::VariableObject(const std::string& type, const std::string& name)
	: m_type(type), m_name(name)
{}
