#ifndef PARTICLES_CUH
#define PARTICLES_CUH

#include <iostream>
#include "../hpp/params.hpp"

namespace PhysPeach{
    struct Particles{
        double *diam;
        double *x;
    };
    void createParticles(Particles*);
    void readParticles(Particles*);
    void deleteParticles(Particles*);
}

#endif