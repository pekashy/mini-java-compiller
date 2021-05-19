#pragma once

#include "Object.h"

class MethodObject : public Object
{
 public:
	using Ptr = std::shared_ptr<MethodObject>;
	static Ptr Create();

	ObjectType GetType() const override
	{
		return ObjectType::Method;
	}

	static Ptr Create(const std::string& methodName);

 private:
	MethodObject(const std::string& methodName);
};
