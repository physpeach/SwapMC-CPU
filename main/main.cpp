#include <iostream>
#include <time.h>

#include "../hpp/conf.hpp"
#include "../hpp/MT.hpp"
#include "../hpp/swapmc.hpp"

//extern
int Np;
double Phi_init;
int main(int argc, char** argv) {
    init_genrand((unsigned long)time(NULL));

    int ID = atoi(argv[1]);
    Np = atof(argv[2]);
    Phi_init = atof(argv[3]);
    double time = atof(argv[4]);
    
    std::cout << "hello jamming" << std::endl;
    PhysPeach::SwapMC s;
    PhysPeach::createSwapMC(&s, ID);
    while(s.t < time){
        PhysPeach::updateSwapMC(&s);
    }
    PhysPeach::readParticles(&s.p, &s.pos);
    
    PhysPeach::deleteSwapMC(&s);
    return 0;
}