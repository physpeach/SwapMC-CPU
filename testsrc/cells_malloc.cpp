#include <iostream>

#include "../hpp/conf.hpp"
#include "../hpp/cells.hpp"

int main() {
    std::cout << "hello jamming" << std::endl;
    PhysPeach::Cells c;
    PhysPeach::createCells(&c);
    for(int i = 0; i < c.Nc*c.Nc*(c.NpC + 1); i++){
            std::cout << i << " " << c.cell[i] << std::endl;
        }
    PhysPeach::deleteCells(&c);
    return 0;
}