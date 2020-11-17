#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"

#include "add.hpp"
#include "seven_mock_op.hpp"
#include "zero_mock_op.hpp"
#include "neg_mock_op.hpp"
#include "neg_mock_pow.hpp"
#include "pos_mock_pow.hpp"
#include "zero_mock_pow.hpp"
#include "neg_mock_sub.hpp"
#include "pos_mock_sub.hpp"
#include "zero_mock_sub.hpp"



TEST(AddTest, BothZero) {
    Base* op1 = new ZeroOpMock();
    Base* op2 = new ZeroPowMock();
    Add* test = new Add(op1, op2);
    EXPECT_EQ(test->evaluate(), 0);
}
TEST(AddTest, BothZeroString) {
    Base* op1 = new ZeroOpMock();
    Base* op2 = new ZeroPowMock();
    Add* test = new Add(op1, op2);
    EXPECT_EQ(test->stringify(), "0 + 0 ** 2");
}

TEST(AddTest, PosNum) {
    Base* op1 = new SevenOpMock();
    Base* op2 = new PosSubMock();
    Add* test = new Add(op1, op2);
    EXPECT_EQ(test->evaluate(), 11);
}
TEST(AddTest, PosNumString) {
    Base* op1 = new SevenOpMock();
    Base* op2 = new PosSubMock();
    Add* test = new Add(op1, op2);
    EXPECT_EQ(test->stringify(), "7 + (5 - 1)");
}

TEST(AddTest, BothNeg) {
    Base* num1 = new SevenOpMock();
    Base* num2 = new NegOpMock();
    Base* op1 = new Mult(num1, num2);
    Base* op2 = new NegOpMock();
    Add* test = new Add(op1, op2);
    EXPECT_EQ(test->evaluate(), -56);
}
TEST(AddTest, BothNegString) {
    Base* num1 = new SevenOpMock();
    Base* num2 = new NegOpMock();
    Base* op1 = new Mult(num1, num2);
    Base* op2 = new NegOpMock();
    Add* test = new Add(op1, op2);
    EXPECT_EQ(test->stringify(), "7 * -7 + -7");
}

TEST(AddTest, NegAndPos) {
    Base* op1 = new PosPowMock();
    Base* op2 = new NegOpMock();
    Add* test = new Add(op1, op2);
    EXPECT_EQ(test->evaluate(), 2);
}
TEST(AddTest, NegAndPosString) {
    Base* op1 = new PosPowMock();
    Base* op2 = new NegOpMock();
    Add* test = new Add(op1, op2);
    EXPECT_EQ(test->stringify(), "3 ** 2 + -7");
}

TEST(AddTest, PosAndZero) {
    Base* num1 = new ZeroOpMock();
    Base* num2 = new SevenOpMock();
    Base* op1 = new Div(num1, num2);
    Base* op2 = new PosPowMock();
    Add* test = new Add(op1, op2);
    EXPECT_EQ(test->evaluate(), 9);
}

TEST(AddTest, PosAndZeroString) {
    Base* num1 = new ZeroOpMock();
    Base* num2 = new SevenOpMock();
    Base* op1 = new Div(num1, num2);
    Base* op2 = new PosPowMock();
    Add* test = new Add(op1, op2);
    EXPECT_EQ(test->stringify(), "0 / 7 + 3 ** 2");
}


#endif //__ADD_TEST_HPP__
