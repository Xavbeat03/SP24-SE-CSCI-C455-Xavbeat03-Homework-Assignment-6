#include <exception>
#include <vector>
#include <string>
#include <iostream>

class Node{
private:
    static inline auto* nodes = new std::vector<Node*> {};

    std::vector<Node*>* adjacentNodes = new std::vector<Node*> {};
    int value;

    Node* parent;
public:
    Node *getParent() const {
        return parent;
    }

    void setParent(Node* parent) {
        Node::parent = parent;
    }

    int getGCost() const {
        return g_cost;
    }

    void setGCost(int gCost) {
        g_cost = gCost;
    }

    int getHCost() const {
        return h_cost;
    }

    void setHCost(int hCost) {
        h_cost = hCost;
    }

    int getFCost() const {
        return f_cost;
    }

    void setFCost(int fCost) {
        f_cost = fCost;
    }

private:
    int g_cost;
    int h_cost;
    int f_cost;

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
     * Adds an adjacent node by the value
     * @param value the new adjacencies value
     */
    void addAdjacentByValue(int value){
        if (getNode(value) == nullptr) {
            addAdjacentNode(new Node(value));
        } else {
            addAdjacentNode(getNode(value));
        }
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

    static std::vector<Node*>* getNodes(){
        return nodes;
    }

    /**
     * Clears the internal node list
     * mainly intended for testing usage.
     */
    static void clearNodes(){
        nodes = new std::vector<Node*> {};
    }

    static std::string NodesToString(){
        std::string val;
        val += "{";
        for(int i = 0; i < nodes->size(); i++){
            val += std::to_string(nodes->at(i)->getValue());
            if(i != nodes->size()-1){
                val += " ";
            }
        }
        val += "}";
        return val;
    }
};