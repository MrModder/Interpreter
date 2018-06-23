#include <gtest/gtest.h>
#include <programGraph/Function.h>

TEST(TestFunction, createEmptyFunction)
{
	Function function;
	EXPECT_EQ(function.inputs().size(), 0);
	EXPECT_EQ(function.outputs().size(), 0);
}

TEST(TestFunction, createFunctionWithIO)
{
	std::vector<Datatype> in = { Datatype::DOUBLE };
	std::vector<Datatype> out = { Datatype::DOUBLE,  Datatype::DOUBLE };
	Function function(in, out);
	EXPECT_EQ(function.inputs(), in);
	EXPECT_EQ(function.outputs(), out);
}