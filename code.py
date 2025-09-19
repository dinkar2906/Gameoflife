import pygame
import sys
import random

CELL_SIZE = 40
ROWS = 10
COLS = 10
WIDTH = COLS * CELL_SIZE
HEIGHT = ROWS * CELL_SIZE

WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
GRID_COLOR = (200, 200, 200)

def create_grid(randomize=False):
    grid = []
    for _ in range(ROWS):
        row = []
        for _ in range(COLS):
            if randomize:
                row.append(random.randint(0, 1)) 
            else:
                row.append(0) 
        grid.append(row)
    return grid

def draw_grid(screen, grid):
    screen.fill(WHITE)
    for r in range(ROWS):
        for c in range(COLS):
            if grid[r][c] == 1:
                pygame.draw.rect(
                    screen, BLACK,
                    (c * CELL_SIZE, r * CELL_SIZE, CELL_SIZE, CELL_SIZE)
                )
            pygame.draw.rect(
                screen, GRID_COLOR,
                (c * CELL_SIZE, r * CELL_SIZE, CELL_SIZE, CELL_SIZE), 1
            )
    pygame.display.flip()

def count_neighbors(grid, r, c):
    neighbors = 0
    for dr in (-1, 0, 1):
        for dc in (-1, 0, 1):
            if dr == 0 and dc == 0:
                continue
            rr, cc = r + dr, c + dc
            if 0 <= rr < ROWS and 0 <= cc < COLS:
                neighbors += grid[rr][cc]
    return neighbors

def next_generation(grid):
    new_grid = [[0] * COLS for _ in range(ROWS)]
    for r in range(ROWS):
        for c in range(COLS):
            alive = grid[r][c]
            neighbors = count_neighbors(grid, r, c)
            if alive and neighbors in (2, 3):
                new_grid[r][c] = 1
            elif not alive and neighbors == 3:
                new_grid[r][c] = 1
    return new_grid

def main():
    pygame.init()
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption("Conway's Game of Life")
    clock = pygame.time.Clock()

    grid = create_grid()
    running = False

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE:
                    running = not running   
                elif event.key == pygame.K_c:
                    grid = create_grid(False)   
                elif event.key == pygame.K_r:
                    grid = create_grid(True)   

            elif event.type == pygame.MOUSEBUTTONDOWN and not running:
                x, y = pygame.mouse.get_pos()
                col = x // CELL_SIZE
                row = y // CELL_SIZE
                grid[row][col] = 1 - grid[row][col]  

        if running:
            grid = next_generation(grid)

        draw_grid(screen, grid)
        clock.tick(10)  # 10 FPS

if __name__ == "__main__":
    main()
