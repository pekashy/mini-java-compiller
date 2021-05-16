#pragma once

#include "../GrammarNode.h"
#include <string>

class Identifier : public GrammarNode
{
 public:
	using Ptr = std::shared_ptr<Identifier>;
	static Ptr Create(const std::string& rName);
	void Accept(const std::shared_ptr<PrintVisitor>& pVisitor) override;
	void Accept(const std::shared_ptr<InterpreterVisitor>& pVisitor) override;
 private:
	explicit Identifier(const std::string& rName);
	const std::string m_rName;
};
