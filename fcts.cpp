#include "fcts.h"
#include <cmath>
#include <iostream>
#include <Eigen/Dense>

using namespace std ;
using namespace Eigen ;

float k;

VectorXf dydt(float t, VectorXf y) {
    VectorXf dydt(y.size()); // p = dimension de y(t)
    dydt(0) = y(1);
    dydt(1) = -k*k*sin(y(0));
    return dydt ;
}

//Fonction second membre dydt pour le système linéaire du pendule
VectorXf dydt_lin(float t, VectorXf y) {
    VectorXf dy(2);
    dy(0) = y(1);            // v = y'
    dy(1) = -k * k * y(0);   // v' = -k^2 y
    return dy ;
}
VectorXf sol(float t, VectorXf y_0) {
    VectorXf solAna(2) ;
    solAna(0) = y_0(0)*cos(k*t) + ((y_0(1)/k)*sin(k*t)) ;
    solAna(1) = y_0(0)*k*sin(k*t) + y_0(1)*cos(k*t) ;
    return solAna ;
}
