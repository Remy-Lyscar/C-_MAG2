#include <iostream>
#include "point.h"
#include <vector>
#include <math.h>
#include <random>
#include "polygone.h"
#include <fstream>
#include <cmath>


#include "complexe.h"

Complexe::Complexe(double re, double im)
{
    this -> re = re; 
    (*this).im =im; 
}; 


Complexe& Complexe::operator+= (Complexe b)
{
    this -> re += b.re; 
    this -> im += b.im; 
    return *this; 
}; 


Complexe Complexe::operator- ()
{
    this -> re = -re; 
    this -> im = -im; 
    return *this; 
}