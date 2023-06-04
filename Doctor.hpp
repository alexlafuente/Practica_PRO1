#include <iostream>
#include <string>
#include <vector>
#include "Visita.hpp"

class Doctor{
    
private:
    string nom;
    vector<Visita> visites;
    // Pre: cert
    // Post: ordena el vector de visites paràmetre implícit
    void ordenarVisites();

public:
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
    Doctor(const string &nom, vector<Visita> &visites);
    
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
    // Post: afegeix visita paràmetre explícit, al final del vector de visites paràmetre implícit
    void afegirVisita(Visita visita);
    
    // Pre: cert
    // Post: elimina visita paràmetre explícit, al final del vector de visites paràmetre implícit
    void eliminarVisita(Visita visita);
    
    // Pre: p no està buit
    // Post: s'eliminen totes les visites d'un pacient p
    void eliminarVisites(Pacient &p);
    
    //-----------
    // L/E
    //-----------
    
    /* Pre: està preparat al canal estàndard d'entrada un valor - string*/
    /* Post: el doctor 'd' passa a tenir el valor llegit del canal
        estàndard d'entrada com a nom */			
    friend istream& operator>>(istream &is, Doctor &d);
    
    /* Pre: cert */
    /* Post: s'ha ordenat les visites, i s'ha escrit el nom del doctor 'd' i les seves visites, al canal estàndard de sortida */
    friend ostream& operator<<(ostream &os, Doctor &d);
};
