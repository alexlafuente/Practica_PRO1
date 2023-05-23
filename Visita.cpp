#include "Visita.hpp"

//-------------
// Constructors
//-------------

Visita::Visita(const Visita &v){
    this->data = v.getData();
    this->pacient = v.getPacient();
}

Visita::Visita(Data d, Pacient p) {
    this->data = d;
    this->pacient = p;
}

Visita::~Visita(){
    
}

//-----------
// Consultors
//-----------

Data Visita::getData() const {
    return data;
}

Pacient Visita::getPacient() const {
    return pacient;
}


//-------------
// Modificadors
//-------------

Visita& Visita::operator=(const Visita &v){
    this->data = v.getData();
    this->pacient = v.getPacient();
    return *this;
}