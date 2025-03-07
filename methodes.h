#ifndef METHODE_H
#define METHODE_H

#include <functional>
#include <eigen3/Eigen/Dense>

Eigen::VectorXf eulerProg (std::function<Eigen::VectorXf(float, Eigen::VectorXf)>dydt, Eigen::VectorXf u_i, const float t_i, const float h) ;

Eigen::VectorXf pointMilieu (std::function<Eigen::VectorXf(float, Eigen::VectorXf)>dydt, Eigen::VectorXf u_i, const float t_i, const float h) ;

Eigen::VectorXf rk4 (std::function<Eigen::VectorXf(float, Eigen::VectorXf)>dydt, Eigen::VectorXf u_i, const float t_i, const float h) ;

#endif 