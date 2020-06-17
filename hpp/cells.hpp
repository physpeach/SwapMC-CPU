#ifndef CELLS_HPP
#define CELLS_HPP

#include <iostream>
#include "../hpp/conf.hpp"

namespace PhysPeach{
    struct Cells{
        int *cell;
        double Lc;
        int Nc;
        int NpC;
    };
    int createCells(Cells*, double);
    void deleteCells(Cells*);
}
#endif