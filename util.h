#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <Eigen/Dense>

void ecrit(const std::string& nomFichier, const Eigen::VectorXf& t, const Eigen::MatrixXf& exact, const Eigen::MatrixXf& estime, const Eigen::sMatrixXf& delta, std::string nom, const float h);

#endif
