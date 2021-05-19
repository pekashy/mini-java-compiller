#pragma once

#include <memory>

enum class ObjectType
{
	Class,
	Method,
	Variable
};


class Object {
 public:
	using Ptr = std::shared_ptr<Object>;

	virtual ~Object() = default;
	virtual ObjectType GetType() const = 0;

	static inline bool IsCallable(ObjectType passedType)
	{
		return passedType == ObjectType::Method;
	}
};