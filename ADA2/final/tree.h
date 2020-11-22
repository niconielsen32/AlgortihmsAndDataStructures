#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include <memory>

#include <node.h>

using namespace std;

class Tree{

public:

    vector<shared_ptr<Node> > nodes;

    Tree(){}

    void addNode(shared_ptr<Node> child){
        nodes.push_back(child);
    }


    // Utility method returns true if (x, y) lies
    // inside Board
    bool isInsideBoard(int x, int y, int N)
    {
        if (x >= 0 && x < N && y >= 0 && y < N)
            return true;
        return false;
    }



    // Method returns minimum step
    // to reach target position
    int minStepToReachTargetClass(int boardHeight, int boardWidth, int knightStartPosX, int knightStartPosY, int knightEndPosX, int knightEndPosY)
    {



        if(!isInsideBoard(knightStartPosX, knightStartPosY, boardHeight) || !isInsideBoard(knightEndPosX, knightEndPosY, boardHeight) ){
            cout << "Position not inside board" << endl;
        }

        // x and y direction, where a knight can move
        int dx[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
        int dy[] = { -1, 1, 1, -1, 2, -2, 2, -2 };

        // queue for storing states of knight in board

        shared_ptr<Node> root(new Node(knightStartPosX, knightStartPosY, 0));

        shared_ptr<Tree> tree(new Tree);

        // push starting position of knight with 0 distance

        shared_ptr<Node> currentNode;
        int x, y;
        bool visit[boardHeight + 1][boardHeight + 1];
        bool endGoalReached = false;

        // make all cell unvisited
        for (int i = 1; i <= boardHeight; i++)
            for (int j = 1; j <= boardHeight; j++)
                visit[i][j] = false;

        // visit starting state
        visit[root->x][root->y] = true;

        const int numberOfPossibleMoves = 8;
        int nodeNumber = 0;

        currentNode = root;

        while(!endGoalReached) {

            // if current cell is equal to target cell,
            // return its distance
            if (currentNode->x == knightEndPosX && currentNode->y == knightEndPosY){
                //delete[] visit;
                return currentNode->distance;
            }

            // loop for all reachable states
            for (int i = 0; i < numberOfPossibleMoves; i++) {
                x = currentNode->x + dx[i];
                y = currentNode->y + dy[i];

                // If reachable state is not yet visited and
                // inside board, push that state into queue
                if (isInsideBoard(x, y, boardHeight) && !visit[x][y]) {
                    visit[x][y] = true;
                    shared_ptr<Node> newNode(new Node(x, y, currentNode->distance + 1));
                    tree->addNode(newNode);
                }
            }

            currentNode = tree->nodes[nodeNumber++];

        }

       //delete[] visit;
       return -1;
    }

};

#endif // TREE_H
