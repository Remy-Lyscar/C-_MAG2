#include <iostream>
#include <vector>
#include <math.h>
#include <random>
#include <fstream>
#include <cmath>
#include <time.h>
#include<algorithm>
#include<tuple>


#include "complexe.h"
#include "reseau.h"

using namespace std; 


mt19937 rng; 
uniform_real_distribution<double> distrib_u01 (0,1);


// Résolution du problème par des MCMC (Markov Chain Monte Carlo)

double H (const Reseau& S, double B)
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


tuple<double, double> observables (const Reseau& S, double B)
{
    int N = S.ny * S.nx; 

    double E = H(S, B); 
    Reseau::Site i; 
    double M = 0; 

    for (int x = 0; x<S.nx; x++)
    {
        for (int y = 0; y<S.ny; y++)
        {
            i = S.site_xy(x,y); 
            M += S[i]; 
        }
    }

    E = E/N; 
    M = M/N; 
    auto t = make_tuple(M, E); 
    return t; 
}

// Mon compilateur n'étant pas assez récent, je vais plutôt passer par des références 
// RQ: je suis obligé de commenter car on ne peut overload uniquement avec le type de retour ! 

void observables (const Reseau& S, double B, double& e, double& m)
{
    int N = S.ny * S.nx; 
    
    double E = H(S, B); 
    Reseau::Site i; 
    double M = 0; 

    for (int x = 0; x<S.nx; x++)
    {
        for (int y = 0; y<S.ny; y++)
        {
            i = S.site_xy(x,y); 
            M += S[i];
        }
    }

    e = E/N;
    m = M/N;  

}





int main()
{ 

    
    srand(time(nullptr)); // use current time as seed for random generator



    // partie principale du programme
    Reseau S (300, 300); // voire 300x300 avec SFML

    int pas = 10000;  
    int step = 0;   

    double B = 0; 
    double beta = 0.6* log(1+sqrt(2))/2; // température critique pour le réseau carré 

    double m = 0; 
    double e = 0; 

    ofstream file ("ising_magnetisation_energie.txt");

    while (step < 10000000)
    {
        if (step%pas == 0)
        {
            observables(S, B, e, m);  
            file << step << " " << m << " " << e << endl; 
        }

        ising_metropolis_step(S, beta, B); 
        step++; 
    }



    return 0; 
}