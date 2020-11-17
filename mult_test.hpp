#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "mult.hpp"
#include "seven_mock_op.hpp"
#include "zero_mock_op.hpp"
#include "neg_mock_op.hpp"

TEST(MultTest, BothZero) {
    Base* op1 = new ZeroOpMock();
    Base* op2 = new ZeroOpMock();
    Mult* test = new Mult(op1, op2);
    EXPECT_EQ(test->evaluate(), 0);
}
TEST(MultTest, BothZeroString) {
    Base* op1 = new ZeroOpMock();
    Base* op2 = new ZeroOpMock();
    Mult* test = new Mult(op1, op2);
    EXPECT_EQ(test->stringify(),"0 * 0");
}

TEST(MultTest, PosNum) {	
    Base* op1 = new SevenOpMock();
    Base* op2 = new SevenOpMock();
    Mult* test = new Mult(op1, op2);
    EXPECT_EQ(test->evaluate(), 49);
}
TEST(MultTest, PosNumString) {
    Base* op1 = new SevenOpMock();
    Base* op2 = new SevenOpMock();
    Mult* test = new Mult(op1, op2);
    EXPECT_EQ(test->stringify(),"7 * 7");
}

TEST(MultTest, BothNeg) {
    Base* op1 = new NegOpMock();
    Base* op2 = new NegOpMock();
    Mult* test = new Mult(op1, op2);
    EXPECT_EQ(test->evaluate(), 49);
}
TEST(MultTest, BothNegString) {
    Base* op1 = new NegOpMock();
    Base* op2 = new NegOpMock();
    Mult* test = new Mult(op1, op2);
    EXPECT_EQ(test->stringify(),"-7 * -7");
}

TEST(MultTest, NegAndPos) {
    Base* op1 = new SevenOpMock();
    Base* op2 = new NegOpMock();
    Mult* test = new Mult(op1, op2);
    EXPECT_EQ(test->evaluate(), -49);
}
TEST(MultTest, NegAndPosString) {
    Base* op1 = new SevenOpMock();
    Base* op2 = new NegOpMock();
    Mult* test = new Mult(op1, op2);
    EXPECT_EQ(test->stringify(),"7 * -7");
}

TEST(MultTest, PosAndZero) {
    Base* op1 = new ZeroOpMock();
    Base* op2 = new SevenOpMock();
    Mult* test = new Mult(op1, op2);
    EXPECT_EQ(test->evaluate(),0);
}

TEST(MultTest, PosAndZeroString) {
    Base* op1 = new ZeroOpMock();
    Base* op2 = new SevenOpMock();
    Mult* test = new Mult(op1, op2);
    EXPECT_EQ(test->stringify(),"0 * 7");
}


#endif //__MULT_TEST_HPP__
