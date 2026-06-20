#include "../include/grid.h"
#include "../include/constants.h"

Grid::Grid()
{
    cells.resize(
        ROWS,
        std::vector<int>(COLS, 0)
    );
}

int Grid::getCell(int row, int col) const
{
    return cells[row][col];
}

void Grid::setCell(int row, int col, int value)
{
    cells[row][col] = value;
}

void Grid::placeGlider(int row, int col)
{
    cells[row][col + 1] = 1;
    cells[row + 1][col + 2] = 1;

    cells[row + 2][col] = 1;
    cells[row + 2][col + 1] = 1;
    cells[row + 2][col + 2] = 1;
}

std::vector<std::vector<int>>& Grid::getCells()
{
    return cells;
}

const std::vector<std::vector<int>>& Grid::getCells() const
{
    return cells;
}