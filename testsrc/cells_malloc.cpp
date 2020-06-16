#include <iostream>
#include <time.h>

#include "../hpp/conf.hpp"
#include "../hpp/MT.hpp"
#include "../hpp/cells.hpp"

int main() {
    init_genrand((unsigned long)time(NULL));
    std::cout << "hello jamming" << std::endl;
    PhysPeach::Cells c;
    PhysPeach::createCells(&c);
    for(int i = 0; i < c.Nc*c.Nc*(c.NpC + 1); i++){
            std::cout << i << " " << c.cell[i] << std::endl;
        }
    PhysPeach::deleteCells(&c);
    return 0;
}