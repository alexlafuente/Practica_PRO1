#include "Doctor.hpp"

//-------------
// Constructors
//-------------

Doctor::Doctor(){
    nom = "";
    visites = vector<Visita>(0, Visita(Data(), Pacient())); // L'inicialitzem sense elements, instanciats a visites buides
}

Doctor::Doctor(const string &nom){
    this->nom = nom;
    visites = vector<Visita>(0, Visita(Data(), Pacient())); // L'inicialitzem sense elements, instanciats a visites buides
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

vector<Visita> Doctor::visitesOrdenades(){
    ordenarVisites();
    return this->visites;
}

void Doctor::ordenarVisites(){
    // Insertion sort
    for(int i = 1; i < int(visites.size()); ++i){
        Visita x = visites[i];
        int j = i;
        while(j > 0 and x.getData() < visites[j - 1].getData()){
            visites[j] = visites[j - 1];
            --j;
        }
        visites[j] = x;
    }
}

void Doctor::afegirVisita(Visita &visita){
    visites.push_back(visita);
}

void Doctor::eliminarVisita(Visita &visita){
    vector<Visita> aux(0, Visita(Data(), Pacient())); // L'inicialitzem sense elements, instanciats a visites buides
    bool found = false;
    int i = 0;
    while(not found and i < int(visites.size())){
        // Es copien tots els elements, fins el que es vol eliminar (aquest no el copiem)
        if(not (visites[i].getData() == visita.getData()) and not (visites[i].getPacient().mateixesDades(visita.getPacient()))){
            aux.push_back(visites[i]);
        }
        else{
            found = true;
        }
        ++i;
    }
    while(i < int(visites.size())){
        // Copia els elements restants
        aux.push_back(visites[i]);
        ++i;
    }
    visites = aux;
}

void Doctor::eliminarVisites(Pacient &p){
    vector<Visita> aux(0, Visita(Data(), Pacient())); // L'inicialitzem sense elements, instanciats a visites buides
    for(int i = 0; i < int(visites.size()); ++i){
        if(not visites[i].getPacient().mateixesDades(p)){
            aux.push_back(visites[i]);
        }
    }
    visites = aux;
}

istream& operator>>(istream &is, Doctor &d){
    is >> d.nom;
    return is;
}

ostream& operator<<(ostream &os, const Doctor &d){
    os << "  " << d.nom << endl;
    for(int i = 0; i < int(visites.size()); ++i){
        os << "  " << d.visites[i].getData() << " " << d.visites[i].getPacient().getNom() << endl;
    }
    return os;
}