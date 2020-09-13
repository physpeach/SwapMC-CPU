#include <iostream>
#include <time.h>

#include "../hpp/conf.hpp"
#include "../hpp/MT.hpp"
#include "../hpp/swapmc.hpp"

int Np;
double Phi_init;
int main() {
    Np = 300;
    Phi_init = 0.3;
    init_genrand((unsigned long)time(NULL));

    std::cout << "-- hello jamming --" << std::endl;
    std::cout << "ID   : " << 0 << std::endl;
    std::cout << "Np   : " << Np << std::endl;
    std::cout << "Phi  : " << Phi_init << std::endl;
    std::cout << "Time : " << 10. << std::endl;
    std::cout << "-------------------" << std::endl << std::endl;

    PhysPeach::SwapMC s;
    PhysPeach::createSwapMC(&s, 0);
    while(s.t < 10.){
        PhysPeach::updateSwapMC(&s, 0);
    }
    PhysPeach::readParticles(&s.p, &s.pos);
    
    PhysPeach::deleteSwapMC(&s, 0);
    return 0;
}