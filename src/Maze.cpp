//
// Created by xavierb on 4/4/24.
//

#include <queue>
#include "Node.cpp"

class Maze
{
public:
    //TODO Set Heuristic to 0

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
     *
     * @param start
     * @param goal
     * @return
     */
    std::vector<Node*>* A_Star(Node* start, Node* goal){

        // Initialize open and closed lists
        auto* openList = new std::priority_queue<Node*>;
        auto* closedList = new std::vector<Node*>;

        // Add the start node to the open list
        openList->Insert(start);

        // Initialize costs for start node
        int startCost = 0;
        int startHeuristicCost = heuristic(start, goal);
        int startFunctionCost = startCost + startHeuristicCost;

        while(!openList->empty()){
            // Get the node with the lowest f_cost from the open list
            Node* current_node = openList->top();
            openList->pop();

            int curCost = 0;

            // Check if the current node is the goal
            if (current_node == goal){
                return reconstruct_path(start, goal);
            }

            // Move current node from open list to closed list
            closedList->emplace_back(current_node);

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
                int tentative_g_cost = curCost + 1;

                // If neighbor is not in the open list, add it
                for(Node *node: openList.)




            }
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

