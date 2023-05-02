#include "Visita.hpp"

//-------------
// Constructors
//-------------

Visita::Visita(const Data &data, const Pacient &pacient) {
    this->data = data;
    this->pacient = pacient;
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
