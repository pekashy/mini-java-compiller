#include "gtest/gtest.h"

#include <SymbolTree/ScopeTree.h>
#include <Objects/ClassObject.h>

TEST(SymbolTree, ClassCreationTest)
{
	auto classObject = ClassObject::Create("ClassObjectName");
}

TEST(SymbolTree, ScopeTreeCreationTest)
{
	ScopeTree tree;
	auto root = tree.GetRoot();
}