#ifndef CELLS_HPP
#define CELLS_HPP

#include <iostream>
#include "../hpp/params.hpp"

namespace PhysPeach{
    struct Cells{
        int *cell;
        double Lc;
        int Nc;
        int NpC;
    };
    void createCells(Cells*);
    void readCells(Cells*);
    void deleteCells(Cells*);
}
#endif