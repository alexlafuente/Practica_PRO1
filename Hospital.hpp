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

};