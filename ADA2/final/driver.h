#ifndef DRIVER_H
#define DRIVER_H

#include "tree.h"

int minStepToReachTarget(int boardHeight, int boardWidth, int knightStartPosX, int knightStartPosY, int knightEndPosX, int knightEndPosY){

    unique_ptr<Tree> tree;
    return tree->minStepToReachTargetClass(boardHeight, boardWidth, knightStartPosX, knightStartPosY, knightEndPosX, knightEndPosY);

}

#endif // DRIVER_H
