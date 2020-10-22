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
    
    std::cout << "-- hello jamming --" << std::endl;
    std::cout << "ID   : " << ID << std::endl;
    std::cout << "Np   : " << Np << std::endl;
    std::cout << "Phi  : " << Phi_init << std::endl;
    std::cout << "-------------------" << std::endl << std::endl;

    PhysPeach::SwapMC s;
    PhysPeach::createSwapMC(&s, ID);
    PhysPeach::equilibrateSwapMC(&s, 0);

    std::ostringstream fileName;
    fileName << "../pos/pos_N" << Np << "_Phi" << Phi_init << "_id" << ID << ".data";
    std::ofstream file;

    file.open(fileName.str().c_str());
    for(int n = 0; n < Np; n++){
        file << s.p.diam[n] << " ";
        for(int d = 0; d < D; d++){
            file << s.p.x[n+d*Np] << " ";
        }
        file << std::endl;
    }
    file.close();
    PhysPeach::deleteSwapMC(&s, ID);
    return 0;
}