#include "../include/logic_gate.h"

void LogicGate::placeNOT(
    Grid& grid,
    int row,
    int col,
    bool input
)
{
    grid.setCell(row, col, input);

    bool output = !input;

    grid.setCell(
        row,
        col + 5,
        output
    );
}

void LogicGate::placeAND(
    Grid& grid,
    int row,
    int col,
    bool a,
    bool b
)
{
    grid.setCell(row, col, a);
    grid.setCell(row + 2, col, b);

    bool output = a && b;

    grid.setCell(
        row + 1,
        col + 5,
        output
    );
}

void LogicGate::placeOR(
    Grid& grid,
    int row,
    int col,
    bool a,
    bool b
)
{
    grid.setCell(row, col, a);
    grid.setCell(row + 2, col, b);

    bool output = a || b;

    grid.setCell(
        row + 1,
        col + 5,
        output
    );
}

void LogicGate::placeXOR(
    Grid& grid,
    int row,
    int col,
    bool a,
    bool b
)
{
    grid.setCell(row, col, a);
    grid.setCell(row + 2, col, b);

    bool output = a ^ b;

    grid.setCell(
        row + 1,
        col + 5,
        output
    );
}

void LogicGate::placeNAND(
    Grid& grid,
    int row,
    int col,
    bool a,
    bool b
)
{
    grid.setCell(row, col, a);
    grid.setCell(row + 2, col, b);

    bool output = !(a && b);

    grid.setCell(
        row + 1,
        col + 5,
        output
    );
}

void LogicGate::placeNOR(
    Grid& grid,
    int row,
    int col,
    bool a,
    bool b
)
{
    grid.setCell(row, col, a);
    grid.setCell(row + 2, col, b);

    bool output = !(a || b);

    grid.setCell(
        row + 1,
        col + 5,
        output
    );
}

void LogicGate::placeXNOR(
    Grid& grid,
    int row,
    int col,
    bool a,
    bool b
)
{
    grid.setCell(row, col, a);
    grid.setCell(row + 2, col, b);

    bool output = !(a ^ b);

    grid.setCell(
        row + 1,
        col + 5,
        output
    );
}