#include "Hospital.hpp"

using namespace std;

//-------------
// Constructors
//-------------

Hospital::Hospital(){
    llistaEspera = PriorityQueue<Pacient>();
    pacients = BST<Pacient>();
    doctors = vector<Doctor>(0);
}

Hospital::Hospital(const PriorityQueue<Pacient> &llistaEspera, const BST<Pacient> &pacients, const vector<Doctor> &doctors){
    this->llistaEspera = llistaEspera;
    this->pacients = pacients;
    this->doctors = doctors;
}

~Hospital(){
    
}

//-------------
// Consultors
//-------------

PriorityQueue<Pacient> Hospital::getLlistaEspera() const{
    return llistaEspera;
}

//-------------
// Modificadors
//-------------

void Hospital::afegirPacient(const Pacient &p){
    pair<bool, Pacient> aux = pacients.find(p);
    if(aux.first){
        pacients.insert(p);
        llistaEspera.push(p);
    }
    else{
        cout << "  error" << endl;
    }
}

void Hospital::eliminarPacient(const string &s){
    Pacient p(s); // Creem pacient, només amb nom, per fer la cerca al BST
    pair<bool, Pacient> aux = pacients.find(p); // Trobem el pacient al qual fa refèrencia el nom
    if(aux.first){
        pacients.remove(pair.second);
        llistaEspera.remove(pair.second);
        doctors.eliminarVisites(s);
    }
    else{
        cout << "  error" << endl;
    }
}

void Hospital::afegirDoctor(const string &s){
    bool found = false;
    int i = 0;
    while(not found and i < int(doctors.size())){
        if(doctors.getName() == s){
            found = true;
        }
        else{
            ++i;
        }
    }
    if(not found){
        doctors.push_back(Doctor(s));
    }
    else{
        cout << "  error" << endl;
    }
}

void Hospital::tractarSeguent(){
    if(int(llistaEspera.size()) != 0){
        llistaEspera.pop();
    }
    else{
        cout << "  error" << endl;
    }
}

void Hospital::modificarPacient(const string &s, int &g){
    if(g >= 1 and g <= 3){
        Pacient p(s); // Creem pacient, només amb nom, per fer la cerca al BST
        pair<bool, Pacient> aux = pacients.find(p); // Trobem el pacient al qual fa refèrencia el nom
        if(aux.first){
            pacients.setValue(aux.second(), g);
            llistaEspera.remove(aux.second());
            llistaEspera.push(aux.second.actualitzaEstat(g)); // Actualitzem pacient amb la nova gravetat, i l'afegim de manera que s'ordeni automàticament
        }
    }
    else{
        cout << "  error" << endl;
    }
}

void Hospital::afegirVisita(const &string &s, const string &doc, const Data &data){
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
            doctors[i].afegirVisita(Visita(data, aux.second)) // creem una visita amb la constructora que rep per paràmetre una data i un pacient
        }
    }
    else{
        cout << "  error" << endl;
    }
}

void Hospital::eliminarVisita(const &string &p, const string &doc, const Data &data){
    
}