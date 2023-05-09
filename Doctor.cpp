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

vector<Visita> Doctor::visitesOrdenades() const{
    visites.ordenarVisites();
    return this->visites;
}

//-------------
// Modificadors
//-------------

void Doctor::ordenadarVisites(){
    vector<Film> faux = visites;
    // Insertion sort
    for(int i = 1; i < int(faux.size()); ++i){
        Film x = faux[i];
        int j = i;
        while(j > 0 and x.getData() < faux[j - 1].data()){
            if(x.getData() < faux[j - 1].data()){
                faux[j] = faux[j - 1];
            }
            --j;
        }
        faux[j] = x;
    }
}

void Doctor::afegirVisita(Visita &visita){
    visites.insert(l.begin(), visita);
}

void Doctor::eliminarVisita(Visita &visita){
    vector<Visita> aux(0);
    for(int i = 0; i < int(visites.size()); ++i){
        // Es copien tots els elements, menys el que es vol eliminar
        if(visites[i].data != visita.data and visites[i].pacient != visita.pacient){
            aux.push_back(visites[i]);
        }
    }
    visites = aux;
}

istream& operator>>(istream &is, Doctor &d){
    is >> d.nom;
    return is;
}