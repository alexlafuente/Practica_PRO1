#ifndef VISITA_HPP
#define VISITA_HPP
#include "Data.hpp"
#include "Pacient.hpp"

using namespace std;

/** Representació d'una visita.
 *
 *  Consta d'una data i d'un pacient.
 */

class Visita {
	
	private:
		Data data;
		Pacient pacient;
	
	public:
		//-------------
		// Constructors
		//-------------
		
		/* Pre: cert */
		/* Post: crea una visita amb els mateixos paràmetres que la visita 'v' */
		Visita(const Visita &v);
		
		/* Pre: cert */
		/* Post: crea una visita de data 'd' i pacient 'p' */
		Visita(Data d, Pacient p);
		
		// Destructor
		// Post: esborra automaticament els objectes locals en sortir d'un ambit de visibilitat
		~Visita();
		
		//-----------
		// Consultors
		//-----------

		/* Pre: cert */
		/* Post: retorna la data de la visita paràmetre implícit */
		Data getData() const;
		
		/* Pre: cert */
		/* Post: retorna el pacient de la visita paràmetre implícit */
		Pacient getPacient() const;
		
		//-------------
		// Modificadors
		//-------------
		
		/* Pre: cert */
		/* Post: crea una visita amb els mateixos paràmetres que la visita 'v' */
		Visita& operator=(const Visita &v);
};
#endif