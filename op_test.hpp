#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(7.5);
    EXPECT_EQ(test->evaluate(), 7.5);
}

TEST(OpTest, OpEvaluateNegative)
{
	Op* test = new Op(-3);
	EXPECT_EQ(test->evaluate(), -3);
}

TEST(OpTest, OpStringifyNonZero)
{
	Op* test = new Op(3);
	EXPECT_EQ(test->stringify(),"3.000000");
}

TEST(OpTest, OpEvaluateZeros)
{
	Op* test = new Op(0);
	EXPECT_EQ(test->evaluate(), 0);
}

TEST(OpTest, OpStringifyZeros)
{
	Op* test = new Op(0);
	EXPECT_EQ("0.000000",test->stringify());
}

TEST(OpTest, OpStringifyNegative)
{
        Op* test = new Op(-3);
        EXPECT_EQ("-3.000000",test->stringify());
}



#endif //__OP_TEST_HPP__
