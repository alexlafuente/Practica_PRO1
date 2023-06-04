#ifndef PACIENT_HPP
#define PACIENT_HPP
#include <string>
#include <iostream>

using namespace std;

/** Representació d'un pacient.
 *
 *  Consta de quatre atributs per emmagatzemar el nom (string),
 *  edat (enter), motiu de l'ingrés (string) i gravetat de 
 *  l'estat de salut (int) d'un pacient.
 */
 
class Pacient {
	
	private:
		string nom;
		int edat;
		string motiu;
		int gravetat;  // int gravetat;  // {alta=1, mitjana=2, baixa=3}
	
	public:
		//-------------
		// Constructors
		//-------------
		
		/* Pre: cert */
		/* Post: crea un pacient buit */		
		Pacient();
		
		/* Pre: cert */
		/* Post: crea un pacient de nom 'nom' */	
		Pacient(string nom);
		
		/* Pre: cert */
		/* Post: crea un pacient amb els valors de 'nom',
           'edat', 'motiu' i 'gravetat' rebuts per paràmetre */
		Pacient(string nom, int edat, string motiu, int gravetat);
		
		/* Pre: cert */
		/* Post: crea un pacient amb els mateixos paràmetres que el pacient 'p' */
		Pacient(const Pacient &p);
		
		// Destructor
		// Post: esborra automaticament els objectes locals en sortir d'un ambit de visibilitat
		~Pacient();
		
		//-------------
		// Modificadors
		//-------------

		/* Pre: cert */
		/* Post: el valor de gravetat del pacient paràmetre 
		   implícit	passa a ser el valor de 'gravetat' */
		void actualitzaEstat(int gravetat);
		
		/* Pre: cert */
		/* Post: retorna un pacient amb els mateixos paràmetres que el pacient 'p' */
		Pacient& operator=(const Pacient &p);
		
		//-----------
		// Consultors
		//-----------

		/* Pre: cert */
		/* Post: retorna el nom del pacient paràmetre implicit */
		string getNom() const;

		/* Pre: cert */
		/* Post: retorna l'edat del pacient paràmetre implicit */
		int getEdat() const;

		/* Pre: cert */
		/* Post: retorna el motiu de l'ingrés del pacient paràmetre 
		   implicit */
		string getMotiu() const;

		/* Pre: cert */
		/* Post: retorna la gravetat de l'estat del pacient paràmetre
		   implicit */		
		int getGravetat() const;
		
		/* Pre: cert */
		/* Post: retorna un booleà que indica si l'estat de gravetat
		   del pacient paràmetre implícit i el del pacient 'p' és
		   inferior (true) o no ho és (false) */
		bool compare(const Pacient &p) const;
		
		/* Pre: cert */
		/* Post: retorna un booleà que indica si el pacient paràmetre
		   implícit i el pacient 'p' rebut són idèntics (true)
		   o no ho són (false)*/
		bool mateixesDades(const Pacient &p) const;
		
		/* Pre: cert */
		/* Post: retorna un booleà que indica si el pacient paràmetre
		   implícit i el pacient 'p' rebut són idèntics (true)
		   o no ho són (false), només tenint en compte els noms */
		bool operator==(Pacient p) const;
		
		/* Pre: cert */
		/* Post: retorna un booleà que indica si el pacient paràmetre
		   implícit és inferior al pacient 'p' rebut (true) o
		   no ho és (false), en base a l'ordenació alfabètica dels noms d'aquests */
		bool operator<(Pacient p) const;
		
		/* Pre: cert */
		/* Post: retorna un booleà que indica si el pacient paràmetre
		   implícit és superior al pacient 'p' rebut (true) o
		   no ho és (false), en base a l'ordenació alfabètica dels noms d'aquests */
		bool operator>(Pacient p) const;
		
		
		//-----------
		// L/E
		//-----------
		
		/* Pre: estan preparats al canal estàndard d'entrada quatre valors
		   en aquest ordre - string, enter, string i enter */
		/* Post: el pacient 'p' passa a tenir els valors llegits del canal
		   estàndard d'entrada com a nom, edat, motiu i gravetat, 
		   respectivament */			
		friend istream& operator>>(istream &is, Pacient &p);
		
		/* Pre: cert */
		/* Post: s'han escrit els atributs nom, edat, motiu i gravetat del
           pacient 'p' al canal estàndard de sortida */
		friend ostream& operator<<(ostream &os, const Pacient &p); 
};
#endif