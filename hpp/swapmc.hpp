#ifndef SWAPMC_HPP
#define SWAPMC_HPP

#include <iostream>
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
    };
    void createSwapMC(SwapMC*);
    void deleteSwapMC(SwapMC*);
    void updateSwapMC(SwapMC*);
}

#endif