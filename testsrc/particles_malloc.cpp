#include <iostream>

#include "../hpp/conf.hpp"
#include "../hpp/particles.hpp"

int main() {
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