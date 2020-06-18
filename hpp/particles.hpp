#ifndef PARTICLES_CUH
#define PARTICLES_CUH

#include <iostream>
#include <math.h>
#include "../hpp/MT.hpp"
#include "../hpp/conf.hpp"

namespace PhysPeach{
    struct Particles{
        double *diam;
        double V;
        double *x;
        double dr;
    };
    void createParticles(Particles*);
    void deleteParticles(Particles*);
    void scatterParticles(Particles*, double, int);
    void swapDiam(Particles*, int, int);
    void kickParticle(Particles*, int, double*);
    void updateDr(Particles*, double);
}

#endif