#include "../hpp/cells.hpp"

namespace PhysPeach{
    int createCells(Cells *c, double L){
        c->Nc = (int)(L/(2. * a_max));
        double buf = 2.3;
        c->NpC = (int)(buf * (double)Np/ (double)powInt(c->Nc, D));
        int NoC = powInt(c->Nc, D)*c->NpC;
        c->cell = (int*)malloc(NoC*sizeof(int));

        //test
        for(int i = 0; i < NoC; i++){
            c->cell[i] = i;
        }
        return c->Nc;
    }
    
    void deleteCells(Cells *c){
        free(c->cell);
        return;
    }
    void updateCells(Cells *c, double L, double* x){
        int i, j, k;
        double Lc = L/(double)c->Nc;
        int NoC = powInt(c->Nc, D)*c->NpC;
        for(int i = 0; i < NoC; i++){
            c->cell[i] = 0;
        }
        for(int n = 0; n < Np; n++){
            i = (x[n] + 0.5 * L)/Lc;
            j = (x[n+Np] + 0.5 * L)/Lc;
            if (D == 2){
                c->cell[(i*c->Nc+j)*c->NpC]++;
                c->cell[(i*c->Nc+j)*c->NpC + c->cell[(i*c->Nc+j)*c->NpC]] = n;
            }else if(D == 3){
                k = (x[n+2*Np] + 0.5 * L)/Lc;
                c->cell[((i*c->Nc+j)*c->Nc + k)*c->NpC]++;
                c->cell[c->cell[((i*c->Nc+j)*c->Nc + k)*c->NpC]];
            }else{
                std::cout << "dimention err" << std::endl;
                    exit(1);
            }
        }
        return;
    }
}