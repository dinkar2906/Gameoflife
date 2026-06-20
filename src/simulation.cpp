#include "../include/simulation.h"
#include "../include/constants.h"

int Simulation::countNeighbors(
    const Grid& grid,
    int row,
    int col
)
{
    int neighbors = 0;

    for(int dr = -1; dr <= 1; dr++)
    {
        for(int dc = -1; dc <= 1; dc++)
        {
            if(dr == 0 && dc == 0)
                continue;

            int r = row + dr;
            int c = col + dc;

            if(r >= 0 &&
               r < ROWS &&
               c >= 0 &&
               c < COLS)
            {
                neighbors += grid.getCell(r, c);
            }
        }
    }

    return neighbors;
}

void Simulation::step(Grid& grid)
{
    auto oldGrid = grid.getCells();
    auto newGrid = oldGrid;

    for(int row = 0; row < ROWS; row++)
    {
        for(int col = 0; col < COLS; col++)
        {
            int alive =
                oldGrid[row][col];

            int neighbors =
                countNeighbors(
                    grid,
                    row,
                    col
                );

            if(alive)
            {
                if(neighbors < 2 ||
                   neighbors > 3)
                {
                    newGrid[row][col] = 0;
                }
            }
            else
            {
                if(neighbors == 3)
                {
                    newGrid[row][col] = 1;
                }
            }
        }
    }

    grid.getCells() = newGrid;
}