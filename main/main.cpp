#include <iostream>
#include <time.h>

#include "../hpp/cells.hpp"
#include "../hpp/MT.hpp"
#include "../hpp/particles.hpp"

int main() {
    init_genrand((unsigned long)time(NULL));
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