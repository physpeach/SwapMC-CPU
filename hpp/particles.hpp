#ifndef PARTICLES_CUH
#define PARTICLES_CUH

#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>
#include "../hpp/MT.hpp"
#include "../hpp/conf.hpp"

namespace PhysPeach{
    struct Particles{
        double *diam;
        double V;
        double *x;
        double *mem;
        double dr;
    };
    void createParticles(Particles*);
    void deleteParticles(Particles*);
    void scatterParticles(Particles*, double, int);
    void swapDiam(Particles*, int, int);
    void kickParticle(Particles*, int, double, double*);
    void updateDr(Particles*, double);
    bool updateMem(Particles*, double);
    void readParticles(Particles*, std::ofstream*);
}

#endif