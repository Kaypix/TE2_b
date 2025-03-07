#include "methodes.h"
#include <eigen3/Eigen/Dense>
#include <functional>
#include <iostream>

using namespace std ;
using namespace Eigen ;

VectorXf eulerProg (function<VectorXf(float, VectorXf)>dydt, VectorXf u_i, const float t_i, const float h) { 
        return u_i + h*dydt(t_i, u_i) ;
} 

VectorXf pointMilieu (function<VectorXf(float, VectorXf)>dydt, VectorXf u_i, const float t_i, const float h) { 
        return u_i + h*dydt(t_i + h/2, u_i + h*dydt(t_i, u_i)/2);
} 

VectorXf rk4 (function<VectorXf(float, VectorXf)>dydt, VectorXf u_i, const float t_i, const float h) { 
        VectorXf k1 , k2 , k3 , k4 ;
        k1 = dydt(t_i, u_i) ;
        k2 = dydt(t_i + h/2, u_i + k1*h/2) ;
        k3 = dydt(t_i + h/2, u_i + k2*h/2) ;
        k4 = dydt(t_i + h, u_i + k3*h) ;
        return u_i + (k1 + 2*k2 + 2*k3 + k4)*h/6 ;
} 