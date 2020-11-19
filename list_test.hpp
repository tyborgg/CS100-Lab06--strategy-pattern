#ifndef __LIST_TEST_HPP__
#define __LIST_TEST_HPP__

#include "gtest/gtest.h"

#include "listContainer.hpp"
#include "base.hpp"

using namespace std;

TEST(ListTest, size) {
    Base* op = new Op(2);
    ListContainer* v1 = new ListContainer();
    v1->add_element(op);
    EXPECT_EQ(v1->size(),1);
}
TEST(ListTest, size2) {
    Base* op1 = new Op(2);
    Base* op2 = new Op(2);
    Base* mult = new Mult(op1,op2);
    ListContainer* v1 = new ListContainer();
    v1->add_element(op1);
    v1->add_element(op2);
    v1->add_element(mult);
    EXPECT_EQ(v1->size(),3);
}

TEST(ListTest, atTest) { 
    Op* seven = new Op(7);
    ListContainer* test_container = new ListContainer();
    //
    //             // Exercise some functionality of hte test elements
    test_container->add_element(seven);
    //
    //                     // Assert that the container has at least a single element
    //                         // otherwise we are likely to cause a segfault when accessing
    ASSERT_EQ(test_container->size(), 1);
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
}

TEST(ListTest, SwapTest) {
    Op* seven = new Op(7);
    ListContainer* test_container = new ListContainer();
    test_container->add_element(seven);
    Op* two = new Op(2);
    Op* three = new Op(3);
    test_container->add_element(two);
    test_container->add_element(three);
    test_container->swap(0,2);

    ASSERT_EQ(test_container->size(), 3);
    EXPECT_EQ(test_container->at(0)->evaluate(), 3);
    EXPECT_EQ(test_container->at(2)->evaluate(), 7);
}

TEST(ListTest, SwapTest2) {
    Base* seven = new Op(7);
    ListContainer* test_container = new ListContainer();
    test_container->add_element(seven);
    Base* two = new Op(2);
    Base* three = new Op(3);
    Base* six = new Mult(two, three);
    test_container->add_element(two);
    test_container->add_element(three);
    test_container->add_element(six);
    test_container->swap(1,3);

    ASSERT_EQ(test_container->size(), 4);
    EXPECT_EQ(test_container->at(1)->evaluate(), 6);
    EXPECT_EQ(test_container->at(3)->evaluate(), 2);
}

TEST(ListTest, PrinTest) {
    Op* seven = new Op(7);
    ListContainer* test_container = new ListContainer();
    test_container->add_element(seven);
    Base* two = new Op(2);
    Base* three = new Op(3);
    Mult* six = new Mult(two, three);
    test_container->add_element(six);
    test_container->swap(0,1);
   
    testing::internal::CaptureStdout();
    test_container->print();
    std::string output = testing::internal::GetCapturedStdout();
        
    ASSERT_EQ(test_container->size(), 2);
    EXPECT_EQ(output, "2.000000 * 3.000000\n7.000000\n");
}

TEST(ListTest, PrintTest2) {
    Base* op1 = new Op(2);
    Base* op2 = new Op(3);
    Base* mult = new Mult(op1,op2);
    ListContainer* v1 = new ListContainer();
    v1->add_element(mult);

    //testing::internal::CaptureStdout();
    //v1->print();
    //std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(v1->size(),1);

    testing::internal::CaptureStdout();
    v1->print();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "2.000000 * 3.000000\n");    
}


#endif //__LIST_TEST_HPP__
