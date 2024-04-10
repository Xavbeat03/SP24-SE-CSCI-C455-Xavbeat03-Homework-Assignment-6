#include <gtest/gtest.h>

#include "../../src/Node.cpp"

namespace {

    TEST(GetValue, SingleDigitTest1){
        auto* p = new Node(5);

        ASSERT_EQ(p->getValue(), 5);
    }

    TEST(GetValue, DoubleDigitTest1){
        auto* p = new Node(10);
        auto* p2 = new Node(15);

        ASSERT_EQ(p->getValue(), 10);
        ASSERT_EQ(p2->getValue(), 15);
    }

    TEST(GetValue, TripleDigitTest1){
        auto* p = new Node(100);
        auto* p2 = new Node(150);
        auto* p3 = new Node(250);

        ASSERT_EQ(p->getValue(), 100);
        ASSERT_EQ(p2->getValue(), 150);
        ASSERT_EQ(p3->getValue(), 250);
    }

}