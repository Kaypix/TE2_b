#include "util.h"
#include <fstream>
#include <Eigen/Dense>
#include <iomanip>
#include <limits>

using namespace std ;
using namespace Eigen ;

void ecrit(const string& nomFichier, const VectorXf& t, const MatrixXf& exact, const MatrixXf& estime, const MatrixXf& delta, string nom, const float h) {
    ofstream fichier(nomFichier);
    fichier << fixed << setprecision(7);

    //Écriture de l'entête avec les valeurs extrêmes
    fichier << "# Pas : h=  " << h << "\n";
    fichier << "# Méthode : " << nom << "\n";
    fichier << "# \n";

    for (size_t i = 0; i < t.size(); ++i) {
        fichier << t(i) << "\t" << exact(0,i) << "\t" << exact(1,i) << "\t" << estime(0,i) << "\t" << estime(1,i) <<"\t" << delta(0,i) << "\t" << delta(1,i) << endl ;
    }

    fichier.close() ;
}

