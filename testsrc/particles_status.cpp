#include <iostream>
#include <time.h>

#include "../hpp/conf.hpp"
#include "../hpp/MT.hpp"
#include "../hpp/particles.hpp"

int Np;
double Phi_init;
int main() {
    Np = 300;
    Phi_init = 0.3;
    init_genrand((unsigned long)time(NULL));
    std::cout << "hello jamming" << std::endl;
    PhysPeach::Particles p;
    PhysPeach::createParticles(&p, 0);
    double L = pow(p.V/Phi_init, 1./(double)D);
    int Nc = 9;
    PhysPeach::scatterParticles(&p, L, Nc);

    double diam_min = 100.;
    double diam_max = 0.;
    double diam_mean = 0.;
    double x_mean[D];
    for(int d = 0; d < D; d++){
        x_mean[d] = 0;
    }
    for (int i = 0; i < Np; i++){
            std::cout << i << " diam: ";
            std::cout << p.diam[i] << ", x1: ";
            std::cout << p.x[i] << ", x2: ";
            if(D == 2){
                 std::cout << p.x[i+Np] << std::endl;
            }else if(D == 3){
                std::cout << p.x[i+Np] << ", x3: ";
                std::cout << p.x[i+2*Np] << std::endl;
            }
            if (p.diam[i] < diam_min) {
                diam_min = p.diam[i];
            }
            if (p.diam[i] > diam_max) {
                diam_max = p.diam[i];
            }
            diam_mean += p.diam[i];
            for(int d = 0; d < D; d++){
                x_mean[d] += p.x[i+d*Np];
            }
        }
    std::cout << "diam_min: " << diam_min << " ~ " << a_min << std::endl;
    std::cout << "diam_max: " << diam_max << " ~ " << a_max << std::endl;
    std::cout << "diam_mean: " << diam_mean /(double)Np << " ~ 1" << std::endl;
    std::cout << "packing: " << p.V << std::endl;
    std::cout << "packing ratio: " << p.V/PhysPeach::powInt(L, D) << " ~ " << Phi_init << std::endl;
    std::cout << "x_mean1: " << x_mean[0]/(double)Np << ", x_mean2: " << x_mean[1]/(double)Np << std::endl;
    PhysPeach::deleteParticles(&p, 0);
    return 0;
}