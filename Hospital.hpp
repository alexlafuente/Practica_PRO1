#include "Pacient.hpp"
#include "Doctor.hpp"
#include "PriorityQueue.hpp"
#include "BST.hpp"
#include <iostream>
#include <string>

class Hospital {
    
private:
    PriorityQueue<Pacient> llistaEspera; // Llista d'espera de la secció d'urgències (en base a gravetat)
    BST<Pacient> pacients; // Llista dels noms dels pacients
    vector<Doctor> doctors; // Llista de doctors
    
Public:
    //-------------
    // Constructors
    //-------------
    
    // Pre: cert
    // Post: crea un hospital buit
    Hospital();
    
    // Pre: cert
    // Post: crea un hospital amb la llista d'espera, el registre de pacients i la llista de doctors, rebuts per paràmetre
    Hospital(const PriorityQueue<Pacient> &llistaEspera, const BST<Pacient> &pacients, const vector<Doctor> &doctors);
    
    // Destructor
    // Post: esborra automaticament els objectes locals en sortir d'un ambit de visibilitat
    ~Hospital();
    
    //-------------
    // Consultors
    //-------------
    
    // Pre: cert
    // Post: retorna la llista de espera
    PriorityQueue<Pacient> getLlistaEspera() const;
    
    
    //-------------
    // Modificadors
    //-------------
    
    // Pre: Pacient no està buit
    // Post: si el pacient està al registre (BST<Pacient> pacients), dona errror i no fa res. En cas contrari, s'afegeix el pacient al registre i a la llista 
    // d'espera
    void afegirPacient(const Pacient &p); // Apunt: abans de mirar en llista d'espera, buscar-lo al registre.
    
    // Pre: s no està buida
    // Post: si el nom s no figura al registre de pacients, dona errror i no fa res. En cas contrari, el pacient s'elmina del registre, de llista d’espera i es 
    // cancel·len totes les visites que tingui programades (en cas d'haver-ne)
    void eliminarPacient(const string &s);
    
    // Pre: s no està buida
    // Post: si existeix algun doctor a la llista amb nomb s, dona error i no fa res. En cas contrari, s'afegeix un doctor amb nom s
    void afegirDoctor(const string &s); // Apunt: en cas que no hi hagi cap altre amb el nom s, crear Doctor amb constructor de nom, i afegir-lo al vector de 
                                        //        doctors
    // Pre: cert
    // Post: si la llista d'espera està buida, dona error i no fa res. En cas contrari, s’elimina el primer pacient de la llista d’espera, 
    // però no es dona de baixa del registre.
    void tractarSeguent();
    
    // Pre: s no està buida
    // Post: si no existeix un pacient amb nom s al registre, o gravetat no és vàlida, dona error i no fa res. En cas contrari, es modifica el pacient al 
    // sistema, i es ressitua el pacient en la llista d’espera en funció del nou nivell de gravetat
    void modificarPacient(const string &s, int &g); // Apunt: en PriorityQueue, eliminar element i afegir el nou element (modificat) i modificar en BST
    
    // Pre: s, doc i data no estan buits
    // Post: si no existeix un pacient amb nom s al registre, o un doctor amb nom doc a la llista, dona error i no fa res. En cas contrari, s’afegeix una nova 
    // visita al doctor amb el pacient i data indicat
    void afegirVisita(const &string &s, const string &doc, const Data &data); // Apunt: Agafar el Pacient a afegir al vector de visites, del BST
    
    // Pre: p, doc i data no estan buits
    // Post: si no existeix un pacient amb nom p al registre, o un doctor amb nom doc a la llista, o la visita no existeix a la llista, dona error. En cas 
    // contrari, s’elimina la visita al doctor amb el pacient de nom p la data de nom data.
    void eliminarVisita(const &string &p, const string &doc, const Data &data); // Apunt: comparar visites del vector de visites amb == getData() i 
                                                                               //        == getPacient();
    // Pre: cert
    // Post: Per cada doctor que hi hagi en la llista, s’escriu el seu nom i la llista de visites (ordenada per data)
    void mostrarVisites(); // Apunt: utilitzar métode de la classe Doctor, ordenarVisites()
};