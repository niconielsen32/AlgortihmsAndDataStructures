#ifndef DRIVER_H
#define DRIVER_H

#include "tree.h"

int MinimumSteps(int BoardHeight, int BoardWidth, int KnightStartXPosition, int knightStartYPosition, int knightEndXPosition, int knightEndYPosition){

    unique_ptr<Tree> tree;
    return tree->minStepToReachTargetClass(BoardHeight, BoardWidth, KnightStartXPosition, knightStartYPosition, knightEndXPosition, knightEndYPosition);

}

#endif // DRIVER_H
