#include "util.h"
#include <fstream>
#include <eigen3/Eigen/Dense>
#include <iomanip>
#include <limits>

using namespace std ;
using namespace Eigen ;

void ecrit(const string& nomFichier, const VectorXf& t, const MatrixXf& exact, const MatrixXf& estime, string nom, const float h) {
    ofstream fichier(nomFichier);
    fichier << fixed << setprecision(7);
/*
    //Calcul des valeurs extrêmes des abscisses et ordonnées
    float x_min = x.minCoeff();
    float x_max = x.maxCoeff();
    float y_min = y.minCoeff();
    float y_max = y.maxCoeff();
*/
    //Écriture de l'entête avec les valeurs extrêmes
    fichier << "# Pas : h=  " << h << "\n";
    fichier << "# Méthode : " << nom << "\n";
    fichier << "# \n";

    for (size_t i = 0; i < t.size(); ++i) {
        fichier << t(i) << "\t" << exact(i,0) << "\t" << exact(i,1) << "\t" << estime(i,0) << "\t" << estime(i,1) << "\t" << exact.col(i) - estime.col(i)<< "\n";
    }

    fichier.close() ;
}