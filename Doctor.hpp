#include <iostream>
#include <string>
#include <list>
#include "Visita.hpp"

class Doctor{
    
private:
    string nom;
    list<Visita> visites;

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
    Doctor(const string &nom, list<Visita> &visites);
    
    // Destructor
    // Post: esborra automaticament els objectes locals en sortir d'un ambit de visibilitat
    ~Doctor();
    
    //-------------
    // Consultors
    //-------------
    
    // Pre: cert
    // Post: retorna el nom del doctor paràmetre implícit
    string getName() const;
    
    // Pre: cert
    // Post: retorna la llista de visites paràmetre implícit, ordenat
    list<Visita> visitesOrdenades() const;
    
    //-------------
    // Modificadors
    //-------------
    
    // Pre: cert
    // Post: ordena el vector de visites paràmetre implícit
    void ordenadarVisites();
    
    // Pre: cert
    // Post: afegeix visita paràmetre explícit, al final del vector de visites paràmetre implícit
    void afegirVisita(Visita &visita);
    
    // Pre: cert
    // Post: elimina visita paràmetre explícit, al final del vector de visites paràmetre implícit (copiar tots elements en vector auxiliar, excepte el que coincideix, i this->visites = vector auxiliar<Visita>)
    void eliminarVisita(Visita &visita);
    
    /* Pre: està preparat al canal estàndard d'entrada un valor - string*/
    /* Post: el doctor 'd' passa a tenir el valor llegit del canal
        estàndard d'entrada com a nom */			
    friend istream& operator>>(istream &is, Doctor &d);
    
<<<<<<< HEAD
    /* Pre: cert */
    /* Post: s'ha escrit l'atribut nom del
        doctor 'd' al canal estàndard de sortida */
    //friend ostream& operator<<(ostream &os, const Doctor &d);
    
=======
>>>>>>> c4a6c6067eb0845587c74945a78998fc61993364
};
