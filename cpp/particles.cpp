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

    void readParticles(Particles *p){
        for (int i = 0; i < Np; i++){
            std::cout << i << " diam: ";
            std::cout << p->diam[i] << ", x1: ";
            std::cout << p->x[i] << ", x2: ";
            std::cout << p->x[i+Np] << std::endl;
        }
        return;
    }

    void deleteParticles(Particles *p){
        free(p->diam);
        free(p->x);
        return;
    }
}