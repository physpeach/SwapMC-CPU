#ifndef CELLS_HPP
#define CELLS_HPP

#include <iostream>
#include <stdlib.h>
#include "../hpp/conf.hpp"

namespace PhysPeach{
    struct Cells{
        int *cell;
        int Nc;
        int NpC;
    };
    int createCells(Cells*, double);
    void deleteCells(Cells*);
    void updateCells(Cells*, double, double*);
}
#endif