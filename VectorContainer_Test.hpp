#ifndef __VECTORCONTAINER_TEST_HPP__
#define __VECTORCONTAINER_TEST_HPP__

#include "gtest/gtest.h"
#include "base.hpp"
#include "op.hpp"
#include "VectorContainer.hpp"
#include "mult.hpp"
#include <string>
#include "sub.hpp"

TEST(VectorContainerTest, NormalSizeTest)
{
	Base* op1 = new Op(7);
	VectorContainer* v1 = new VectorContainer();
	v1->add_element(op1);
	EXPECT_EQ(1,v1->size());
}


TEST(VectorContainerTest, SingleTreePrintTest)
{
	Base* op1 = new Op(3);
	Base* op2 = new Op(2);
	Base* mult1 = new Mult(op1,op2);
	Base* Tree1 = new Sub(mult1,op2);
	VectorContainer* v1 = new VectorContainer();
	v1->add_element(Tree1);
	testing::internal::CaptureStdout();
	v1->print();
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "3.000000 * 2.000000 - 2.000000\n");
	
}


TEST(VectorContainerTest, SwapTest)
{
	Base* op1 = new Op(-3);
	Base* op2 = new Op(1);
	VectorContainer* v1 = new VectorContainer();
	v1->add_element(op1);
	v1->add_element(op2);
	v1->swap(0,1);
	EXPECT_EQ(op1, v1->at(1));

}

TEST(VectorContainerTest, LargeSizeTest)
{
	Base* op1 = new Op(2);
	VectorContainer* v1 = new VectorContainer();
	for(int i = 0; i < 100; i++)
	{
		v1->add_element(op1);
	}
	EXPECT_EQ(100,v1->size());

}

TEST(VectorContainerTest, ZeroSizeTest)
{
	VectorContainer* v1 = new VectorContainer();
	EXPECT_EQ(0, v1->size());

}


TEST(VectorContainerTest, ManyTreePrintTest)
{
        Base* op1 = new Op(3);
        Base* op2 = new Op(2);
        Base* mult1 = new Mult(op1,op2);
        Base* Tree1 = new Sub(mult1,op2);
	Base* Tree2 = new Sub(mult1,op2);
	Base* Tree3 = new Sub(mult1,op2);
        VectorContainer* v1 = new VectorContainer();
        v1->add_element(Tree1);
	v1->add_element(Tree2);
	v1->add_element(Tree3);
        testing::internal::CaptureStdout();
        v1->print();
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "3.000000 * 2.000000 - 2.000000\n3.000000 * 2.000000 - 2.000000\n3.000000 * 2.000000 - 2.000000\n");

}

#endif //__VECTORCONTAINER_TEST_HPP__

