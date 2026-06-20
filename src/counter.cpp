#include "../include/counter.h"

Counter::Counter()
    : value(0)
{
}

void Counter::update()
{
    value = (value + 1) % 16;
}

void Counter::draw(Grid& grid)
{
    int row = 5;
    int col = 5;

    for(int i = 0; i < 4; i++)
    {
        int bit = (value >> i) & 1;

        grid.setCell(
            row,
            col + i * 3,
            bit
        );
    }
}