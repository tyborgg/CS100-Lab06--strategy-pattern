#ifndef __SELECTIONSORT_TEST_HPP__
#define __SELECTIONSORT_TEST_HPP__

#include "SelectionSort.cpp"
#include "base.hpp"
//#include "VectorContainer.cpp"
#include "gtest/gtest.h"
#include "op.hpp"
#include "mult.hpp"
#include "container.hpp"
TEST(SelectionSortTest, ThreeNormalTrees)
{
	Base* op1 = new Op(7);
	Base* op2 = new Op(4);
	Base* TreeA = new Mult(op1,op2);

	Base* op3 = new Op(3);
	Base* op4 = new Op(2);
	Base* TreeB = new Mult(op3,op4);

	Base* op5 = new Op(2);
	Base* op6 = new Op(2);
	Base* TreeC = new Mult(op5,op6);

	Sort* s1 = new SelectionSort();	
	VectorContainer* v1 = new VectorContainer(s1);
	v1->add_element(TreeB);
	v1->add_element(TreeA);
	v1->add_element(TreeC);
	v1->sort();

	EXPECT_EQ(v1->at(2)->evaluate(), 4);
	EXPECT_EQ(v1->at(1)->evaluate(), 6);
	EXPECT_EQ(v1->at(0)->evaluate(), 28);

}

TEST(SelectionSortTest, ThreeTreesOneNeg)
{
        Base* op1 = new Op(3);
        Base* op2 = new Op(3);
        Base* TreeA = new Mult(op1,op2);

        Base* op3 = new Op(9);
        Base* op4 = new Op(2);
        Base* TreeB = new Mult(op3,op4);

        Base* op5 = new Op(-2);
        Base* op6 = new Op(2);
        Base* TreeC = new Mult(op5,op6);

        Sort* s1 = new SelectionSort();
        VectorContainer* v1 = new VectorContainer(s1);
        v1->add_element(TreeB);
        v1->add_element(TreeA);
        v1->add_element(TreeC);
        v1->sort();

        EXPECT_EQ(v1->at(2)->evaluate(), -4);
	EXPECT_EQ(v1->at(1)->evaluate(),9);
	EXPECT_EQ(v1->at(0)->evaluate(),18);
}


#endif //__SELECTIONSORT_TEST_HPP__
