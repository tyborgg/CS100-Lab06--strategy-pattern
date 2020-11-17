#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"
#include "pow.hpp"
#include "op.hpp"
#include "base.hpp"
#include "sub.hpp"
#include "MultMock.hpp"
#include "AddMock.hpp"
#include "DivMock.hpp"
#include "RandMock.hpp"

TEST(PowTest, PowEvaluateNonZero)
{
        Base* Op1 = new Op(5);
        Base* Op2 = new Op(3);
        Base* test = new Pow(Op1,Op2);
        EXPECT_EQ(125, test->evaluate());
}

TEST(PowTest, PowEvaluateNegNumbers)
{
        Base* Op1 = new Op(-5);
        Base* Op2 = new Op(-3);
        Base* test = new Pow(Op1,Op2);
        EXPECT_EQ(-.008, test->evaluate());
}

TEST(PowTest, PowStringifyNonZero)
{
        Base* Op1 = new Op(5);
        Base* Op2 = new Op(3);
        Base* test = new Pow(Op1,Op2);
        EXPECT_EQ("5.000000 ** 3.000000", test->stringify());
}

TEST(PowTest, PowEvaluateSubAndOp)
{
        Base* Op1 = new Op(5);
	Base* Op2 = new Op(3);
        Base* Sub1 = new Sub(Op1,Op2); //Sub1 == 2
        Base* test = new Pow(Sub1,Op2);
        EXPECT_EQ(8, test->evaluate());
}

TEST(PowTest, PowEvaluateOnlyZeros)
{
	Base* Op1 = new Op(0);
	Base* Op2 = new Op(0);
	Base* test = new Pow(Op1,Op2);
	EXPECT_EQ(1, test->evaluate());
}

TEST(PowTest, PowStringifySubAndOp)
{
	Base* Op1 = new Op(1);
	Base* Op2 = new Op(2);
	Base* Sub1 = new Sub(Op1,Op2);
	Base* test = new Pow(Sub1,Op2);
	EXPECT_EQ("1.000000 - 2.000000 ** 2.000000",test->stringify());
}

TEST(PowTest, PowStringifyMultandPow)
{
        Base* Op1 = new Op(1);
        Base* Mult2 = new MultMock();
        Base* test = new Pow(Mult2,Op1);
        EXPECT_EQ("3.000000 * 4.000000 ** 1.000000",test->stringify());
}


TEST(PowTest, PowStringifyAddandPow)
{
        Base* Op1 = new Op(1);
        Base* Add2 = new AddMock();
        Base* test = new Pow(Add2,Op1);
        EXPECT_EQ("6.000000 + 3.000000 ** 1.000000",test->stringify());
}

TEST(PowTest, PowStringifyDivandPow)
{
        Base* Op1 = new Op(1);
        Base* Div2 = new DivMock();
        Base* test = new Pow(Div2,Op1);
        EXPECT_EQ("8.000000 / 4.000000 ** 1.000000",test->stringify());
}

TEST(PowTest, PowStringifyRandandPow)
{
        Base* Op1 = new Op(1);
        Base* Rand2 = new RandMock();
        Base* test = new Pow(Rand2,Op1);
        EXPECT_EQ("11.000000 ** 1.000000",test->stringify());
}

TEST(PowTest, PowEvaluateRandAndOp)
{
        Base* Rand1 = new RandMock();
        Base* Op2 = new Op(2);
        Base* test = new Pow(Rand1,Op2);
        EXPECT_EQ(121,test->evaluate());
}

TEST(PowTest, PowEvaluateMultAndOp)
{
        Base* Mult1 = new MultMock();
        Base* Op2 = new Op(2);
        Base* test = new Pow(Mult1,Op2);
        EXPECT_EQ(144,test->evaluate());
}

TEST(PowTest, PowEvaluateAddAndOp)
{
        Base* Add1 = new AddMock();
        Base* Op2 = new Op(3);
        Base* test = new Pow(Add1,Op2);
        EXPECT_EQ(729,test->evaluate());
}

TEST(PowTest, PowEvaluateDivAndOp)
{
        Base* Div1 = new DivMock();
        Base* Op2 = new Op(3);
        Base* test = new Pow(Div1,Op2);
        EXPECT_EQ(8,test->evaluate());
}

#endif //__POW_TEST_HPP__
