#include "Visita.hpp"

//-------------
// Constructors
//-------------

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
