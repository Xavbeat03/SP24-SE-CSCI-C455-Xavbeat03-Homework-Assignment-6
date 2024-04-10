#include <gtest/gtest.h>

#include "../../src/Node.cpp"

namespace {

    TEST(GetNode, NoNodes){
        ASSERT_EQ(nullptr, Node::getNode(3));
    }

    TEST(GetNode, OneNode){
        auto* n = new Node(3);
        ASSERT_EQ(n, Node::getNode(3));
    }

    TEST(GetNode, TwoNodes){
        auto* n = new Node(3);
        auto* n2 = new Node(4);

        ASSERT_EQ(n, Node::getNode(3));
        ASSERT_EQ(n2, Node::getNode(4));
    }


}