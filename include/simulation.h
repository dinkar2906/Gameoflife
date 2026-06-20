#pragma once

#include "grid.h"

class Simulation
{
public:
    void step(Grid& grid);

private:
    int countNeighbors(
        const Grid& grid,
        int row,
        int col
    );
};