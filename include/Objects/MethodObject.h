#pragma once

#include "VariableObject.h"
#include <vector>

class VariableObject;

class MethodObject : public Object
{
 public:
	using Ptr = std::shared_ptr<MethodObject>;

	[[nodiscard]] ObjectType GetType() const override;
	static Ptr Create(const std::string& retValue, const std::string& methodName);
	void AddArg(const std::shared_ptr<VariableObject>& pArg);
 private:
	MethodObject(const std::string& retValue, const std::string& methodName);

	std::string m_retValue;
	std::string m_methodName;
	std::vector<std::shared_ptr<VariableObject>> m_argList;
};
