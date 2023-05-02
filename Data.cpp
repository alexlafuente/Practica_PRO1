#include "Data.hpp"

//-------------
// Constructors
//-------------

Data::Data() {
}

Data::Data(int dia, int mes, int any) {
    this->dia = dia;
    this->mes = mes;
    this->any = any;
}

Data::~Data(){
    
}

//-----------
// Consultors
//-----------

int Data::getDia() const {
    return dia;
}

int Data::getMes() const {
    return mes;
}

int Data::getAny() const {
    return any;
}

bool Data::operator==(const Data &data) {
	return dia == data.dia  and  mes == data.mes  and  any == data.any;
}

bool Data::operator<(const Data &data) {
	return dia < data.dia  or (dia == data.dia and mes < data.mes) or (dia == data.dia and mes == data.mes and any < data.any);
}

bool Data::esPrevia(Data &data){
    bool esPrevi = false;
    if(this->any < data.any){
        esPrevi = true;
    }
    else if(this->any == data.any and this->mes < data.mes){
        esPrevi = true;
    }
    else if(this->any == data.any and this->mes == data.mes and this->dia < data.dia){
        esPrevi = true;
    }
    return esPrevi;
}

//-----------
// L/E
//-----------
		
istream& operator>>(istream &is, Data &data) {
	is >> data.dia >> data.mes >> data.any;
	return is;
}
		
ostream& operator<<(ostream &os, const Data &data) {
	os << data.dia << " " << data.mes << " " << data.any;
  return os;
}
