#include "Doctor.hpp"

//-------------
// Constructors
//-------------

Doctor::Doctor(){
    nom = "";
    visites = vector<Visita>(0);
}

Doctor::Doctor(const string &nom){
    this->nom = nom;
}

Doctor::Doctor(const string &nom, vector<Visita> &visites){
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

//-------------
// Modificadors
//-------------

vector<Visita> Doctor::visitesOrdenades() const{
    visites.ordenarVisites();
    return this->visites;
}

void Doctor::ordenarVisites(){
    vector<Film> faux = visites;
    // Insertion sort
    for(int i = 1; i < int(faux.size()); ++i){
        Film x = faux[i];
        int j = i;
        while(j > 0 and x.getData() < faux[j - 1].data()){
            faux[j] = faux[j - 1];
            --j;
        }
        faux[j] = x;
    }
}

void Doctor::afegirVisita(Visita &visita){
    visites.push_back(visita);
}

void Doctor::eliminarVisita(Visita &visita){
    vector<Visita> aux(0);
    bool found = false;
    int i = 0;
    for(i; not found and i < int(visites.size()); ++i){
        // Es copien tots els elements, fins el que es vol eliminar (aquest no el copiem)
        if(not (visites[i].getData() == visita.getData()) and not (visites[i].getPacient().mateixesDades(visita.getPacient()))){
            aux.push_back(visites[i]);
        }
        else{
            found = true;
        }
    }
    for(i; i < int(visites.size()); ++i){
        // Copia els elements restants
        aux.push_back(visites[i]);
    }
    visites = aux;
}

void Hospital::eliminarVisites(Pacient &p){
    vector<Visita> aux(0);
    for(int i = 0; i < int(visites.size()); ++i){
        if(visites[i].getPacient() != p){
            aux.push_back(visites[i]);
        }
    }
    visites = aux;
}

istream& operator>>(istream &is, Doctor &d){
    is >> d.nom;
    return is;
}