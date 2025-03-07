#ifndef FCTS_H

#include <eigen3/Eigen/Dense>

Eigen::VectorXf dydt(float t, Eigen::VectorXf y) ;

Eigen::VectorXf sol(float t, Eigen::VectorXf y_0) ;

#define FCTS_H
#endif