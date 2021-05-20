#include <Objects/MethodObject.h>

[[nodiscard]] ObjectType MethodObject::GetType() const
{
	return ObjectType::Method;
}

MethodObject::Ptr MethodObject::Create(const std::string& retValue, const std::string& methodName)
{
	return Ptr(new MethodObject(retValue, methodName));
}

void MethodObject::AddArg(const std::shared_ptr<VariableObject>& pArg)
{
	m_argList.push_back(pArg);
}

MethodObject::MethodObject(const std::string& retValue, const std::string& methodName)
	: m_retValue(retValue), m_methodName(methodName)
{}
