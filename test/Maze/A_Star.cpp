#include <gtest/gtest.h>

#include "../../src/Maze.cpp"

namespace {

    TEST(AStar, TEST1){
        std::string testFile = "../../mazes/test-maze.txt";

        Maze::ingestNodesFromFile(testFile);

        std::vector<Node*>* path = Maze::A_Star(Node::getNode(1), Node::getNode(6));

        if(path== nullptr) {
            FAIL();
        }

        ASSERT_EQ(path->size(), 5);

        std::vector<int> correctVal = {1,2,3,5,6};

        for(int i = 0; i < 5; i ++) {
            ASSERT_EQ(path->at(i), Node::getNode(correctVal.at(i)));
        }

    }

    TEST(AStar, TEST2){

        std::string testFile = "../../mazes/test-maze2.txt";

        Maze::ingestNodesFromFile(testFile);

        std::vector<Node*>* path = Maze::A_Star(Node::getNode(1), Node::getNode(7));



        /**
         *

        if(path== nullptr) {
            FAIL();
        }

        ASSERT_EQ(path->size(), 7);

        std::vector<int> correctVal = {1,2,3,4,5,6,7};

        for(int i = 0; i < 7; i ++) {
            ASSERT_EQ(path->at(i), Node::getNode(correctVal.at(i)));
            std::cout << path->at(i)->getValue();
        }
         */

    }

}