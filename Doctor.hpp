#include <iostream>
#include <string>
#include <queue>
#include "Visita.hpp"

class Doctor{
    
private:
    string nom;
    vector<Visita> visites;

Public:
    //-------------
    // Constructors
    //-------------
    
    // Pre: cert
    // Post: crea un Doctor buit
    Doctor();
    
    // Pre: cert
    // Post: crea un Doctor amb el valor "nom" passat per referència
    Doctor(const string &nom);
    
    // Pre: cert
    // Post: crea un Doctor amb el valor "nom" i "visites" passats per referència
    Doctor(const string &nom, queue<Visita> &visites);
    
    // Destructor
    // Post: esborra automaticament els objectes locals en sortir d'un ambit de visibilitat
    ~Doctor();
    
    //-------------
    // Consultors
    //-------------
    
    // Pre: cert
    // Post: retorna el nom del doctor paràmetre implícit
    string getName() const;
    
    //-------------
    // Modificadors
    //-------------
    
    // Pre: cert
    // Post: ordena el vector de visites paràmetre implícit
    void visitesOrdenades();
    
    // Pre: cert
    // Post: afegeix visita paràmetre explícit, al final del vector de visites paràmetre implícit
    void afegirVisita(Visita &visita);
    
    // Pre: cert
    // Post: elimina visita paràmetre explícit, al final del vector de visites paràmetre implícit (copiar tots elements en vector auxiliar, excepte el que coincideix, i this->visites = vector auxiliar<Visita>)
    void eliminarVisita(Visita &visita);
    
    
};