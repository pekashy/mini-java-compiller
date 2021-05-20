#include <Objects/ClassObject.h>
ClassObject::Ptr ClassObject::Create(const std::string& className)
{
	return ClassObject::Ptr(new ClassObject(className));
}


ClassObject::ClassObject(const std::string& className)
: m_name(className)
{}

[[nodiscard]] ObjectType ClassObject::GetType() const
{
	return ObjectType::Class;
}


void ClassObject::AddMethod(const std::shared_ptr<MethodObject>& pMethod)
{
	m_pMethods.push_back(pMethod);
}


void ClassObject::AddField(const std::shared_ptr<MethodObject>& pMethod)
{
	m_pMethods.push_back(pMethod);
}

[[nodiscard]] std::string ClassObject::GetName() const
{
	return m_name;
}