#include "Doctor.hpp"

//-------------
// Constructors
//-------------

Doctor::Doctor(){
    nom = "";
    visites = list<Visita>(0);
}

Doctor::Doctor(const string &nom){
    this->nom = nom;
}

Doctor::Doctor(const string &nom, list<Visita> &visites){
    this->nom = nom;
    this->visites = visites;
}

Doctor::~Doctor(){
    
}

//-------------
// Consultors
//-------------

string Doctor::getName() const{
    return nom;
}

list<Visita> Doctor::visitesOrdenades() const{
    visites.ordenarVisites();
    return this->visites;
}

//-------------
// Modificadors
//-------------

void Doctor::ordenadarVisites(){
    // Insertion sort
    list<Visita>::iterator it = visites.begin();
    ++it;
    for(it; it != visites.end(); ++it){ // it = i
        Visita x = *it;
        list<Visita>::iterator it2 = it; // it2 = j
        list<Visita>::iterator it3 = --it2; // it3 = j - 1
        while(it2 != visites.begin() and x.getData() < (*it3).data){
            if(x.getData() < (*it3).data){
                *it2 = (*it3);
            }
            it2--;
        }
        *it2 = x;
    }
}

void Doctor::afegirVisita(Visita &visita){
    visites.insert(l.begin(), visita);
}

void Doctor::eliminarVisita(Visita &visita){
    list<Visita> iterator it = visites.begin()
    bool found = false;
    while(not found and it != visites.end){
        if(it->data == visita.data and it->pacient == visita.pacient){
            found = true;
            it = it.erase(it);
        }
        else{
            ++it;
        }
    }
}

istream& operator>>(istream &is, Doctor &d){
    is >> d.nom;
    return os;
}