#ifndef RESEAU_H
#define RESEAU_H


#include<vector>
#include<array>
#include<random>

using namespace std; 


class Reseau// On se fiche de la localisation précise d'un site, on veut juste pouvoir
// accéder à ses voisins. On rend invisible la structure réelle du réseau
// pour l'algorithme l'utilisant ! 
{

    public: 

    class Site 
    {
        private: 
        int index; 
        int x; 
        int y; 

        friend class Reseau; 

        public: 
        // Constructors 
        Site () = default; 
        Site (int i_, int x_, int y_): index(i_), x(x_), y(y_) {}
    }; 



    public: 
    vector<int> reseau; 
    int nx; 
    int ny; 

    // distribution d'entiers aléatoires  
    random_device rd;  // ex: température de mon CPU, ...
    mt19937 gen;
    uniform_int_distribution<int> dist;


    Site site_index (int index) const; 

    public: 

    // Constructors
    Reseau (int , int , int ); 
    Reseau (int, int); 
    // Deep Copy Constructor
    Reseau (const Reseau&); 

    // Destructors 
    // Not needed here, because I used vector and not manual memory allocation 
    

    //Overloaded operators
    int operator[] (Site) const; 
    int& operator[] (Site); 
    // int& operator[] ((int x, int y)); 


    Site site_xy (int x, int y) const; 

    Site site_alea () const;  

    array<Site,4> voisins (Site s) const; 


    // Affichage

    void affiche_console () const; // affichage textuel dans la console   


}; 


#endif // RESEAU_H