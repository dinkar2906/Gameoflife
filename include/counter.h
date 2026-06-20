#pragma once

#include "grid.h"

class Counter
{
public:
    Counter();

    void update();
    void draw(Grid& grid);

private:
    int value;
};