#pragma once

#include "VariableObject.h"
#include <vector>

class VariableObject;

class MethodObject : public Object
{
 public:
	using Ptr = std::shared_ptr<MethodObject>;

	ObjectType GetType() const override
	{
		return ObjectType::Method;
	}

	static Ptr Create(const std::string& retValue, const std::string& methodName)
	{
		return Ptr(new MethodObject(retValue, methodName));
	}

	void AddArg(const std::shared_ptr<VariableObject>& pArg)
	{
		m_argList.push_back(pArg);
	}

 private:
	MethodObject(const std::string& retValue, const std::string& methodName)
	: m_retValue(retValue), m_methodName(methodName)
	{}

	std::string m_retValue;
	std::string m_methodName;
	std::vector<std::shared_ptr<VariableObject>> m_argList;
};
