#ifndef COMMON_H
#define COMMON_H

#include "debug.h"

#define C 	 2.9979246e+8    // m/s    velocity of light in vacuum
#define E    1.6021773e-19   // C      electron charge
#define M    9.1093897e-31   // kg     electron mass
#define EPS  8.8541878e-12   // C/Vm   dielectric permability
#define EV   1.6021773e-19   // J      electron volt
#define HB   1.0545727e-34   // Js     Planck's h/2pi
#define AB   5.2917726e-11   // m      Bor radius
#define EN   4.3597483e-18   // J      atomic energy unit = 2 * 13.6 eV
#define TI   2.4188843e-17   // s      atomic time unit = HB / EN
#define PI   M_PI

#define TINY 1e-10
#define MASK 10

#define filename_size 100

inline double sqr(double x) { return (x*x); }   // inline function of c++

#endif