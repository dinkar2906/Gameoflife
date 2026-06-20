#include "../include/application.h"
#include "../include/constants.h"
#include "../include/renderer.h"
#include "../include/grid.h"
#include "../include/simulation.h"

#include <SDL2/SDL.h>

void Application::run()
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window =
        SDL_CreateWindow(
            "Gosper Glider Gun",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            WINDOW_WIDTH,
            WINDOW_HEIGHT,
            SDL_WINDOW_SHOWN
        );

    SDL_Renderer* renderer =
        SDL_CreateRenderer(
            window,
            -1,
            SDL_RENDERER_ACCELERATED
        );

    Grid grid;

    grid.setCell(5, 25, 1);

    grid.setCell(6, 23, 1);
    grid.setCell(6, 25, 1);

    grid.setCell(7, 13, 1);
    grid.setCell(7, 14, 1);
    grid.setCell(7, 21, 1);
    grid.setCell(7, 22, 1);
    grid.setCell(7, 35, 1);
    grid.setCell(7, 36, 1);

    grid.setCell(8, 12, 1);
    grid.setCell(8, 16, 1);
    grid.setCell(8, 21, 1);
    grid.setCell(8, 22, 1);
    grid.setCell(8, 35, 1);
    grid.setCell(8, 36, 1);

    grid.setCell(9, 1, 1);
    grid.setCell(9, 2, 1);
    grid.setCell(9, 11, 1);
    grid.setCell(9, 17, 1);
    grid.setCell(9, 21, 1);
    grid.setCell(9, 22, 1);

    grid.setCell(10, 1, 1);
    grid.setCell(10, 2, 1);
    grid.setCell(10, 11, 1);
    grid.setCell(10, 15, 1);
    grid.setCell(10, 17, 1);
    grid.setCell(10, 18, 1);
    grid.setCell(10, 23, 1);
    grid.setCell(10, 25, 1);

    grid.setCell(11, 11, 1);
    grid.setCell(11, 17, 1);
    grid.setCell(11, 25, 1);

    grid.setCell(12, 12, 1);
    grid.setCell(12, 16, 1);

    grid.setCell(13, 13, 1);
    grid.setCell(13, 14, 1);

    Simulation simulation;

    Renderer gameRenderer(renderer);

    bool running = true;

    while (running)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }

        simulation.step(grid);

        SDL_SetRenderDrawColor(
            renderer,
            255,
            255,
            255,
            255
        );

        SDL_RenderClear(renderer);

        gameRenderer.drawCells(grid);
        gameRenderer.drawGrid();

        SDL_RenderPresent(renderer);

        SDL_Delay(50);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}