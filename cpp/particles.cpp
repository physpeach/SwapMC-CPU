#include "../hpp/particles.hpp"

namespace PhysPeach{
    void createParticles(Particles *p){
        p->diam = (double*)malloc(Np * sizeof(double));
        p->x = (double*)malloc(D * Np * sizeof(double));

        for (int i = 0; i < Np; i++){
            p->diam[i] = sqrt(A * a_min * a_min / (A - 2 * a_min * a_min * genrand_real1()));
            //test
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