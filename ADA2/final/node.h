#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include <memory>

using namespace std;


// Represents a node of an n-ary tree
class Node {
public:
    int x, y;
    int distance;
    Node() {}
    Node(int x, int y, int distance)
        : x(x), y(y), distance(distance) {}

};


#endif // NODE_H
