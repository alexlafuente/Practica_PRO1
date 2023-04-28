#include <iostream>
#include <string>
#include <queue>
#include "Visita.hpp"

class Doctor{
    
private:
    string nom;
    queue<Visita> visites;

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
    
    
};