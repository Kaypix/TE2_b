#include <iostream>
#include <Eigen/Dense>
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
    float t0 = 0 ; float xmax = 50 ; int p = 2 ; int m=1 ; 
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
    y_0(0)=0 ; y_0(1)=1.98 ;
    VectorXf t(size1) ;
    MatrixXf exact(p, size1) ;
    MatrixXf estime(p, size1) ;
    MatrixXf delta(p,size1) ;
    
    estime.col(0)=y_0;
    float E0 = 0.5 * (estime(1,0))*(estime(1,0)) ;

    for (i = 0; i < size1; ++i) {
        t(i) = t0 + i * h ;
        exact.col(i) = sol(t(i), y_0) ;
    }
    
    delta.col(0) = exact.col(0) - estime.col(0) ;
#include <bits/stdc++.h> 

    for (i = 1 ; i< size1 ; ++i){
        if (choix == 1) {
            nom_titre="Euler progressive" ;
            nom_fichier="eulerprog" ;
            estime.col(i) = eulerProg (dydt, estime.col(i-1) , t(i-1), h) ;
            delta.col(i) = exact.col(i) - estime.col(i) ;
            float Em = (0.5 * estime(1,i) * estime(1,i)) + (k * k * (1 - cos(estime(0,i)))) ; //(0.5 * m * v * v) + (0.5 * k *  y *  y) ;
            float deltaE = (Em-E0)/E0 ;
            cout << "L'energie mécanique est : " << Em << " l'écart relatif est " << deltaE << endl ;
        }
        if (choix == 2) {
            nom_titre="Point du milieu" ;
            nom_fichier="pointMilieu" ;
            estime.col(i) = pointMilieu (dydt, estime.col(i-1) , t(i-1), h) ;
            delta.col(i) = exact.col(i) - estime.col(i) ;
            float Em = (0.5 * estime(1,i) * estime(1,i)) + (k * k * (1 - cos(estime(0,i)))) ; //(0.5 * m * v * v) + (0.5 * k *  y *  y) ;
            float deltaE = (Em-E0)/E0 ;
            cout << "L'energie mécanique est : " << Em << " l'écart relatif est " << deltaE << endl ;
        }
        if (choix==3) {
            nom_titre="Runge kutta d'ordre 4" ;
            nom_fichier="rk4" ;
            estime.col(i) = rk4 (dydt, estime.col(i-1) , t(i-1), h) ;
            delta.col(i) = exact.col(i) - estime.col(i) ;
            float Em = (0.5 * estime(1,i) * estime(1,i)) + (k * k * (1 - cos(estime(0,i)))) ; //(0.5 * m * v * v) + (0.5 * k *  y *  y) ;
            float deltaE = (Em-E0)/E0 ;
            cout << "L'energie mécanique est : " << Em << " l'écart relatif est " << deltaE << endl ;
        }      
    }
    
    pas=to_string(h); 
    ecrit(nom_fichier + "_" + pas + ".txt", t, exact, estime, delta, nom_titre, h) ;
    cout << "Résultats écrits dans le fichier txt correspondant." << endl;
}
