//
// Created by xavierb on 4/4/24.
//

#include "PriorityQueue/PriorityQueue.h"
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
    PriorityQueue<Node> A_Star(Node* start, Node* goal){
        PriorityQueue openList = new PriorityQueue<Node>;



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
    std::vector<Node>* reconstruct_path(Node* start, Node* goal){


        return new std::vector<Node>;
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
private:

};

