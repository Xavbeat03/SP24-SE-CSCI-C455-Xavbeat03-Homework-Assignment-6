#include <gtest/gtest.h>

#include "../../src/Maze.cpp"

namespace {

    TEST(IngestNodesFromFile, TEST1){
        std::string testFile = "../../mazes/test-maze.txt";

        Maze::ingestNodesFromFile(testFile);

        ASSERT_EQ(Node::NodesToString(), "{1 2 3 4 5 6}");

        auto* correct = new std::vector<Node*> {Node::getNode(1)->getAdjacentNodes()->at(0)};

        ASSERT_EQ(Node::getNode(1)->getAdjacentNodes()->at(0), correct->at(0));

        correct = new std::vector<Node*> {Node::getNode(2)->getAdjacentNodes()->at(0)};

        ASSERT_EQ(Node::getNode(2)->getAdjacentNodes()->at(0), correct->at(0));

        correct = Node::getNode(3)->getAdjacentNodes();

        ASSERT_EQ(Node::getNode(3)->getAdjacentNodes()->at(0), correct->at(0));
        ASSERT_EQ(Node::getNode(3)->getAdjacentNodes()->at(1), correct->at(1));

        correct = Node::getNode(4)->getAdjacentNodes();

        ASSERT_EQ(Node::getNode(4)->getAdjacentNodes()->size(), 0);

        correct = Node::getNode(5)->getAdjacentNodes();

        ASSERT_EQ(Node::getNode(5)->getAdjacentNodes()->at(0), correct->at(0));

        correct = Node::getNode(6)->getAdjacentNodes();

        ASSERT_EQ(Node::getNode(6)->getAdjacentNodes()->size(), 0);
    }

}