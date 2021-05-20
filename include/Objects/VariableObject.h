#pragma once

#include "Object.h"
#include <string>

class ClassObject;

class VariableObject : public Object
{
 public:
	using Ptr = std::shared_ptr<VariableObject>;
	static Ptr Create(const std::string& type, const std::string& name)
	{
		return Ptr(new VariableObject(type, name));
	}

	ObjectType GetType() const override
	{
		return ObjectType::Variable;
	}

	void SetCorrespondingClass(const std::shared_ptr<ClassObject>& pClass)
	{
		m_pCorrespondingClass = pClass;
	}

 private:
	VariableObject(const std::string& type, const std::string& name)
	: m_type(type), m_name(name)
	{}

	std::string m_type;
	std::string m_name;
	std::shared_ptr<ClassObject> m_pCorrespondingClass;
};
