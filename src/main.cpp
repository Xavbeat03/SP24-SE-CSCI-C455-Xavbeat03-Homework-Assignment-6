//
// Created by xavierb on 4/4/24.
//

#include "Maze.cpp"

int main()
{
    std::string testFile = "../../mazes/test-maze2.txt";

    Maze::ingestNodesFromFile(testFile);

    std::vector<Node*>* path = Maze::A_Star(Node::getNode(1), Node::getNode(7));
}
