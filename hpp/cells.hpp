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
    void createCells(Cells*);
    void deleteCells(Cells*);
}
#endif