#pragma once

#include "Object.h"

#include "MethodObject.h"


class ClassObject : public Object
{
 public:
	using Ptr = std::shared_ptr<ClassObject>;
	static Ptr Create(const std::string& className);

	ObjectType GetType() const override
	{
		return ObjectType::Class;
	}


	void AddMethod(const std::shared_ptr<MethodObject>& pMethod)
	{
		m_pMethods.push_back(pMethod);
	}


	void AddField(const std::shared_ptr<MethodObject>& pMethod)
	{
		m_pMethods.push_back(pMethod);
	}


 private:
	ClassObject(const std::string& className);

	std::string m_name;
	std::vector<std::shared_ptr<MethodObject>> m_pMethods;
	std::vector<std::shared_ptr<VariableObject>> m_pFields;
};
