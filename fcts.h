#ifndef FCTS_H

#include <Eigen/Dense>

Eigen::VectorXf dydt(float t, Eigen::VectorXf y) ;

Eigen::VectorXf dydt_lin(float t, Eigen::VectorXf y) ;

Eigen::VectorXf sol(float t, Eigen::VectorXf y_0) ;

#define FCTS_H
#endif
