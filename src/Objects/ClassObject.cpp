#include <Objects/ClassObject.h>
ClassObject::Ptr ClassObject::Create(const std::string& className)
{
	return ClassObject::Ptr(new ClassObject(className));
}


ClassObject::ClassObject(const std::string& className)
: m_name(className)
{}
