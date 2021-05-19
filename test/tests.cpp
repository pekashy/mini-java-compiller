#include "gtest/gtest.h"

#include <SymbolTree/ScopeTree.h>

TEST(TSuite, FirstTest)
{
	ScopeTree tree;
	auto root = tree.GetRoot();

	printf("Hello World!");
}