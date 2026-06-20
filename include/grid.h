#pragma once

#include <vector>

class Grid
{
public:
    Grid();

    int getCell(int row, int col) const;
    void setCell(int row, int col, int value);

    void placeGlider(int row, int col);

    std::vector<std::vector<int>>& getCells();
    const std::vector<std::vector<int>>& getCells() const;

private:
    std::vector<std::vector<int>> cells;
};