#include "../hpp/swapmc.hpp"

namespace PhysPeach {
    double Upartial(SwapMC* s, int i){
        int j;
        double xij[D], rij, rij2, aij;
        int oc, pc, qc;
        int list;
        double U = 0;
        double Lh = 0.5 * s->L;
        double Lc = s->L / s->c.Nc;

        oc = (s->p.x[i] + Lh)/Lc;
        pc = (s->p.x[i+Np] + Lh)/Lc;
        qc = 0;
        if(D == 3){
            qc = (s->p.x[i+Np] + Lh)/Lc;
        }

        for(int o = oc - 1; o <= oc + 1; o++){
            for(int p = pc - 1; p <= pc + 1; p++){
                if(D == 2){
                    list = (((o+s->c.Nc)%s->c.Nc)*s->c.Nc+((p+s->c.Nc)%s->c.Nc))*s->c.NpC;
                    for(int l = 1; l <= s->c.cell[list]; l++){
                        j = s->c.cell[list+l];
                        if(i != j){
                            xij[0] = s->p.x[j] - s->p.x[i];
                            xij[1] = s->p.x[Np+j] - s->p.x[Np+i];
                            if(xij[0] > Lh){xij[0] -= s->L;}
                            if(xij[1] > Lh){xij[1] -= s->L;}
                            if(xij[0] < -Lh){xij[0] += s->L;}
                            if(xij[1] < -Lh){xij[1] += s->L;}
                            rij2 = xij[0]*xij[0] + xij[1]*xij[1];
                            aij = 0.5 * (s->p.diam[j] + s->p.diam[i]);
                            if(rij2 < aij * aij){
                                rij = sqrt(rij2);
                                U += 0.5 * (1 - rij/aij) * (1 - rij/aij);
                            }
                        }
                    }
                }else if (D == 3){
                    for(int q = qc - 1; q <= qc + 1; q++){
                        list = ((((o+s->c.Nc)%s->c.Nc)*s->c.Nc+((p+s->c.Nc)%s->c.Nc))*s->c.Nc + ((q+s->c.Nc)%s->c.Nc))*s->c.NpC;
                        for(int l = 1; l <= s->c.cell[list]; l++){
                            j = s->c.cell[list+l];
                            if(i != j){
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
                                aij = 0.5 * (s->p.diam[j] + s->p.diam[i]);
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

    double U(SwapMC* s){
        int j;
        double xij[D], rij, rij2, aij;
        int oc, pc, qc;
        int list;
        double U = 0;
        double Lh = 0.5 * s->L;
        double Lc = s->L / s->c.Nc;
        
        for(int i = 0; i < Np; i++){
            oc = (s->p.x[i] + Lh)/Lc;
            pc = (s->p.x[i+Np] + Lh)/Lc;
            qc = 0;
            if(D == 3){
                qc = (s->p.x[i+Np] + Lh)/Lc;
            }
            for(int o = oc - 1; o <= oc + 1; o++){
                for(int p = pc - 1; p <= pc + 1; p++){
                    if(D == 2){
                        list = (((o+s->c.Nc)%s->c.Nc)*s->c.Nc+((p+s->c.Nc)%s->c.Nc))*s->c.NpC;
                        for(int l = 1; l <= s->c.cell[list]; l++){
                            j = s->c.cell[list+l];
                            if(i < j){
                                xij[0] = s->p.x[j] - s->p.x[i];
                                xij[1] = s->p.x[Np+j] - s->p.x[Np+i];
                                if(xij[0] > Lh){xij[0] -= s->L;}
                                if(xij[1] > Lh){xij[1] -= s->L;}
                                if(xij[0] < -Lh){xij[0] += s->L;}
                                if(xij[1] < -Lh){xij[1] += s->L;}
                                rij2 = xij[0]*xij[0] + xij[1]*xij[1];
                                aij = 0.5 * (s->p.diam[j] + s->p.diam[i]);
                                if(rij2 < aij * aij){
                                    rij = sqrt(rij2);
                                    U += 0.5 * (1 - rij/aij) * (1 - rij/aij);
                                }
                            }
                        }
                    }else if(D == 3){
                        for(int q = qc - 1; q <= qc + 1; q++){
                            list = ((((o+s->c.Nc)%s->c.Nc)*s->c.Nc+((p+s->c.Nc)%s->c.Nc))*s->c.Nc + ((q+s->c.Nc)%s->c.Nc))*s->c.NpC;
                            for(int l = 1; l <= s->c.cell[list]; l++){
                                j = s->c.cell[list+l];
                                if(i < j){
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
                                    aij = 0.5 * (s->p.diam[j] + s->p.diam[i]);
                                    if(rij2 < aij * aij){
                                        rij = sqrt(rij2);
                                        U += 0.5 * (1 - rij/aij) * (1 - rij/aij);
                                    }
                                }
                            }
                        }
                    }else{
                        std::cout << "dimention err" << std::endl;
                        exit(1);
                    }
                }
            }
        }
        return U;
    }
    void createSwapMC(SwapMC* s, int id){
        s->T = T;
        s->t = 0.;
        createParticles(&s->p);
        s->L = pow(s->p.V/Phi_init, 1./(double)D);
        scatterParticles(&s->p, s->L, createCells(&s->c, s->L));
        updateCells(&s->c, s->L, s->p.x);
        return;
    }

    void deleteSwapMC(SwapMC* s, int id){
        deleteParticles(&s->p);
        deleteCells(&s->c);
        return;
    }

    int updateSwapMC(SwapMC* s, int id){

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
            }
        }else{
            //kick a particle case
            double rnd[D], rndlen2;
            rndlen2 = 2;
            while (rndlen2 > 1){
                rndlen2 = 0;
                for(int d = 0; d < D; d++){
                    rnd[d] = 2. * genrand_real1() - 1.;
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
                s->t += s->p.dr / (2. * (double)Np);
                kick++;
            }
        }

        // should be ac/rj -> 0.23
        if(count == 2*Np){
            if(kick > 2*Np * 26/100){
                updateDr(&s->p, 1.1);
            }else if(kick < 2*Np * 19/100){
                updateDr(&s->p, 0.8);
            }
            count = 0;
            kick = 0;
        }

        bool mustUpdateCells = updateMem(&s->p, s->L);
        if(mustUpdateCells){
            updateCells(&s->c, s->L, s->p.x);
        }
        return i;
    }

    void equilibrateSwapMC(SwapMC* s, int id){

        double Fs = 1.;
        double *fs;
        double fs1;
        fs = (double*)malloc(Np*sizeof(double));

        double *x0;
        x0 = (double*)malloc(D*Np*sizeof(double));

        double k = 2 * pi / 1.; //aav = 1
        int q1 = (int)(k * s->L / (2. * pi));
        double k1 = 2 * pi*q1 / s->L;
        double k2 = 2 * pi*(q1 + 1) / s->L;

        if ((k - k1) <= (k2 - k)){ k = k1;}
        else{ k = k2;}

        while(s->t < 10.){
            updateSwapMC(s, id);
        }
        s->t = 0.;

        int n;
        double dx[D];
        for(int loop = 0; loop < 10; loop++){
            memcpy(x0, s->p.x, D * Np * sizeof(double));
            Fs = 1.;
            for(int i = 0; i < Np; i++){
                fs[i] = 1. / (double)Np;
            }
            while(Fs > 0.1){
                n = updateSwapMC(s, id);
                Fs -= fs[n];
                fs[n] = 0.;
                for(int d = 0; d < D; d++){
                    dx[d] = x0[d*Np + n] - s->p.x[d*Np + n];
                    fs[n] += cos(k * dx[d]);
                }
                fs[n] /= (double)D * Np;
                Fs += fs[n];
            }
        }
        std::cout << "equilibrated t: " << s->t << std::endl;

        free(x0);
        free(fs);
        return;
    }
}