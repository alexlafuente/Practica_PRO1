#include "Hospital.hpp"

using namespace std;

//-------------
// Constructors
//-------------

Hospital::Hospital(){
    llistaEspera = Queue<Pacient>();
    pacients = BST<Pacient>();
    doctors = vector<Doctor>(0);
}

Hospital::Hospital(const Queue<Pacient> &llistaEspera, const BST<Pacient> &pacients, const vector<Doctor> &doctors){
    this->llistaEspera = llistaEspera;
    this->pacients = pacients;
    this->doctors = doctors;
}

Hospital::~Hospital(){
    
}

//-------------
// Consultors
//-------------

void Hospital::mostrarLlistaEspera() const{
    cout << "llista_espera" << endl;
    if(not this->llistaEspera.empty()){
        cout << "  " << llistaEspera;
    }
}

//-------------
// Modificadors
//-------------

void Hospital::afegirPacient(const Pacient &p){
    cout << "alta_pacient " << p << endl;
    pair<bool, Pacient> aux = pacients.find(p);
    if(not aux.first and not (p.mateixesDades(aux.second))){
        llistaEspera.push(p);
        pacients.insert(p);
    }
    else{
        cout << "  error" << endl;
    }
}

void Hospital::eliminarPacient(const string &s){
    cout << "baixa_pacient " << s << endl;
    Pacient p(s); // Creem pacient, només amb nom, per fer la cerca al BST
    pair<bool, Pacient> aux = pacients.find(p); // Trobem el pacient al qual fa refèrencia el nom
    if(aux.first){
        llistaEspera.remove(aux.second); // Eliminem el pacient de la llista d'espera
        for(int i = 0; i < int(doctors.size()); ++i){ // Eliminem de les agendes dels doctors, totes les visites programades aquest per pacient
            doctors[i].eliminarVisites(aux.second);
        }
        pacients.remove(aux.second); // Eliminem el pacient del sistema
    }
    else{
        cout << "  error" << endl;
    }
}

void Hospital::afegirDoctor(const string &s){
    cout << "alta_doctor " << s << endl;
    bool found = false;
    int i = 0;
    while(not found and i < int(doctors.size())){
        if(doctors[i].getName() == s){
            found = true;
        }
        else{
            ++i;
        }
    }
    if(not found){
        doctors.push_back(Doctor(s)); // Afegim un nou element al vector de doctors, utilitzant la constructora de la classe 'Doctor' que rep una string
    }
    else{
        cout << "  error" << endl;
    }
}

void Hospital::tractarSeguent(){
    cout << "tractar_seguent_pacient" << endl;
    if(int(llistaEspera.size()) != 0){
        llistaEspera.pop();
    }
    else{
        cout << "  error" << endl;
    }
}

void Hospital::modificarPacient(const string &s, int &g){
    cout << "modificar_estat_pacient " << s << " "<< g << endl;
    if(g >= 1 and g <= 3){
        Pacient p(s); // Creem pacient, només amb nom, per fer la cerca al BST
        pair<bool, Pacient> aux = pacients.find(p); // Trobem el pacient al qual fa refèrencia el nom
        if(aux.first){
            pacients.setValue(aux.second, Pacient(aux.second.getNom(), aux.second.getEdat(), aux.second.getMotiu(), g));
            llistaEspera.remove(aux.second);
            aux.second.actualitzaEstat(g); // Actualitzem pacient amb la nova gravetat
            llistaEspera.push(aux.second); // Afegim el pacient, de manera que s'ordeni automàticament
        }
        else{
            cout << "  error" << endl;
        }
    }
    else{
        cout << "  error" << endl;
    }
}

void Hospital::afegirVisita(const string &s, const string &doc, Data &data){
    cout<< "programar_visita "<< s <<" "<< doc << " " << data << endl;
    Pacient p(s); // Creem pacient, només amb nom, per fer la cerca al BST
    pair<bool, Pacient> aux = pacients.find(p); // Trobem el pacient al qual fa refèrencia el nom
    if(aux.first){
        // Trobem el doctor de nom doc
        bool found = false;
        int i = 0;
        while(not found and i < int(doctors.size())){
            if(doctors[i].getName() == doc){
                found = true;
            }
            else{
                ++i;
            }
        }
        if(found){
            doctors[i].afegirVisita(Visita(data, aux.second)); // creem una visita amb la constructora que rep per paràmetre una data i un pacient
        }
        else{
            cout << "  error" << endl;
        }
    }
    else{
        cout << "  error" << endl;
    }
}

void Hospital::eliminarVisita(const string &s, const string &doc, Data &data){
    cout << "cancellar_visita " << s << " " << doc << " " << data << endl;
    Pacient p(s); // Creem pacient, només amb nom, per fer la cerca al BST
    pair<bool, Pacient> aux = pacients.find(p); // Trobem el pacient al qual fa refèrencia el nom
    if(aux.first){
        // Trobem el doctor de nom doc
        bool found = false;
        int i = 0;
        while(not found and i < int(doctors.size())){
            if(doctors[i].getName() == doc){
                found = true;
            }
            else{
                ++i;
            }
        }
        if(found){
            doctors[i].eliminarVisita(Visita(data, aux.second)); // creem una visita amb la constructora que rep per paràmetre una data i un pacient
        }
        else{
            cout << "  error" << endl;
        }
    }
    else{
        cout << "  error" << endl;
    }
}

void Hospital::mostrarVisites(){
    cout<< "mostrar_programacio_visites " << endl;
    if(doctors.size() > 0){
        for(int i = 0; i < int(doctors.size()); ++i){
            cout << doctors[i];
        }
    }
}