#ifndef SWAPMC_HPP
#define SWAPMC_HPP

#include <iostream>
#include <fstream>
#include <math.h>
#include "../hpp/conf.hpp"
#include "../hpp/particles.hpp"
#include "../hpp/cells.hpp"

namespace PhysPeach{
    struct SwapMC {
        double L;
        double T;
        int trial;
        int accept;
        double t; //dt :~ dr / (2. * Np)
        Particles p;
        Cells c;

        std::ofstream trajectory;
        std::ofstream pos;
    };
    void createSwapMC(SwapMC*);
    void deleteSwapMC(SwapMC*);
    void updateSwapMC(SwapMC*);
    void readSwapMC(SwapMC*);
}

#endif