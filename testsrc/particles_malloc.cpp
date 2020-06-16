#include <iostream>
#include <time.h>

#include "../hpp/conf.hpp"
#include "../hpp/MT.hpp"
#include "../hpp/particles.hpp"

int main() {
    init_genrand((unsigned long)time(NULL));
    std::cout << "hello jamming" << std::endl;
    PhysPeach::Particles p;
    PhysPeach::createParticles(&p);
    for (int i = 0; i < Np; i++){
            std::cout << i << " diam: ";
            std::cout << p.diam[i] << ", x1: ";
            std::cout << p.x[i] << ", x2: ";
            std::cout << p.x[i+Np] << std::endl;
        }
    PhysPeach::deleteParticles(&p);
    return 0;
}