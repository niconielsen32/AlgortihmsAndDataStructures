#include <iostream>
#include <vector>
#include <memory>

using namespace std;


class Node {

public:
    int x;
    int y;
    int distance;
    shared_ptr<Node> parent;
    vector<shared_ptr<Node>> children;

    Node(){}
    Node(shared_ptr<Node> parent)
        :parent(parent) {}

    void addNode(shared_ptr<Node> child){
        children.push_back(child);
    }
};


class Tree {

public:

    vector<shared_ptr<Node>> nodes;

    Tree(shared_ptr<Node> root){}
    Tree(){}

    void addNode(shared_ptr<Node> child){
        nodes.push_back(child);
    }
};



int main(){

    Tree tree;


    for(int i = 0; i < 8; i++){
        shared_ptr<Node> node(new Node());
        node->x = i;
        tree.addNode(node);
    }

    for(int i = 0; i < 8; i++){
        cout << tree.nodes[i]->x << endl;
    }


    return 0;
}
