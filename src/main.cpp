//
// Created by xavierb on 4/4/24.
//

#include "Maze.cpp"

int main()
{
    std::string File = "../../mazes/maze.txt";

    Maze::ingestNodesFromFile(File);

    std::vector<Node*>* path = Maze::A_Star(Node::getNode(1), Node::getNode(100));

    std::cout << "Path:\n";

    for(int i = 0; i < path->size(); i++){
        std::cout << path->at(i)->getValue();
        if(i != path->size()-1)
            std::cout << "->";
    }
    std::cout << "\nPath Length: " << path->at(path->size()-1)->getFCost();
}
