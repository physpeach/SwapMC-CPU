#include "../hpp/particles.hpp"

namespace PhysPeach{
    void createParticles(Particles *p){
        p->dr = 1.;
        p->diam = (double*)malloc(Np * sizeof(double));
        p->x = (double*)malloc(D * Np * sizeof(double));

        p->V = 0;
        for (int i = 0; i < Np; i++){
            p->diam[i] = sqrt(A * a_min * a_min / (A - 2 * a_min * a_min * genrand_real1()));
            p->V += powInt(p->diam[i], D);
            //test
            p->x[i] = i;
            p->x[i+Np] = i;
        }
        p->V *= 0.5 * pi / D;
        return;
    }

    void deleteParticles(Particles *p){
        free(p->diam);
        free(p->x);
        return;
    }
    
    void scatterParticles(Particles *p, double L, int Nc){
        int NcD = powInt(Nc, D);
        int NpC = Np / NcD;
        double Lc = L / (double)Nc;

        for(int i = 0; i < Nc; i++){
            for(int j = 0; j < Nc; j++){
                if(D == 2){
                    for(int m = 0; m < NpC; m++){
                        p->x[(i*Nc+j)*NpC+m] = (i + genrand_real1()) * Lc - 0.5 * L;
                        p->x[(i*Nc+j)*NpC+m+Np] = (j + genrand_real1()) * Lc - 0.5 * L;
                    }
                }
                else if(D == 3){
                    for(int k = 0; k < Nc; k++){
                        for(int m = 0; m < NpC; m++){
                            p->x[((i*Nc+j)*Nc + k)*NpC+m] = (i + genrand_real1()) * Lc - 0.5 * L;
                            p->x[((i*Nc+j)*Nc + k)*NpC+m+Np] = (j + genrand_real1()) * Lc - 0.5 * L;
                            p->x[((i*Nc+j)*Nc + k)*NpC+m+Np] = (k + genrand_real1()) * Lc - 0.5 * L;
                        }
                    }
                }
                else{
                    std::cout << "dimention err" << std::endl;
                    exit(1);
                }
            }
        }
        for(int m = NpC*powInt(Nc,D); m < Np; m++){
            p->x[m] = (genrand_real1() - 0.5 )* L;
            p->x[m+Np] = (genrand_real1() - 0.5) * L;
            if(D == 3){
                p->x[m+2*Np] = (genrand_real1() - 0.5) * L;
            }
        }
        return;
    }

    void swapDiam(Particles* p, int i, int j){
        double tmpdiam = p->diam[i];
        p->diam[i] = p->diam[j];
        p->diam[j] = tmpdiam;
        return;
    }

    void kickParticle(Particles* p, int i, double* rnd){
        for(int d = 0; d < D; d++){
            p->x[i+d*Np] += p->dr * rnd[d];
        }
        return;
    }
}