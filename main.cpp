#include <iostream>
#include <eigen3/Eigen/Dense>
#include <cmath>
#include <bits/stdc++.h> 

//entêtes personnelles
#include "methodes.h" //La méthode : tabulation
#include "fcts.h" //Les fonctions test
#include "util.h" //Ecriture dans un fichier

using namespace std ;
using namespace Eigen ;

extern float k ;

int main () {
    k=1 ;
    float t0 = 0 ; float xmax = 20 ; int p = 2 ; 
    float h ; 
    string nom_titre, nom_fichier, pas ;
    int i, choix ;
    // Saisie des paramètres
    cout << "Entrer le pas d'integration" << endl ;
    cin >> h ;

    //Affichage du menu pour choisir la methode
    cout << "Choisissez la méthode à utiliser :\n";
    cout << "1. Euler progressive \n";
    cout << "2. Point du milieu \n";
    cout << "3. Runge Kutta d'ordre 4 \n";
    cout << "Votre choix (1-3) : ";
    cin >> choix;

    int size1 = ((xmax - t0) / h) + 1;

    VectorXf y_0(p) ;
    y_0(0)=0 ; y_0(1)=0.2 ;
    VectorXf t(size1) ;
    MatrixXf exact(p, size1) ;
    MatrixXf estime(p, size1) ;

    for (i = 0; i < size1; ++i) {
        t(i) = t0 + i * h ;
        exact.col(i) = sol(t(i), y_0) ;
    }

#include <bits/stdc++.h> 

    for (i = 0 ; i< size1 ; ++i){
        if (choix == 1) {
            nom_titre="Euler progressive" ;
            nom_fichier="eulerprog" ;
            estime.col(i+1) = eulerProg (dydt, estime.col(i) , t(i), h) ;
        }
        if (choix == 2) {
            nom_titre="Point du milieu" ;
            nom_fichier="pointMilieu" ;
            estime.col(i+1) = pointMilieu (dydt, estime.col(i) , t(i), h) ; //estime.col(i+1) = milieu(estime.col(i), t(i), h, dydt);

        }
        if (choix==3) {
            nom_titre="Runge kutta d'ordre 4" ;
            nom_fichier="rk4" ;
            estime.col(i+1) = rk4 (dydt, estime.col(i) , t(i), h) ;
        }      
    }

    pas=to_string(h); 
    ecrit(nom_fichier + "_" + pas + ".txt", t, exact, estime, nom_titre, h) ;
    cout << "Résultats écrits dans le fichier txt correspondant." << endl;
}