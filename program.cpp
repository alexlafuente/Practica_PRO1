#include <iostream>
#include "Hospital.hpp"

using namespace std;

/** Programa principal
 *
 * main() crea l'hospital, fa la lectura d'instruccions i
 * l'escriptura de resultats. Les operacions estan definides i
 * implementades en les classes Hospital, Pacient, Doctor, Visita,
   Data, PriorityQueue i BST
 */

int main() {
	// Crear un hospital
	Hospital h;
	
	// Processar instruccions
    string inst;
    while ((cin >> inst) and (inst != "fi")) {
        if (inst == "alta_pacient") {
        	Pacient p;
        	cin >> p;
        	h.afegirPacient(p);
        } 
        else if (inst == "baixa_pacient") {
            string nom;
            cin >> nom;
			h.eliminarPacient(nom);
        } 
        else if (inst == "alta_doctor") {
            string doctor;
            cin >> doctor;
			h.afegirDoctor(doctor);
        } 
        else if (inst == "llista_espera") {
           	h.mostrarLlistaEspera();
        }
        else if (inst == "tractar_seguent_pacient") {
            h.tractarSeguent();
        }
        else if (inst == "modificar_estat_pacient") {
            string nom;
            int gravetat;
            cin >> nom >> gravetat;
			h.modificarPacient(nom, gravetat);
        }
        else if (inst == "programar_visita") {
            string nom, doctor;
            Data data;
            cin >> nom >> doctor >> data; 
			h.afegirVisita(nom, doctor, data);
        }
        else if (inst == "cancellar_visita") {
            string nom, doctor;
            Data data;
            cin >> nom >> doctor >> data;
			h.eliminarVisita(nom, doctor, data);	
        }
        else if (inst == "mostrar_programacio_visites") { 
			h.mostrarVisites();
        }
        else {
            cout << inst << endl;
            cout << "  error" << endl;
        }
		
    }
    cout << "fi" << endl;
}