//
// Created by xavierb on 4/4/24.
//

#include "Maze.cpp"

int main()
{
    //Maze

    std::string File = "../../mazes/maze.txt";

    Maze::ingestNodesFromFile(File);

    std::vector<Node*>* path = Maze::A_Star(Node::getNode(1), Node::getNode(100));

    std::cout << "\nFile:";

    std::cout << "\n" << File << ":\n";

    std::cout << "Path:\n";

    for(int i = 0; i < path->size(); i++){
        std::cout << path->at(i)->getValue();
        if(i != path->size()-1)
            std::cout << "->";
    }
    std::cout << "\nPath Cost: " << path->at(path->size()-1)->getFCost();

    std::cout << '\n';

    //test-maze

    Node::clearNodes();

    std::string File2 = "../../mazes/test-maze.txt";

    Maze::ingestNodesFromFile(File2);

    std::vector<Node*>* path2 = Maze::A_Star(Node::getNode(1), Node::getNode(6));

    std::cout << "\nFile:";

    std::cout << "\n" <<  File2 << ":\n";

    std::cout << "Path:\n";

    for(int i = 0; i < path2->size(); i++){
        std::cout << path2->at(i)->getValue();
        if(i != path2->size()-1)
            std::cout << "->";
    }
    std::cout << "\nPath Cost: " << path2->at(path2->size()-1)->getFCost();

    std::cout << '\n';

    // test-maze2

    Node::clearNodes();

    std::string File3 = "../../mazes/test-maze2.txt";

    Maze::ingestNodesFromFile(File3);

    std::vector<Node*>* path3 = Maze::A_Star(Node::getNode(1), Node::getNode(7));

    std::cout << "\nFile:";

    std::cout << "\n" << File3 << ":\n";

    std::cout << "Path:\n";

    for(int i = 0; i < path3->size(); i++){
        std::cout << path3->at(i)->getValue();
        if(i != path3->size()-1)
            std::cout << "->";
    }
    std::cout << "\nPath Cost: " << path3->at(path3->size()-1)->getFCost();

    std::cout << '\n';

}
