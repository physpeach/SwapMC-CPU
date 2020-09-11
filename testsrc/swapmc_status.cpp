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
    std::cout << "hello jamming" << std::endl;
    PhysPeach::SwapMC s;
    PhysPeach::createSwapMC(&s, 0);
    for(int i = 0; i < 100; i++){
        PhysPeach::updateSwapMC(&s);
    }
    for (int i = 0; i < Np; i++){
            std::cout << i << " diam: ";
            std::cout << s.p.diam[i] << ", x1: ";
            std::cout << s.p.x[i] << ", x2: ";
            if(D == 2){
                 std::cout << s.p.x[i+Np] << std::endl;
            }
            else if(D == 3){
                std::cout << s.p.x[i+Np] << ", x3: ";
                 std::cout << s.p.x[i+2*Np] << std::endl;
            }
        }
    int NoC = PhysPeach::powInt(s.c.Nc, D)*s.c.NpC;
    for(int i = 0; i < NoC; i++){
            std::cout << i << " " << s.c.cell[i] << std::endl;
        }
    std::cout << "box length: " << s.L << std::endl;
    PhysPeach::deleteSwapMC(&s);
    return 0;
}