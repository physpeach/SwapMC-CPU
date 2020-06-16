#include <iostream>

#include "../hpp/conf.hpp"
#include "../hpp/swapmc.hpp"

int main() {
    std::cout << "hello jamming" << std::endl;
    PhysPeach::SwapMC s;
    PhysPeach::createSwapMC(&s);
    for (int i = 0; i < Np; i++){
            std::cout << i << " diam: ";
            std::cout << s.p.diam[i] << ", x1: ";
            std::cout << s.p.x[i] << ", x2: ";
            std::cout << s.p.x[i+Np] << std::endl;
        }
    for(int i = 0; i < s.c.Nc*s.c.Nc*(s.c.NpC + 1); i++){
            std::cout << i << " " << s.c.cell[i] << std::endl;
        }
    PhysPeach::deleteSwapMC(&s);
    return 0;
}