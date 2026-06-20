#include "../include/renderer.h"
#include "../include/constants.h"

Renderer::Renderer(SDL_Renderer* renderer)
    : renderer(renderer)
{
}

void Renderer::drawGrid()
{
    SDL_SetRenderDrawColor(
        renderer,
        200,
        200,
        200,
        255
    );

    for (int x = 0;
         x <= WINDOW_WIDTH;
         x += CELL_SIZE)
    {
        SDL_RenderDrawLine(
            renderer,
            x,
            0,
            x,
            WINDOW_HEIGHT
        );
    }

    for (int y = 0;
         y <= WINDOW_HEIGHT;
         y += CELL_SIZE)
    {
        SDL_RenderDrawLine(
            renderer,
            0,
            y,
            WINDOW_WIDTH,
            y
        );
    }
}

void Renderer::drawCells(const Grid& grid)
{
    SDL_SetRenderDrawColor(
        renderer,
        0,
        0,
        0,
        255
    );

    for(int row = 0; row < ROWS; row++)
    {
        for(int col = 0; col < COLS; col++)
        {
            if(grid.getCell(row, col))
            {
                SDL_Rect cell =
                {
                    col * CELL_SIZE,
                    row * CELL_SIZE,
                    CELL_SIZE,
                    CELL_SIZE
                };

                SDL_RenderFillRect(
                    renderer,
                    &cell
                );
            }
        }
    }
}