#ifndef COMPLEXE_H
#define COMPLEXE_H


class Complexe
{
    private: 

    double re; 
    double im; 
    double r; 
    double theta; 


    void sync_cart_to_polar(); 
    void sync_polar_to_cart(); 

    public: 

    // Constructeurs 
    Complexe(); // constructeur par défaut
    Complexe(double re_, double im_);
    Complexe(double re_); 


    // Destructeurs: Ici pas besoin car on alloue pas de mémoire

    // Opérateurs
    Complexe& operator+= (Complexe b); 
    Complexe operator- ( ); 
    Complexe& operator-= (const Complexe other); 
    Complexe operator* (const Complexe other); 


    // Getters and Setters

    void real(double re_); 
    void imag(double im_); 
    double real() const; 
    double imag() const; 

    void polar(double r_, double theta_); 

}; 



#endif //COMPLEXE_H