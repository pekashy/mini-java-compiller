#pragma once

#include <memory>

class Scope;

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

	virtual std::shared_ptr<Scope> GetCorrespondingScope()
	{
		return m_pCorrespondingScope;
	}

	virtual void SetCorrespondingScope(const std::shared_ptr<Scope>& pScope)
	{
		m_pCorrespondingScope = pScope;
	}


	static inline bool IsCallable(ObjectType passedType)
	{
		return passedType == ObjectType::Method;
	}
 private:
	std::shared_ptr<Scope> m_pCorrespondingScope;
};