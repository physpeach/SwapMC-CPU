#ifndef SWAPMC_HPP
#define SWAPMC_HPP

#include <iostream>
#include <math.h>
#include "../hpp/conf.hpp"
#include "../hpp/particles.hpp"
#include "../hpp/cells.hpp"

namespace PhysPeach{
    struct SwapMC {
        Particles p;
        Cells c;
        double L;
    };
    void createSwapMC(SwapMC*);
    void deleteSwapMC(SwapMC*);
}

#endif