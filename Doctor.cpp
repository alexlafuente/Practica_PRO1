#include "Doctor.hpp"

//--------------------------
// Mètodes privats auxiliars
//--------------------------

void Doctor::ordenarVisites(){
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

void Doctor::afegirVisita(Visita visita){
    visites.push_back(visita);
}

void Doctor::eliminarVisita(Visita visita){
    vector<Visita> aux(0, Visita(Data(), Pacient())); // L'inicialitzem sense elements, instanciats a visites buides
    bool found = false;
    int i = 0;
    while(not found and i < int(visites.size())){
        // Es copien tots els elements, fins el que es vol eliminar (aquest no el copiem)
        if(not (visites[i].getData() == visita.getData() and (visites[i].getPacient().mateixesDades(visita.getPacient())))){
            aux.push_back(visites[i]);
        }
        else{
            found = true;
        }
        ++i;
    }
    if(found){
        while(i < int(visites.size())){
            // Copia els elements restants
            aux.push_back(visites[i]);
            ++i;
        }
        visites = aux;
    }
    else{
        cout << "  error" << endl;
    }
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

//-----------
// L/E
//-----------

istream& operator>>(istream &is, Doctor &d){
    is >> d.nom;
    return is;
}

ostream& operator<<(ostream &os, Doctor &d){
    os << "  " << d.nom << endl;
    d.ordenarVisites();
    for(int i = 0; i < int(d.visites.size()); ++i){
        os << "  " << d.visites[i].getData().getDia() << "/" << d.visites[i].getData().getMes() << "/" << d.visites[i].getData().getAny() << " " << d.visites[i].getPacient().getNom() << endl;
    }
    return os;
}