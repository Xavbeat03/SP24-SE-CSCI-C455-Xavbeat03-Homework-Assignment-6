//
// Created by xavierb on 4/8/24.
//
class Node{
private:
    static Node* nodes;
    static int numNodes;

    Node* adjacentNodes;
    int adjacentSize = 0;

    int value;

public:


    /**
     * Constructs a node with value value
     * @param value the integer value of the node
     */
    Node(int value){
        this->value = value;
        nodes[numNodes++] = *this;
    }

    ~Node()=default;

    /**
     * Adds an adjacent node to this node
     * @param node the node being added as an adjacent one
     */
    void addAdjacentNode(Node node){
        adjacentNodes[adjacentSize] = node;
    }

    /**
     * returns a list of all the adjacent nodes
     * @return a pointer to an array of Nodes
     */

    Node* getAdjacentNodes(){
        return nodes;
    }

    /**
     * Gets the value of the node
     * @return the integer value of the node
     */
    int getValue(){
        return value;
    }

    /**
     * Gets a node based on the value
     * @param value the value to search by
     * @return a pointer to a node
     */
    static Node* getNode(int value){
        for(int i = 0; i < numNodes; i++){
            if (nodes[i].getValue() == value){
                return &nodes[i];
            }
        }
        return nullptr;
    }
};