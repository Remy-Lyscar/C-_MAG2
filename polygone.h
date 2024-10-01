#ifndef POLYGONE_H
#define POLYGONE_H


#include <vector>
#include "point.h"
using namespace std; 

class Polygone
{   
    public: 

    vector<Point> coord; 


    void init_regulier(unsigned int ordre, double taille); 
    void affiche_sommets(); 
    double perimetre(); 

}; 


#endif //POLYGONE_H
