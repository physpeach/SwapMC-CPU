#include <iostream>
#include <time.h>

#include "../hpp/conf.hpp"
#include "../hpp/MT.hpp"
#include "../hpp/swapmc.hpp"

//extern
int Np;
double Phi_init;
int main(int argc, char** argv) {
    int ID = atoi(argv[1]);
    init_genrand((unsigned long)time(NULL)*ID + ID);
    Np = atof(argv[2]);
    Phi_init = atof(argv[3]);
    double time = atof(argv[4]);
    
    std::cout << "-- hello jamming --" << std::endl;
    std::cout << "ID   : " << ID << std::endl;
    std::cout << "Np   : " << Np << std::endl;
    std::cout << "Phi  : " << Phi_init << std::endl;
    std::cout << "Time : " << time << std::endl;
    std::cout << "-------------------" << std::endl << std::endl;

    PhysPeach::SwapMC s;
    PhysPeach::createSwapMC(&s, ID);
    while(s.t < time){
        PhysPeach::updateSwapMC(&s, ID);
    }
    PhysPeach::readParticles(&s.p, &s.pos);
    
    PhysPeach::deleteSwapMC(&s, ID);
    return 0;
}