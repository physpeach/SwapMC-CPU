#ifndef SWAPMC_HPP
#define SWAPMC_HPP

#include <iostream>
#include "../hpp/conf.hpp"
#include "../hpp/particles.hpp"
#include "../hpp/cells.hpp"

namespace PhysPeach{
    struct SwapMC {
        Particles p;
        Cells c;
    };
    void createSwapMC(SwapMC*);
    void deleteSwapMC(SwapMC*);
}

#endif