#include <iostream>
#include <vector>
#include <math.h>
#include <random>
#include <fstream>
#include <cmath>


#include "complexe.h"




// Méthodes privées

void Complexe::sync_cart_to_polar()
{
    this -> r = sqrt( pow(this -> re, 2) + pow(this -> im, 2));
    this -> theta = atan2(this -> im, this -> re + this -> r); 

}; 

void Complexe::sync_polar_to_cart()
{
    this -> re = (this -> r)*cos(this->theta); 
    this -> im = (this -> r)*sin(this->theta); 
}; 



// Constructeurs de la classe Complexe: on pourrait utiliser les list initializer 
Complexe::Complexe()
{
    this -> re = 0; 
    this -> im = 0;
    this -> r = 0; 
    this -> theta = 0; 
}; 


Complexe::Complexe(double re_, double im_)
{
    this -> re = re_; 
    (*this).im =im_; 
    sync_cart_to_polar; 
    
}; 

Complexe::Complexe(double re_)
{
    Complexe(re_, 0); 
}; 



// Surcharge d'opérateurs
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
}; 

Complexe Complexe::operator-= (const Complexe other)
{
    this -> re -= other.re; 
    this -> im -= other.im; 
    return *this; 
}


// Getters and Setters 

void Complexe::real (double re_)
{
    this -> re = re_; 
    sync_cart_to_polar; 
}; 

void Complexe::imag (double im_)
{
    this -> im = im_; 
    sync_cart_to_polar; 
}; 


double Complexe::real() const
{
    return this -> re; 
}; 

double Complexe::imag() const
{
    return this -> im; 
}; 


void Complexe::polar (double r_, double theta_)
{
    this -> r = r_; 
    this -> theta = theta_; 
    sync_polar_to_cart; 
}