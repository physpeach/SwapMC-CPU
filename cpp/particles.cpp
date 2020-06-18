#include "../hpp/particles.hpp"

namespace PhysPeach{
    void createParticles(Particles *p){
        p->dr = 0.1 * a_max;
        p->diam = (double*)malloc(Np * sizeof(double));
        p->x = (double*)malloc(D * Np * sizeof(double));
        p->mem = (double*)malloc(D * Np * sizeof(double));

        p->V = 0;
        for (int i = 0; i < Np; i++){
            p->diam[i] = sqrt(A * a_min * a_min / (A - 2 * a_min * a_min * genrand_real1()));
            p->V += powInt(p->diam[i], D);
            //test
            p->x[i] = i;
            p->x[i+Np] = i;
        }
        memcpy(p->mem, p->x, D * Np * sizeof(double));
        p->V *= 0.5 * pi / D;
        return;
    }

    void deleteParticles(Particles *p){
        free(p->diam);
        free(p->x);
        free(p->mem);
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
        memcpy(p->mem, p->x, D * Np * sizeof(double));
        return;
    }

    void swapDiam(Particles* p, int i, int j){
        double tmpdiam = p->diam[i];
        p->diam[i] = p->diam[j];
        p->diam[j] = tmpdiam;
        return;
    }

    void kickParticle(Particles* p, int i, double L, double* rnd){
        double Lh = 0.5 * L;
        for(int d = 0; d < D; d++){
            p->x[i+d*Np] += p->dr * rnd[d];
            if(p->x[i+d*Np] > Lh){p->x[i+d*Np] -= L;}
            if(p->x[i+d*Np] < -Lh){p->x[i+d*Np] += L;}
        }
        return;
    }
    void updateDr(Particles* p, double a){
        p->dr *= a;
        return;
    }
    bool updateMem(Particles* p, double L){
        bool result = false;
        double Lh = 0.5 * L;
        double dx;
        double frag = 0.25 * a_max * a_max;
        for(int i = 0; i < D * Np; i++){
            dx = (p->x[i] - p->mem[i]);
            if(dx > Lh){dx -= L;}
            if(dx < -Lh){dx += L;}
            if(dx > frag){
                result = true;
                break;
            }
        }
        if(result){
            memcpy(p->mem, p->x, D * Np * sizeof(double));
        }
        return result;
    }
    void readParticles(Particles* p, std::ofstream* out){
        for(int n = 0; n < Np; n++){
            *out << p->diam[n] << " ";
            for(int d = 0; d < D; d++){
                *out << p->x[n+d*Np] << " ";
            }
            *out << std::endl;
        }
        return;
    }
}