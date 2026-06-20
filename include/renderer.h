#pragma once

#include <SDL2/SDL.h>
#include "grid.h"

class Renderer
{
public:
    Renderer(SDL_Renderer* renderer);

    void drawGrid();
    void drawCells(const Grid& grid);

private:
    SDL_Renderer* renderer;
};