#include <iostream>
#include <vector>
#include <math.h>
#include <random>
#include <fstream>
#include <cmath>
#include <time.h>
#include<algorithm>


#include "complexe.h"
#include "reseau.h"

using namespace std; 


mt19937 rng; 
uniform_real_distribution<double> distrib_u01 (0,1);


// Résolution du problème par des MCMC (Markov Chain Monte Carlo)

double H (Reseau& S, double B)
{
    double rst = 0; 
    Reseau::Site i; 
    array<Reseau::Site, 4> v; 

    for (int x = 0; x<S.nx; x++)
    {
        for (int y = 0; y<S.ny; y++)
        {
            i = S.site_xy(x,y); 
            v = S.voisins(i); 
            rst -= 0.5 * S[i]*(S[v[0]] + S[v[1]] + S[v[2]] + S[v[3]]) - B*S[i]; 
        }
    }

    return rst; 

}


// On fixe l'échelle d'énergie et de température en fixant J = kb = 1
bool ising_metropolis_step (Reseau& S, double beta, double B)
// On passe par référence pour ne pas copier le réseau dans une 
// variable locale de la fonction à chaque appel
// ce qui serait coûteux et ralentirait le programme 
{
    // Proposition de transition 
    Reseau::Site i = S.site_alea(); 
    Reseau Sprop = S; 
    Sprop[i] = -S[i];
    
    double Ei = H(S, B); 
    double Ef = H(Sprop, B); 
    double DeltaE = Ef - Ei; 
    double r = min(1.0, exp(-beta*DeltaE)); 

    double t = distrib_u01(rng); 
    if (t<r) 
    {
        S[i] = Sprop[i]; 
        return true; 
    }

    return false; 
    
}


int main()
{ 

    
    srand(time(nullptr)); // use current time as seed for random generator



    // partie principale du programme
    Reseau S (200, 100); // voire 300x300 avec SFML




    





    return 0; 
}