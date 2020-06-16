#include <iostream>
#include <time.h>

#include "../hpp/conf.hpp"
#include "../hpp/MT.hpp"
#include "../hpp/particles.hpp"

int main() {
    init_genrand((unsigned long)time(NULL));
    std::cout << "hello jamming" << std::endl;
    PhysPeach::Particles p;
    PhysPeach::createParticles(&p);

    double diam_min = 100.;
    double diam_max = 0.;
    double diam_mean = 0.;
    for (int i = 0; i < Np; i++){
            std::cout << i << " diam: ";
            std::cout << p.diam[i] << std::endl;
            if (p.diam[i] < diam_min) {
                diam_min = p.diam[i];
            }
            if (p.diam[i] > diam_max) {
                diam_max = p.diam[i];
            }
            diam_mean += p.diam[i];
        }
    std::cout << "min: " << diam_min << " ~ " << a_min << std::endl;
    std::cout << "min: " << diam_max << " ~ " << a_max << std::endl;
    std::cout << "mean: " << diam_mean /(double)Np << " ~ 1" << std::endl;
    PhysPeach::deleteParticles(&p);
    return 0;
}