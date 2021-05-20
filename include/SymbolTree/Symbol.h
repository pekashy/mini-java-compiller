#pragma once
#include <Objects/Object.h>

#include <string>

class Symbol
{
 public:
	Symbol(const std::string& symbolId, const Object::Ptr& pCorrespondingObject, int symbolOffset);
	[[nodiscard]] const std::string& GetId() const;

	bool operator==(const Symbol& other) const;
	bool operator!=(const Symbol& other) const;
	Symbol(const Symbol& other);
	void SetCorrObj(const Object::Ptr& pCorrespondingObject) const; // need a const-mutable pair to escape constness in call chain
 private:
	const std::string m_Id;
	mutable Object::Ptr m_pObject; // Can by Null!
	const int m_offset;
};

namespace std {
	template<>
	struct hash<Symbol>
	{
		std::size_t operator()(const Symbol& symbol) const {
			return hash<string>()(symbol.GetId());
		}
	};

}
