#include <iostream>
#include <fstream>
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
    std::cout << "-------------------" << std::endl << std::endl;

    PhysPeach::SwapMC s;
    PhysPeach::createSwapMC(&s, 0);
    PhysPeach::equilibrateSwapMC(&s, 0);

    std::ostringstream fileName;
    fileName << "../pos/pos_N" << Np << "_Phi" << Phi_init << "_id" << 0 << ".data";
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
    
    PhysPeach::deleteSwapMC(&s, 0);
    return 0;
}