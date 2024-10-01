#include <iostream>
#include "point.h"
#include <vector>
#include <math.h>
#include <random>
#include "polygone.h"

using namespace std; 




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


    double taille = sqrt(2);
    Polygone carre; 

    carre.init_regulier(4, taille); 
    cout << carre.perimetre() << endl; 



    return 0; 
}
