#include <iostream>
#include "point.h"
#include <vector>
#include <math.h>


void Point::init(double abs, double ord)
{
    x = abs; 
    y = ord; 
}

double Point::dist_origine()
{
    return pow(abs(x-y), 2); 
}