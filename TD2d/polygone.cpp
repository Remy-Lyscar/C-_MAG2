#include <iostream>
#include "point.h"
#include "polygone.h"
#include <vector>
#include <math.h>


double dist (Point a, Point b)
{
    return sqrt(pow(abs(a.x - b.x), 2) + pow((a.y - b.y), 2)); 
}

void Polygone::init_regulier(unsigned int ordre, double taille)
{
    vector<Point> tab(ordre); 
    for (size_t i = 0; i< ordre; i++)
    {
        tab[i].init(taille*cos((2*M_PI*i)/ordre), taille*sin((2*M_PI*i)/ordre));
    } 

    for (size_t i = 0; i< ordre; i++)
    {
        coord.push_back(tab[i]); 
    }
}


void Polygone::affiche_sommets()
{
    for (size_t i = 0; i<coord.size(); i++)
    {
        cout << "x = " << coord[i].x << " " << "y = " << coord[i].y << endl; 
    }
}



double Polygone::perimetre()
{
    double peri = 0 ; 
    for (size_t i = 0; i<(coord.size() - 1); i++)
    {
        peri = dist(coord[i], coord[i+1]); 
    }

    return peri; 
}


