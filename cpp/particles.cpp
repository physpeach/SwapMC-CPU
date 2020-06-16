#include "../hpp/particles.hpp"

namespace PhysPeach{
    void createParticles(Particles *p){
        p->diam = (double*)malloc(Np * sizeof(double));
        p->x = (double*)malloc(D * Np * sizeof(double));

        p->V = 0;
        for (int i = 0; i < Np; i++){
            p->diam[i] = sqrt(A * a_min * a_min / (A - 2 * a_min * a_min * genrand_real1()));
            p->V += powInt(p->diam[i], D);
            //test
            p->x[i] = i;
            p->x[i+Np] = i;
        }
        p->V *= 0.5 * pi / D;
        return;
    }

    void deleteParticles(Particles *p){
        free(p->diam);
        free(p->x);
        return;
    }
}