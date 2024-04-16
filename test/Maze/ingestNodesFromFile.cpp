#include <gtest/gtest.h>

#include "../../src/Maze.cpp"

namespace {

    TEST(IngestNodesFromFile, TEST1){
        std::string testFile = "../../mazes/test-maze.txt";

        Maze::ingestNodesFromFile(testFile);

        ASSERT_EQ(Node::NodesToString(), "{1 2 3 4 5 6}");

        ASSERT_EQ(Node::getNode(1)->getAdjacentNodes()->at(0)->getValue(), 2);

        ASSERT_EQ(Node::getNode(2)->getAdjacentNodes()->at(0)->getValue(), 3);

        ASSERT_EQ(Node::getNode(3)->getAdjacentNodes()->at(0)->getValue(), 4);
        ASSERT_EQ(Node::getNode(3)->getAdjacentNodes()->at(1)->getValue(), 5);

        ASSERT_EQ(Node::getNode(4)->getAdjacentNodes()->size(), 0);

        ASSERT_EQ(Node::getNode(5)->getAdjacentNodes()->at(0)->getValue(), 6);

        ASSERT_EQ(Node::getNode(6)->getAdjacentNodes()->size(), 0);
    }

    TEST(IngestNodesFromFile, TEST2){
        std::string testFile = "../../mazes/test-maze2.txt";

        Maze::ingestNodesFromFile(testFile);

        ASSERT_EQ(Node::NodesToString(), "{1 2 3 4 8 5 6 7 9 10 11 12}");

        ASSERT_EQ(Node::getNode(1)->getAdjacentNodes()->at(0)->getValue(), 2);

        ASSERT_EQ(Node::getNode(2)->getAdjacentNodes()->at(0)->getValue(), 3);

        ASSERT_EQ(Node::getNode(3)->getAdjacentNodes()->at(0)->getValue(), 4);
        ASSERT_EQ(Node::getNode(3)->getAdjacentNodes()->at(1)->getValue(), 8);

        ASSERT_EQ(Node::getNode(4)->getAdjacentNodes()->at(0)->getValue(), 5);

        ASSERT_EQ(Node::getNode(5)->getAdjacentNodes()->at(0)->getValue(), 6);

        ASSERT_EQ(Node::getNode(6)->getAdjacentNodes()->at(0)->getValue(), 7);

        ASSERT_EQ(Node::getNode(7)->getAdjacentNodes()->size(), 0);

        ASSERT_EQ(Node::getNode(8)->getAdjacentNodes()->at(0)->getValue(), 9);

        ASSERT_EQ(Node::getNode(9)->getAdjacentNodes()->at(0)->getValue(), 10);

        ASSERT_EQ(Node::getNode(10)->getAdjacentNodes()->at(0)->getValue(), 11);

        ASSERT_EQ(Node::getNode(11)->getAdjacentNodes()->at(0)->getValue(), 12);

        ASSERT_EQ(Node::getNode(12)->getAdjacentNodes()->size(), 0);


    }

}