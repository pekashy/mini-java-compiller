#pragma once

#include "Object.h"

#include <vector>
#include <string>

class Scope;

class ClassObject : public Object
{
 public:
	using Ptr = std::shared_ptr<ClassObject>;
	static Ptr Create(const std::string& className);

	ObjectType GetType() const override
	{
		return ObjectType::Class;
	}

 private:
	ClassObject(const std::string& className);

	std::string m_name;
};
