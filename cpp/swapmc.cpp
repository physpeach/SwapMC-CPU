#include "../hpp/swapmc.hpp"

namespace PhysPeach {
    double Upartial(SwapMC* s, int n){
        int m;
        double xij[D], rij, rij2, aij;
        int ic, jc, kc;
        int list;
        double U = 0;
        double Lh = 0.5 * s->L;
        double Lc = s->L / s->c.Nc;

        ic = (s->p.x[n] + Lh)/Lc;
        jc = (s->p.x[n+Np] + Lh)/Lc;
        kc = 0;
        if(D == 3){
            kc = (s->p.x[n+Np] + Lh)/Lc;
        }

        for(int i = ic - 1; i < ic + 1; i++){
            for(int j = jc - 1; j < jc + 1; j++){
                if(D == 2){
                    list = (((i+s->c.Nc)%s->c.Nc)*s->c.Nc+((j+s->c.Nc)%s->c.Nc))*s->c.NpC;
                    for(int l = 1; l <= s->c.cell[list]; l++){
                        m = s->c.cell[list+l];
                        if(n != m){
                            xij[0] = s->p.x[j] - s->p.x[i];
                            xij[1] = s->p.x[Np+j] - s->p.x[Np+i];
                            if(xij[0] > Lh){xij[0] -= s->L;}
                            if(xij[1] > Lh){xij[1] -= s->L;}
                            if(xij[0] < -Lh){xij[0] += s->L;}
                            if(xij[1] < -Lh){xij[1] += s->L;}
                            rij2 = xij[0]*xij[0] + xij[1]*xij[1];
                            aij = 0.5 * (s->p.diam[i] + s->p.diam[j]);
                            if(rij2 < aij * aij){
                                rij = sqrt(rij2);
                                U += 0.5 * (1 - rij/aij) * (1 - rij/aij);
                            }
                        }
                    }
                }else if (D == 3){
                    for(int k = kc - 1; k < kc + 1; k++){
                        list = ((((i+s->c.Nc)%s->c.Nc)*s->c.Nc+((j+s->c.Nc)%s->c.Nc))*s->c.Nc + ((k+s->c.Nc)%s->c.Nc))*s->c.NpC;
                        for(int l = 1; l <= s->c.cell[list]; l++){
                            m = s->c.cell[list+l];
                            if(n != m){
                                xij[0] = s->p.x[j] - s->p.x[i];
                                xij[1] = s->p.x[Np+j] - s->p.x[Np+i];
                                xij[2] = s->p.x[2*Np+j] - s->p.x[2*Np+i];
                                if(xij[0] > Lh){xij[0] -= s->L;}
                                if(xij[1] > Lh){xij[1] -= s->L;}
                                if(xij[2] > Lh){xij[2] -= s->L;}
                                if(xij[0] < -Lh){xij[0] += s->L;}
                                if(xij[1] < -Lh){xij[1] += s->L;}
                                if(xij[2] < -Lh){xij[2] += s->L;}
                                rij2 = xij[0]*xij[0] + xij[1]*xij[1] + xij[2]*xij[2];
                                aij = 0.5 * (s->p.diam[i] + s->p.diam[j]);
                                if(rij2 < aij * aij){
                                    rij = sqrt(rij2);
                                    U += 0.5 * (1 - rij/aij) * (1 - rij/aij);
                                }
                            }
                        }
                    }
                } else{
                    std::cout << "dimention err" << std::endl;
                    exit(1);
                }
            }
        }

        return U;
    }
    void createSwapMC(SwapMC* s){
        s->T = T;
        s->trial = 0;
        s->accept = 0;
        s->t = 0.;
        s->trajectory.open("test.txt");
        s->pos.open("last.txt");

        createParticles(&s->p);
        s->L = pow(s->p.V/Phi_init, 1./(double)D);
        scatterParticles(&s->p, s->L, createCells(&s->c, s->L));
        updateCells(&s->c, s->L, s->p.x);
        return;
    }

    void deleteSwapMC(SwapMC* s){
        s->trajectory.close();
        s->pos.close();
        deleteParticles(&s->p);
        deleteCells(&s->c);
        return;
    }

    void updateSwapMC(SwapMC* s){
        readSwapMC(s);

        double Up, Uptry;
        double judge;

        static int count = 0;
        static int kick = 0;

        int i = genrand_int32()%Np;
        Up = Upartial(s, i);

        //swap algorithm
        bool swap = (genrand_real1() < 0.2);
        if (swap) {
            //swap diam case
            int j = i;
            while(j == i){
                j = genrand_int32()%Np;
            }
            Up += Upartial(s, j);
            swapDiam(&s->p, i, j);
            Uptry = Upartial(s, i) + Upartial(s, j);

            judge = exp(-(Uptry - Up)/T);
            if(judge < genrand_real2()){
                //reject
                swapDiam(&s->p, i, j);
            }else{
                s->accept++;
            }
        }else{
            //kick a particle case
            double rnd[D], rndlen2;
            rndlen2 = 2;
            while (rndlen2 > 1){
                rndlen2 = 0;
                for(int d = 0; d < D; d++){
                    rnd[d] = genrand_real1();
                    rndlen2 += rnd[d] * rnd[d];
                }
            }
            kickParticle(&s->p, i, s->L, rnd);
            Uptry = Upartial(s, i);

            judge = exp(-(Uptry - Up)/T);
            count++;
            if(judge < genrand_real2()){
                //reject
                for(int d = 0; d < D; d++){
                    rnd[d] = -rnd[d];
                }
                kickParticle(&s->p, i, s->L, rnd);
            }else{
                s->accept++;
                s->t += s->p.dr / (2. * (double)Np);
                kick++;
            }
        }
        s->trial++;

        // should be ac/rj -> 1
        if(count == 100){
            if(kick > 55){
                updateDr(&s->p, 1.1);
            }else if(kick < 45){
                updateDr(&s->p, 0.7);
            }
            count = 0;
            kick = 0;
        }

        bool mustUpdateCells = updateMem(&s->p, s->L);
        if(mustUpdateCells){
            updateCells(&s->c, s->L, s->p.x);
        }
        return;
    }
    void readSwapMC(SwapMC* s){
        static double nexttime = 0;
        if (s->t >= nexttime){
            s->trajectory << s->t << " ";
            for(int n = 0; n < Np; n++){
                s->trajectory << s->p.diam[n] << " ";
                    for(int d = 0; d < D; d++){
                        s->trajectory << s->p.x[n+d*Np] << " ";
                    }
            }
            s->trajectory << std::endl;
            nexttime += 0.1;
        }
        return;
    }
}