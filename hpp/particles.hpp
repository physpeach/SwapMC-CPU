#ifndef PARTICLES_CUH
#define PARTICLES_CUH

#include <iostream>
#include "../hpp/conf.hpp"

namespace PhysPeach{
    struct Particles{
        double *diam;
        double *x;
    };
    void createParticles(Particles*);
    void deleteParticles(Particles*);
}

#endif