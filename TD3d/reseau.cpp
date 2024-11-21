#include <iostream>
#include <vector>
#include <math.h>
#include <random>
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include<array>

#include<windows.h>

#include "reseau.h"

using namespace std; 



// Constructors 

Reseau::Reseau (int nx_, int ny_, int valeur_init)
// RQ: l'utilisation d'une initializer list est nécessaire quand un 
// membre n'a pas de constructeur par défaut (ce qui n'est pas le cas ici)
{

    nx = nx_;
    ny = ny_; 


    for (int k = 0; k<(nx*ny); k++)
    {
        reseau.push_back(valeur_init); 
    }

    // cout << "Reseau " << nx << "x" << ny << " @ " << &reseau << endl; 
}

Reseau::Reseau(const Reseau& other)
    : nx(other.nx), ny(other.ny)
{
    for (int k=0;  k<(nx*ny);k++)
    {
        reseau.push_back(other.reseau[k]); 
    }
    // cout << "Reseau " << nx << "x" << ny << " @ " << &reseau << endl;
}


Reseau::Reseau(int nx_, int ny_)
    :nx(nx_), ny(ny_), gen(rd()), dist(0,1)

    // crée un réseau dont les sites ont une valeur aléatoire +/- 1
{
    int rd_binary; 

    for (int k = 0; k<(nx*ny); k++)
    {  
        rd_binary = dist(gen)*2 - 1; 
        reseau.push_back(rd_binary); 
    }
    
    // cout << "Reseau " << nx << "x" << ny << " @ " << &reseau << endl;
}

Reseau::Site Reseau::site_index (int index) const
{
    int x = index % nx; 
    int y = index / nx; 
    if (x<0) {x += nx;} 

    return Site (index, x, y); 
}

Reseau::Site Reseau::site_alea () const
{
    int x =  rand() % nx ; 
    int y = rand() % ny;
    if (x < 0) {x += nx;}
    if (y < 0) {y += ny;}

    return Site(x + nx*y, x, y); 

}

Reseau::Site Reseau::site_xy (int x, int y) const
{
    x = x % nx;
    if (x < 0) {x += nx;}
    y = y % ny; 
    if (y<0) {y+=ny;}

    Site site (x + nx*y, x, y); 
    return site;
}

int Reseau::operator[] (Site s) const
{
    return reseau[s.index]; 
}

int& Reseau::operator[] (Site s)
{
    return reseau[s.index]; 
}


array<Reseau::Site,4> Reseau::voisins (Site s) const
// We return a array of size 4, hence we assume we are not asking for a 
// point at the border of the lattice
// Anyway since we imposed periodic conditions we don't have any border effects 
{
    array<Site, 4> tab = {site_xy(s.x -1, s.y), site_xy(s.x, s.y-1), site_xy(s.x, s.y+1), site_xy(s.x+1,s.y)}; 
    return tab; 

}



// Affichage 

void Reseau::affiche_console () const
// Affichage textuel dans la console
// Ceci n'est valable que pour le réseau carré 
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int x = 0; x<nx; x++)
    {
        for (int y = 0; y<ny; y++)
        {
            int ind = x + nx*y; 
            if (reseau[ind]>0)
            {
                // cout << WHITE << (char)254u << RESET; 
                SetConsoleTextAttribute(hConsole, 15); // White 
                cout << (char)254u; 

                SetConsoleTextAttribute(hConsole, 7); // reset to default 
            }
            else if (reseau[ind] < 0)
            {
                // cout << RED << (char)254u << RESET;  
                SetConsoleTextAttribute(hConsole, 12); // Red 
                cout << (char)254u;

                SetConsoleTextAttribute(hConsole, 7); // reset to default 
            }
            else 
            {
                cout << " "; 
            }
        }

        cout << "\n"; 
    }
}