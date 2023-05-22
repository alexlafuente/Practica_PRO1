#include "Pacient.hpp"

//-------------
// Constructors
//-------------

/* Pre: cert */
/* Post: crea un pacient buit */		
Pacient::Pacient(){
    nom = "";
    edat = 0;
    motiu = "";
    gravetat = 0;
}

/* Pre: cert */
/* Post: crea un pacient de nom 'nom' */	
Pacient::Pacient(string nom){
    this->nom = nom;
    edat = 0;
    motiu = "";
    gravetat = 0;
}

/* Pre: cert */
/* Post: crea un pacient amb els valors de 'nom',
    'edat', 'motiu' i 'gravetat' rebuts per paràmetre */
Pacient::Pacient(string nom, int edat, string motiu, int gravetat){
    this->nom = nom;
    this->edat = edat;
    this->motiu = motiu;
    this->gravetat = gravetat;
}

// Destructor
// Post: esborra automaticament els objectes locals en sortir d'un ambit de visibilitat
Pacient::~Pacient(){
    
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
    return this->gravetat < p.getGravetat();
}

bool Pacient::mateixesDades(const Pacient &p) const{
    return this->nom == p.getNom() and this->edat == p.getEdat() and this->motiu == p.getMotiu() and this->gravetat == p.getGravetat();
}

bool Pacient::operator==(Pacient p) const{
    return this->nom == p.getNom();
}

/* Pre: cert */
/* Post: retorna un booleà que indica si el pacient paràmetre
    implícit és anterior al pacient 'p' rebut (true) o
    no ho és (false), en base a l'ordenació alfabètica dels noms d'aquests */
bool Pacient::operator<(Pacient p) const{
    return this->nom < p.getNom();
}

bool Pacient::operator>(Pacient p) const{
    return this->nom > p.getNom();
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
    os << p.nom << "  " << p.edat << " " << p.motiu << " " << p.gravetat << endl;
    return os;
}