#ifndef COMPLEXE_H
#define COMPLEXE_H


class Complexe
{
    public: 

    Complexe(); 
    Complexe(double re, double im);

    double re;
    double im; 

    Complexe& operator+= (Complexe b); 

    Complexe operator- ( ); 

}; 



#endif //COMPLEXE_H