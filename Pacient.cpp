#include "Pacient.hpp"

/* Pre: cert */
/* Post: crea un pacient buit */		
Pacient Pacient::Pacient(){
    nom = "";
    edat = 0;
    motiu = "";
    gravetat = 0;
    return *this;
}

/* Pre: cert */
/* Post: crea un pacient de nom 'nom' */	
Pacient Pacient::Pacient(string nom){
    this->nom = nom;
    edat = 0;
    motiu = "";
    gravetat = 0;
    return *this;
}

/* Pre: cert */
/* Post: crea un pacient amb els valors de 'nom',
    'edat', 'motiu' i 'gravetat' rebuts per paràmetre */
Pacient Pacient::Pacient(string nom, int edat, string motiu, int gravetat){
    this->nom = nom;
    this->/edat = edat;
    this->motiu = motiu;
    this->gravetat = gravetat;
    return *this;
}

//-------------
// Modificadors
//-------------

/* Pre: cert */
/* Post: el valor de gravetat del pacient paràmetre 
    implícit	passa a ser el valor de 'gravetat' */
void Pacient::actualitzaEstat(int gravetat){
    this->gravetat = gravetat;
}

//-----------
// Consultors
//-----------

/* Pre: cert */
/* Post: retorna el nom del pacient paràmetre implicit */
string Pacient::getNom() const{
    return nom;
}

/* Pre: cert */
/* Post: retorna l'edat del pacient paràmetre implicit */
int Pacient::getEdat() const{
    return edat;
}

/* Pre: cert */
/* Post: retorna el motiu de l'ingrés del pacient paràmetre 
    implicit */
string Pacient::getMotiu() const{
    return motiu;
}

/* Pre: cert */
/* Post: retorna la gravetat de l'estat del pacient paràmetre
    implicit */		
int Pacient::getGravetat() const{
    return gravetat;
}

/* Pre: cert */
/* Post: retorna un booleà que indica si l'estat de gravetat
    del pacient paràmetre implícit i el del pacient 'p' són
    identics (true) o no ho són (false) */
bool Pacient::compare(const Pacient &p) const{
    bool igual = false;
    if(this->gravetat == p.getGravetat()){
        igual = true;
    }
    return igual;
}


// PODEU AFEGIR ELS MÈTODES QUE NECESSITEU


//-----------
// L/E
//-----------

/* Pre: estan preparats al canal estàndard d'entrada quatre valors
    en aquest ordre - string, enter, string i enter */
/* Post: el pacient 'p' passa a tenir els valors llegits del canal
    estàndard d'entrada com a nom, edat, motiu i gravetat, 
    respectivament */			
istream& operator>>(istream &is, Pacient &p){
    is >> p.nom >> p.edat >> p.motiu >> p.gravetat;
    return is;
}

/* Pre: cert */
/* Post: s'han escrit els atributs nom, edat, motiu i gravetat del
    pacient 'p' al canal estàndard de sortida */
ostream& operator<<(ostream &os, const Pacient &p){
    os << p.nom << " | " << p.edat << " | " << p.motiu << " | " << p.gravetat << endl;
    return os;
}