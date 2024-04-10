#include <gtest/gtest.h>

#include "../../src/Node.cpp"

namespace {

    // This tests both the get and add since they're tied together

    TEST(AddAdjacentNode, OneNode){

        Node n = Node(3);
        Node* No = &n;

        Node adj1 = Node(3);
        Node* A1 = &adj1;

        No->addAdjacentNode(A1);

        std::vector<Node*> nodes = {A1};
        std::vector<Node*>* correct = &nodes;

        ASSERT_EQ(correct->at(0), No->getAdjacentNodes()->at(0));

    }

    TEST(AddAdjacentNode, TwoNode){

        Node n = Node(3);
        Node* No = &n;

        Node adj1 = Node(3);
        Node* A1 = &adj1;

        Node adj2 = Node(4);
        Node* A2 = &adj2;

        No->addAdjacentNode(A1);
        No->addAdjacentNode(A2);

        std::vector<Node*> nodes = {A1, A2};
        std::vector<Node*>* correct = &nodes;

        ASSERT_EQ(correct->at(0), No->getAdjacentNodes()->at(0));
        ASSERT_EQ(correct->at(1), No->getAdjacentNodes()->at(1));

    }

    TEST(AddAdjacentNode, ThreeNode){

        Node n = Node(3);
        Node* No = &n;

        Node adj1 = Node(3);
        Node* A1 = &adj1;

        Node adj2 = Node(4);
        Node* A2 = &adj2;

        Node adj3 = Node(5);
        Node* A3 = &adj3;

        No->addAdjacentNode(A1);
        No->addAdjacentNode(A2);
        No->addAdjacentNode(A3);

        std::vector<Node*> nodes = {A1, A2, A3};
        std::vector<Node*>* correct = &nodes;

        ASSERT_EQ(correct->at(0), No->getAdjacentNodes()->at(0));
        ASSERT_EQ(correct->at(1), No->getAdjacentNodes()->at(1));
        ASSERT_EQ(correct->at(2), No->getAdjacentNodes()->at(2));

    }

    TEST(AddAdjacentNode, SameNode){
        Node n = Node(3);
        Node* No = &n;

        Node adj1 = Node(3);
        Node* A1 = &adj1;

        Node adj2 = Node(3);
        Node* A2 = &adj2;

        No->addAdjacentNode(A1);
        No->addAdjacentNode(A1);
        No->addAdjacentNode(A2);

        std::vector<Node*> nodes = {A1};
        std::vector<Node*>* correct = &nodes;

        ASSERT_EQ(correct->at(0), No->getAdjacentNodes()->at(0));
        ASSERT_ANY_THROW(No->getAdjacentNodes()->at(1));
    }



}