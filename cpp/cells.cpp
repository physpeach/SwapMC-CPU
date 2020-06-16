#include "../hpp/cells.hpp"

namespace PhysPeach{
    void createCells(Cells *c, double L){
        c->Nc = (int)(L/(2. * a_max));
        c->Lc = L/(double)c->Nc;
        double buf = 2.3;
        c->NpC = (int)(buf * (double)Np/ (double)powInt(c->Nc, D));
        double NoA = powInt(c->Nc, D)*(c->NpC + 1);
        c->cell = (int*)malloc(NoA*sizeof(int));

        //test
        for(int i = 0; i < NoA; i++){
            c->cell[i] = i;
        }
        return;
    }
    
    void deleteCells(Cells *c){
        free(c->cell);
        return;
    }
}