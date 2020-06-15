#include <iostream>

#include "../hpp/cells.hpp"
#include "../hpp/particles.hpp"

int main() {
    std::cout << "hello jamming" << std::endl;
    PhysPeach::Particles p;
    PhysPeach::createParticles(&p);
    PhysPeach::readParticles(&p);
    PhysPeach::deleteParticles(&p);

    PhysPeach::Cells c;
    PhysPeach::createCells(&c);
    PhysPeach::readCells(&c);
    PhysPeach::deleteCells(&c);
    return 0;
}