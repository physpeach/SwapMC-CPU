#include <iostream>
#include <time.h>

#include "../hpp/conf.hpp"
#include "../hpp/MT.hpp"
#include "../hpp/cells.hpp"

int Np;
double Phi_init;
int main() {
    Np = 300;
    Phi_init = 0.3;
    init_genrand((unsigned long)time(NULL));
    std::cout << "hello jamming" << std::endl;
    PhysPeach::Cells c;
    double L = 30.;
    PhysPeach::createCells(&c, L);
    int NoC = (c.NpC + 1) * PhysPeach::powInt(c.Nc, D);
    for(int i = 0; i < NoC; i++){
            std::cout << i << " " << c.cell[i] << std::endl;
        }
    std::cout << "Nc: " << c.Nc << std::endl;
    std::cout << "Lc: " << L/c.Nc << " > " << 2. * a_max << std::endl;
    std::cout << "NpC: " << c.NpC << std::endl;
    PhysPeach::deleteCells(&c, 0);
    return 0;
}