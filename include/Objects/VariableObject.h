#pragma once

#include "Object.h"

class VariableObject : public Object
{
 public:
	using Ptr = std::shared_ptr<VariableObject>;
	static Ptr Create();

	ObjectType GetType() const override
	{
		return ObjectType::Variable;
	}

 private:
	VariableObject();
};
