#include "../hpp/cells.hpp"

namespace PhysPeach{
    void createCells(Cells *c){
        //test
        c->Lc = 2.5;
        c->Nc = 1;
        c->NpC = 30;

        c->cell = (int*)malloc(powInt(c->Nc, D)*(c->NpC + 1)*sizeof(int));

        //test
        for(int i = 0; i < powInt(c->Nc, D)*(c->NpC + 1); i++){
            c->cell[i] = i;
        }
        return;
    }

    void readCells(Cells *c){
        for(int i = 0; i < c->Nc*c->Nc*(c->NpC + 1); i++){
            std::cout << i << " " << c->cell[i] << std::endl;
        }
        return;
    }
    
    void deleteCells(Cells *c){
        free(c->cell);
        return;
    }
}