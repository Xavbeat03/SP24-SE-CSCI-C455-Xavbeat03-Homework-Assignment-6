//
// Created by xavierb on 4/4/24.
//

#include <queue>
#include <string>
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
    std::vector<Node*>* A_Star(Node* start, Node* goal){

        // Initialize open and closed lists
        auto* openList = new std::priority_queue<Node*>;
        auto* closedList = new std::vector<Node*>;

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
                auto* tempqueue = openList;
                while(!tempqueue->empty()){
                    if(tempqueue->top() != neighbor){
                        tempqueue->pop();
                    }
                }
                if(tempqueue->empty()){
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
     *
     * @param start
     * @param goal
     * @return
     */
    std::vector<Node*>* reconstruct_path(Node* start, Node* goal){
        auto* revPath = new std::vector<Node*> {};
        Node* currentNode = goal;
        while(currentNode!=start){
            revPath->emplace_back(currentNode);
            currentNode = currentNode->getParent();
        }
        revPath->emplace_back(start);

        // Reverse the reversed path

        auto* path = new std::vector<Node*> {};

        for(int i = revPath->size()-1; i > 0; i--){
            path->emplace_back(revPath->at(i));
        }

        return path;



        return new std::vector<Node*>;
    }

    /**
     * Returns the heuristic estimation between neighbor and goal
     * @param start the start node for the heuristic
     * @param goal the final node for the heuristic
     * @return integer representing the heuristic distance between start and goal, in this case 0 is used
     */
    int heuristic(Node* start, Node* goal){
        return 0;
    }


    /**
     * Takes a filepath and reads the file. Attempting to convert it to a Maze
     * If it fails, returns a nullptr
     * @param filePath the path to the file
     * @return A maze pointer of null pointer
     */
    static Maze* ingestMazeFromFile(std::string filePath){
        return nullptr;
    }
private:

};

