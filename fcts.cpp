#include "fcts.h"
#include <cmath>
#include <iostream>
#include <eigen3/Eigen/Dense>

using namespace std ;
using namespace Eigen ;

float k;

VectorXf dydt(float t, VectorXf y) {
    VectorXf dydt(y.size()); // p = dimension de y(t)
    dydt(0) = y(1);
    dydt(1) = -sin(y(0));
    return dydt ;
}

VectorXf sol(float t, VectorXf y_0) {
    VectorXf solAna(2) ;
    solAna(0) = y_0(0)*cos(k*t) + (y_0(1)/k*sin(k*t)) ;
    solAna(1) = y_0(0)*k*sin(k*t) + y_0(1)*cos(k*t) ;
    return solAna ;
}