#ifndef CONF_HPP
#define CONF_HPP

#include <math.h>

const double pi = 3.141592653589793;

const int D = 2;
const int Np = 300;
const double Phi_init = 0.3;
const double T = 10e-6;
const double a0 = 1.;
const double a_min = 0.7253;
const double a_max = 1.6095;
const double A = 1.3203;

namespace PhysPeach{
    template<typename T>
    T powInt(T a, int x);
}
#endif