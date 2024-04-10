#include <exception>
#include <vector>

//
// Created by xavierb on 4/8/24.
//
class Node{
private:
    static inline auto* nodes = new std::vector<Node*> {};
    static inline bool s_first = true;

    std::vector<Node*>* adjacentNodes = new std::vector<Node*> {};
    int adjacentSize = 0;
    int value;

    void addNodeToNodes (Node* node){
        nodes->emplace_back(node);
    }
public:


    /**
     * Constructs a node with value value
     * @param value the integer value of the node
     */
    Node(int value){
        this->value = value;

        addNodeToNodes(this);
    }

    ~Node()=default;

    /**
     * Adds an adjacent node to this node
     * If the node is already in AdjacentNodes it won't be added twice
     * @param node the node being added as an adjacent one
     */
    void addAdjacentNode(Node* node){
        for(auto & adjacentNode : *adjacentNodes){
            if(adjacentNode==node || adjacentNode->getValue() == node->getValue()){
                return;
            }
        }

        adjacentNodes->emplace_back(node);
    }

    /**
     * returns a list of all the adjacent nodes
     * @return a pointer to an array of Nodes
     */

    std::vector<Node*>* getAdjacentNodes(){
        return adjacentNodes;
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
        for(int i = 0; i < nodes->size(); i++){
            if (nodes->at(i)->getValue() == value){
                return nodes->at(i);
            }
        }
        return nullptr;
    }
};