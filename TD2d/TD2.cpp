#include <iostream>
#include "point.h"
#include <vector>
#include <math.h>
#include <random>
#include "polygone.h"
#include <fstream>
#include <cmath>
#include "complexe.h"

using namespace std; 




ostream& operator<< (ostream& out, const Complexe& nombre)
{
    cout << nombre.re << " " << nombre.im << endl;
}

Complexe operator+ (Complexe a, Complexe b)
{
    return a += b; 
}


Complexe operator* (double scalaire, Complexe a)
{
    return Complexe(scalaire * a.re, scalaire * a.im); 
}

Complexe operator* (Complexe a, double scalaire)
{
    return scalaire * a; 
}



void le_plus_loin(vector<Point> tab)
{

    unsigned short int k = 0; 
    double d = tab[0].dist_origine(); 
    double di = 0; 

    for (size_t i = 1; i<tab.size(); i++)
    {
        di = tab[i].dist_origine(); 
        if ( di > d)
        {
            k = i; 
            d = di; 
        }
    }

    cout << tab[k].x << " " << tab[k].y << endl; 
}


int main()
{



    Complexe a = Complexe(1.2, 3.4); 
    Complexe b = Complexe(2.3, 5.1); 

    // cout << (a+b).re << " " << (a+b).im << endl; 
    Complexe c = a+b; 
    cout << c.re << " " << c.im << endl;

    Complexe d = -a; 
    cout << d.re << endl; 

    cout << d << endl; 

    return 0; 


    // Point p; 
    // p.init(1.2 , 3.4); 

    // cout << p.x << " " << p.y << endl; 



    // // double * tab = new point[5]; 
    // vector<Point> tab(5); 
    // for (size_t i = 0; i<tab.size(); i++)
    // {
    //     tab[i].init(1.4*i, 2.3*i); 
    // }

    // le_plus_loin(tab); 


    // double taille = sqrt(2);
    // Polygone carre; 

    // carre.init_regulier(4, taille); 
    // cout << carre.perimetre() << endl; 


    // int n = 100; 

    // fstream f; 
    // f.open("perimetres.txt", ios::out); 

    // double taille = double(1)/2 ; 
    // for (int i = 3; i<n; i++)
    // {
    //     Polygone poly; 
    //     poly.init_regulier(i, taille); 
    //     f << poly.perimetre() << endl; 
    // }

    // f.close(); 


    // return 0; 
}