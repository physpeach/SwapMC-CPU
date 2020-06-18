#include <iostream>
#include <time.h>

#include "../hpp/conf.hpp"
#include "../hpp/MT.hpp"
#include "../hpp/swapmc.hpp"

int main() {
    init_genrand((unsigned long)time(NULL));
    std::cout << "hello jamming" << std::endl;
    PhysPeach::SwapMC s;
    PhysPeach::createSwapMC(&s);
    while(s.t < 10.){
        PhysPeach::updateSwapMC(&s);
    }
    PhysPeach::readParticles(&s.p, &s.pos);
    
    PhysPeach::deleteSwapMC(&s);
    return 0;
}