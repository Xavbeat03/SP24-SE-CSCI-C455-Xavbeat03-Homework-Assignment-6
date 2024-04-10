#include <gtest/gtest.h>

#include "../../src/Maze.cpp"

namespace {

    TEST(AStar, TEST1){
        std::string testFile = "../../mazes/maze.txt";

        Maze::ingestNodesFromFile(testFile);


    }

}