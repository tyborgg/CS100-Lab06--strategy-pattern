#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "div.hpp"
#include "seven_mock_op.hpp"
#include "zero_mock_op.hpp"
#include "neg_mock_op.hpp"

TEST(DivTest, BothZero) {
    Base* op1 = new ZeroOpMock();
    Base* op2 = new ZeroOpMock();
    Div* test = new Div(op1, op2);
    EXPECT_EQ(test->evaluate(), -1);
}
TEST(DivTest, BothZeroString) {
    Base* op1 = new ZeroOpMock();
    Base* op2 = new ZeroOpMock();
    Div* test = new Div(op1, op2);
    EXPECT_EQ(test->stringify(),"Error");
}

TEST(DivTest, PosNum) {	
    Base* op1 = new SevenOpMock();
    Base* op2 = new SevenOpMock();
    Div* test = new Div(op1, op2);
    EXPECT_EQ(test->evaluate(), 1);
}
TEST(DivTest, PosNumString) {
    Base* op1 = new SevenOpMock();
    Base* op2 = new SevenOpMock();
    Div* test = new Div(op1, op2);
    EXPECT_EQ(test->stringify(),"7 / 7");
}

TEST(DivTest, BothNeg) {
    Base* op1 = new NegOpMock();
    Base* op2 = new NegOpMock();
    Div* test = new Div(op1, op2);
    EXPECT_EQ(test->evaluate(), 1);
}
TEST(DivTest, BothNegString) {
    Base* op1 = new NegOpMock();
    Base* op2 = new NegOpMock();
    Div* test = new Div(op1, op2);
    EXPECT_EQ(test->stringify(),"-7 / -7");
}

TEST(DivTest, NegAndPos) {
    Base* op1 = new SevenOpMock();
    Base* op2 = new NegOpMock();
    Div* test = new Div(op1, op2);
    EXPECT_EQ(test->evaluate(), -1);
}
TEST(DivTest, NegAndPosString) {
    Base* op1 = new SevenOpMock();
    Base* op2 = new NegOpMock();
    Div* test = new Div(op1, op2);
    EXPECT_EQ(test->stringify(),"7 / -7");
}

TEST(DivTest, PosAndZero) {
    Base* op1 = new ZeroOpMock();
    Base* op2 = new SevenOpMock();
    Div* test = new Div(op1, op2);
    EXPECT_EQ(test->evaluate(),0);
}

TEST(DivTest, PosAndZeroString) {
    Base* op1 = new ZeroOpMock();
    Base* op2 = new SevenOpMock();
    Div* test = new Div(op1, op2);
    EXPECT_EQ(test->stringify(),"0 / 7");
}

TEST(DivTest, ZeroInDenominator) {
    Base* op1 = new SevenOpMock();
    Base* op2 = new ZeroOpMock();
    Div* test = new Div(op1, op2);
    EXPECT_EQ(test->evaluate(),-1);
}
TEST(DivTest, ZeroInDenomiatorString) {
    Base* op1 = new SevenOpMock();
    Base* op2 = new ZeroOpMock();
    Div* test = new Div(op1, op2);
    EXPECT_EQ(test->stringify(),"Error");
}

TEST(DivTest, NegAndZeroInDenominator) {
    Base* op1 = new NegOpMock();
    Base* op2 = new ZeroOpMock();
    Div* test = new Div(op1, op2);
    EXPECT_EQ(test->evaluate(),-1);
}
TEST(DivTest, NegAndZeroInDenominatorString) {
    Base* op1 = new NegOpMock();
    Base* op2 = new ZeroOpMock();
    Div* test = new Div(op1, op2);
    EXPECT_EQ(test->stringify(),"Error");
}




#endif //__DIV_TEST_HPP__
