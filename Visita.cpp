#include "Visita.hpp"

//-------------
// Constructors
//-------------

Visita::Visita(const Data &d, const Pacient &p) {
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
