#pragma once

#include "Object.h"
#include <string>

class ClassObject;

class VariableObject : public Object
{
 public:
	using Ptr = std::shared_ptr<VariableObject>;
	static Ptr Create(const std::string& type, const std::string& name);
	[[nodiscard]] ObjectType GetType() const override;
	void SetCorrespondingClass(const std::shared_ptr<ClassObject>& pClass);
 private:
	VariableObject(const std::string& type, const std::string& name);
	std::string m_type;
	std::string m_name;
	std::shared_ptr<ClassObject> m_pCorrespondingClass;
};
