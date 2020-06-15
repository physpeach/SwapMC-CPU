#include "../hpp/particles.hpp"

namespace PhysPeach{
    void createParticles(Particles *p){
        p->diam = (double*)malloc(NP * sizeof(double));
        p->x = (double*)malloc(D * NP * sizeof(double));

        //test
        for (int i = 0; i < NP; i++){
            p->diam[i] = i;
            p->x[i] = i;
            p->x[i+NP] = i;
            p->x[i+2*NP] = i;
        }
        return;
    }

    void readParticles(Particles *p){
        for (int i = 0; i < NP; i++){
            std::cout << i << " diam: ";
            std::cout << p->diam[i] << ", x1: ";
            std::cout << p->x[i] << ", x2: ";
            std::cout << p->x[i+NP] << ", x3: ";
            std::cout << p->x[i+2*NP] << std::endl;
        }
        return;
    }

    void deleteParticles(Particles *p){
        free(p->diam);
        free(p->x);
        return;
    }
}