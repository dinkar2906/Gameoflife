#pragma once

#include "grid.h"

class LogicGate
{
public:
    static void placeNOT(
        Grid& grid,
        int row,
        int col,
        bool input
    );

    static void placeAND(
        Grid& grid,
        int row,
        int col,
        bool a,
        bool b
    );

    static void placeOR(
        Grid& grid,
        int row,
        int col,
        bool a,
        bool b
    );

    static void placeXOR(
        Grid& grid,
        int row,
        int col,
        bool a,
        bool b
    );

    static void placeNAND(
        Grid& grid,
        int row,
        int col,
        bool a,
        bool b
    );

    static void placeNOR(
        Grid& grid,
        int row,
        int col,
        bool a,
        bool b
    );

    static void placeXNOR(
        Grid& grid,
        int row,
        int col,
        bool a,
        bool b
    );
};