#include "Pacient.hpp"

//-------------
// Constructors
//-------------

Pacient::Pacient(){
    nom = "";
    edat = 0;
    motiu = "";
    gravetat = 0;
}

Pacient::Pacient(string nom){
    this->nom = nom;
    edat = 0;
    motiu = "";
    gravetat = 0;
}


Pacient::Pacient(string nom, int edat, string motiu, int gravetat){
    this->nom = nom;
    this->edat = edat;
    this->motiu = motiu;
    this->gravetat = gravetat;
}

Pacient::Pacient(const Pacient &p){
    this->nom = p.getNom();
    this->edat = p.getEdat();
    this->motiu = p.getMotiu();
    this->gravetat = p.getGravetat();
}

Pacient::~Pacient(){
    
}

//-------------
// Modificadors
//-------------

void Pacient::actualitzaEstat(int gravetat){
    this->gravetat = gravetat;
}

Pacient& Pacient::operator=(const Pacient &p){
    this->nom = p.getNom();
    this->edat = p.getEdat();
    this->motiu = p.getMotiu();
    this->gravetat = p.getGravetat();
    return *this;
}

//-----------
// Consultors
//-----------

string Pacient::getNom() const{
    return nom;
}

int Pacient::getEdat() const{
    return edat;
}

string Pacient::getMotiu() const{
    return motiu;
}

int Pacient::getGravetat() const{
    return gravetat;
}

bool Pacient::compare(const Pacient &p) const{
    return this->gravetat < p.getGravetat();
}

bool Pacient::mateixesDades(const Pacient &p) const{
    return this->nom == p.getNom() and this->edat == p.getEdat() and this->motiu == p.getMotiu() and this->gravetat == p.getGravetat();
}

bool Pacient::operator==(Pacient p) const{
    return this->nom == p.getNom();
}

bool Pacient::operator<(Pacient p) const{
    return this->nom < p.getNom();
}

bool Pacient::operator>(Pacient p) const{
    return this->nom > p.getNom();
}

//-----------
// L/E
//-----------

istream& operator>>(istream &is, Pacient &p){
    is >> p.nom >> p.edat >> p.motiu >> p.gravetat;
    return is;
}

ostream& operator<<(ostream &os, const Pacient &p){
    os << p.nom << "  " << p.edat << " " << p.motiu << " " << p.gravetat;
    return os;
}