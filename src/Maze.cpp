//
// Created by xavierb on 4/4/24.
//

#include <queue>
#include <fstream>
#include "Node.cpp"

class Maze
{
public:

    /**
    function A_star(start, goal):

    // Initialize open and closed lists
    open_list = priority_queue()
    closed_list = set()

    // Add the start node to the open list
    open_list.add(start)

    // Initialize costs for start node
    start.g_cost = 0
    start.h_cost = heuristic(start, goal)
    start.f_cost = start.g_cost + start.h_cost

    while open_list is not empty:

        // Get the node with the lowest f_cost from the open list
        current_node = open_list.pop()

        // Check if the current node is the goal
        if current_node == goal:
            return reconstruct_path(start, goal)

        // Move current node from open list to closed list
        closed_list.add(current_node)


        // Expand current node's neighbors
        for neighbor in current_node.neighbors():
            // Skip neighbor if it's in the closed list
            if neighbor in closed_list:
                continue


            // Calculate tentative g_cost for the neighbor
            tentative_g_cost = current_node.g_cost + distance(current_node, neighbor)

            // If neighbor is not in the open list, add it
            if neighbor not in open_list:
                open_list.add(neighbor)
            // If this path is worse than the one already present, skip it
            else if tentative_g_cost >= neighbor.g_cost:
                continue

            // This path is the best until now. Record it!
            neighbor.parent = current_node
            neighbor.g_cost = tentative_g_cost
            neighbor.h_cost = heuristic(neighbor, goal)
            neighbor.f_cost = neighbor.g_cost + neighbor.h_cost

    // If open_list is empty and goal has not been reached, no path exists
    return null

     */

    /**
     * Finds the best path between two nodes when it exists
     * @param start the starting node
     * @param goal the goal node to end on
     * @return a vector representing the path between start and goal or a nullptr if there is no path
     */
    static std::vector<Node*>* A_Star(Node* start, Node* goal){

        // Initialize open and closed lists
        auto* openList = new std::priority_queue<Node*>;
        auto* closedList = new std::vector<Node*>;

        for (Node* node : *Node::getNodes()){
            node->setGCost(2147483647);
            node->setHCost(0);
            node->setFCost(node->getGCost() + node->getHCost());
        }

        // Add the start node to the open list
        openList->push(start);

        // Initialize costs for start node
        start->setGCost(0);
        start->setHCost(heuristic(start,goal));
        start->setFCost(start->getGCost()+start->getHCost());

        while(!openList->empty()){

            // Get the node with the lowest f_cost from the open list
            Node* current_node = openList->top();
            openList->pop();

            // Check if the current node is the goal
            if (current_node == goal){
                return reconstruct_path(start, goal);
            }

            // Move current node from open list to closed list
            closedList->push_back(current_node);

            // TESTING
            Node::printNodes(current_node->getAdjacentNodes());

            // Expand current node's neighbors
            for(Node* neighbor: *current_node->getAdjacentNodes()) {

                // Skip neighbor if it's in the closed list
                bool neighborIsNode = false;
                for (Node *node: *closedList){
                    if (neighbor == node) {
                        neighborIsNode = true;
                        break;
                    }
                }
                if(neighborIsNode) continue;

                // Calculate tentative g_cost for the neighbor
                int tentative_g_cost = current_node->getGCost() + 1; // 1 is the distance between any node and its neighbor in an unweighted graph

                // If neighbor is not in the open list, add it
                auto tempqueue = *openList;
                while(!tempqueue.empty()){
                    if(tempqueue.top() != neighbor){
                        tempqueue.pop();
                    }
                }
                if(tempqueue.empty()){
                    openList->push(neighbor);
                }

                // If this path is worse than the one already present, skip it
                if (tentative_g_cost >= neighbor->getGCost()){
                    continue;
                }

                // This path is the best until now. Record it!
                neighbor->setParent(current_node);
                neighbor->setGCost(tentative_g_cost);
                neighbor->setHCost(heuristic(neighbor, goal));
                neighbor->setFCost(neighbor->getGCost() + neighbor->getHCost());

            }
        }

        if(openList->empty()){
            return nullptr;
        }
    }

    /**
     *
     function reconstruct_path(start, goal):
    path = []. //you may also use a vector
    current_node = goal
    while current_node != start:
        path.prepend(current_node)
        current_node = current_node.parent
    path.prepend(start)
    return path
     */

    /**
     * Reconstructs the path between the start node and goal node
     * @param start the starting node
     * @param goal the ending node
     * @return a vector of the path from start node to goal node
     */
    static std::vector<Node*>* reconstruct_path(Node* start, Node* goal){
        auto* revPath = new std::vector<Node*> {};
        Node* currentNode = goal;
        while(currentNode!=start){
            revPath->emplace_back(currentNode);
            currentNode = currentNode->getParent();
        }
        revPath->emplace_back(start);

        // Reverse the reversed path

        auto* path = new std::vector<Node*> {};

        for(int i = revPath->size()-1; i > -1; i--){
            path->emplace_back(revPath->at(i));
        }

        return path;
    }

    /**
     * Returns the heuristic estimation between neighbor and goal
     * @param start the start node for the heuristic
     * @param goal the final node for the heuristic
     * @return integer representing the heuristic distance between start and goal, in this case 0 is used
     */
    static int heuristic(Node* start, Node* goal){
        return 0;
    }


    /**
     * Takes a filepath and reads the file. Attempting to convert it to a Maze
     * If it fails, returns a nullptr
     * @param filePath the path to the file
     */
    static void ingestNodesFromFile(std::string filePath){
        std::string line;
        std::ifstream file;
        file.open(filePath);
        if (file.is_open())
        {
            while (getline (file, line) )
            {
                std::vector<std::string> splitLine = splitString(line, ' ');
                if(splitLine.size() == 0) continue;

                if(Node::getNode(std::stoi(splitLine.at(0))) == nullptr){
                    new Node(std::stoi(splitLine.at(0)));
                }

                for(int i = 1; i < splitLine.size() && std::stoi(splitLine.at(i)) != -1; i++){
                    Node::getNode(std::stoi(splitLine.at(0)))->addAdjacentByValue(std::stoi(splitLine.at(i)));
                }
            }
        }


    }

private:

    /**
     * Split string str at delimiter dl returning a vector of the pieces
     * @param str string split
     * @param dl delimiter
     * @return vector containing pieces
     */
    static std::vector<std::string> splitString(std::string str, char dl)
    {
        std::string word;

        // to count the number of split strings
        int num = 0;

        // adding delimiter character at the end
        // of 'str'
        str = str + dl;

        // length of 'str'
        int l = str.size();

        // traversing 'str' from left to right
        std::vector<std::string> substr_list;
        for (int i = 0; i < l; i++) {

            // if str[i] is not equal to the delimiter
            // character then accumulate it to 'word'
            if (str[i] != dl)
                word = word + str[i];

            else {

                // if 'word' is not an empty string,
                // then add this 'word' to the vector
                // 'substr_list[]'
                if ((int)word.size() != 0)
                    substr_list.push_back(word);

                // reset 'word'
                word = "";
            }
        }

        // return the splitted strings
        return substr_list;
    }

};

