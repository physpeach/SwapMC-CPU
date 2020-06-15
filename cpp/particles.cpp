#include "../hpp/particles.hpp"

namespace PhysPeach{
    void createParticles(Particles *p){
        p->diam = (double*)malloc(Np * sizeof(double));
        p->x = (double*)malloc(D * Np * sizeof(double));

        //test
        for (int i = 0; i < Np; i++){
            p->diam[i] = i;
            p->x[i] = i;
            p->x[i+Np] = i;
        }
        return;
    }

    void deleteParticles(Particles *p){
        free(p->diam);
        free(p->x);
        return;
    }
}