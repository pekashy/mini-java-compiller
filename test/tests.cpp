#include "gtest/gtest.h"

#include <Objects/ClassObject.h>
#include <CompilerDriver.h>
#include <Visitors/SymbolTableVisitor.h>


TEST(Parsing, FullParsingTest)
{
	auto pDriver = CompilerDriver::Create(0, 0, 0);
	ASSERT_EQ(pDriver->Parse("../code.in"), 0);
}

TEST(Visitors, PrintVisitorTest)
{
	auto pDriver = CompilerDriver::Create(0, 0, 0);
	ASSERT_EQ(pDriver->Parse("../code.in"), 0);
	auto pVisitor = PrintVisitor::Create();
	pDriver->StartVisitor(pVisitor);
}


TEST(Visitors, InterpreterVisitorTest)
{
	std::string result = "int main() {\n"
						 "int num_aux;\n"
						 "assert(0);\n"
						 "num_aux = 1;\n"
						 "if (1)\n"
						 "\tnum_aux = 2;\n"
						 "while (1)\n"
						 "\tstd::cout << num_aux << std::endl;\n"
						 "}";
	auto pDriver = CompilerDriver::Create(0, 0, 0);
	ASSERT_EQ(pDriver->Parse("../interpreter-code.in"), 0);
	auto iVisitor = InterpreterVisitor::Create();
	pDriver->StartVisitor(iVisitor);
	ASSERT_EQ(iVisitor->GetInterpreterResult(), result);
}

TEST(Visitors, SymbolTableVisitorTest)
{
	auto pDriver = CompilerDriver::Create(0, 0, 0);
	ASSERT_EQ(pDriver->Parse("../code.in"), 0);
	auto sVisitor = SymbolTableVisitor::Create();
	pDriver->StartVisitor(sVisitor);
}
