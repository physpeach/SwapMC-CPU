#include <iostream>

#include "../hpp/particles.hpp"

int main() {
    std::cout << "hello jamming" << std::endl;
    PhysPeach::Particles p;
    PhysPeach::createParticles(&p);
    PhysPeach::readParticles(&p);
    PhysPeach::deleteParticles(&p);
    return 0;
}