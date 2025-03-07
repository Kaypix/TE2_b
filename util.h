#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <eigen3/Eigen/Dense>

void ecrit(const std::string& nomFichier, const Eigen::VectorXf& t, const Eigen::MatrixXf& exact, const Eigen::MatrixXf& estime, std::string nom, const float h);

#endif