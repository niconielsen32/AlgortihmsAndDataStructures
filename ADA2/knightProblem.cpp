#include <bits/stdc++.h> 
//#include "Tree.h"

using namespace std; 
  
class Node {

public:
    int x;
    int y;
    int distance;
    vector<Node> children;

    Node(){}

    Node(int x, int y, int distance) 
        : x(x), y(y), distance(distance) 
    { 
    }

};


class Tree {

public:

    vector<Node> nodes;

    Tree(Node root){}
    Tree(){}

    void addNode(Node child){
        nodes.push_back(child);
    }

};

  
// Utility method returns true if (x, y) lies 
// inside Board 
bool isInsideBoard(int x, int y, int N) 
{ 
    if (x >= 1 && x <= N && y >= 1 && y <= N) 
        return true; 
    return false; 
} 
  
// Method returns minimum step 
// to reach target position 
int minStepToReachTarget(int knightPos[], int targetPos[], int N) 
{ 
    // x and y direction, where a knight can move 
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 }; 
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 }; 
  
    // queue for storing states of knight in board 

    Node root(knightPos[0], knightPos[1], 0);
    Tree tree(root);
  
    // push starting position of knight with 0 distance 

    //q.push(Node(knightPos[0], knightPos[1], 0)); 
  
    Node currentNode; 
    int x, y; 
    bool visit[N + 1][N + 1]; 
    bool endGoalReached = false;
  
    // make all cell unvisited 
    for (int i = 1; i <= N; i++) 
        for (int j = 1; j <= N; j++) 
            visit[i][j] = false; 
  
    // visit starting state 
    visit[knightPos[0]][knightPos[1]] = true; 
  
    // loop untill we have one element in queue 
    while (true) { 
        //currentNode = q.front(); 
        //q.pop(); 
        currentNode = tree.nodes[0];

        cout << currentNode.x << endl;
  
        // if current cell is equal to target cell, 
        // return its distance 
        if (currentNode.x == targetPos[0] && currentNode.y == targetPos[1]) 
            return currentNode.distance; 
  
        // loop for all reachable states 
       // for (int i = 0; i < 8; i++) { 
           // x = currentNode.x + dx[i]; 
           // y = currentNode.y + dy[i]; 
  
            // If reachable state is not yet visited and 
            // inside board, push that state into queue 
           // if (isInsideBoard(x, y, N) && !visit[x][y]) { 
             //   visit[x][y] = true; 
              //  tree.add.push(Node(x, y, currentNode.distance + 1)); 
            } 
    

   return -1;
} 
  
// Driver code to test above methods 
int main() { 
    int N = 10; 
    int knightPos[] = { 3, 2 }; 
    int targetPos[] = { 3, 2 }; 
    cout << "Minimum steps: " << minStepToReachTarget(knightPos, targetPos, N) << endl; 
    return 0; 
} 
