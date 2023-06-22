[![GPLv3 License](https://img.shields.io/badge/License-GPL%20v3-yellow.svg)](https://opensource.org/licenses/)

[![Logo](https://camo.githubusercontent.com/824ab59f0f7eff5585ea26cb01600b956575c85b87824e362738a74cd52c0c06/68747470733a2f2f7777772e7570632e6564752f636f6d756e69636163696f2f63612f6964656e74697461742f646573636172726567612d6172786975732d677261666963732f666974786572732d6d617263612d7072696e636970616c2f7570632d706f73697469752d70333030352e706e67)](https://www.upc.edu/ca)

# Pràctica (PRO1) - Sistema de Gestió de Pacients d'un Hospital

Aquest projecte conforma la pràctica de PRO1 a l'EPSEVG (UPC).

El sistema de gestió de pacients compta amb un registre amb tota la informació dels pacients de l'hospital, una cua de pacients del servei d'urgències, i una llista dels doctors i la seva informació.

### Doctor

Cada doctor compta amb un nom i una agenda de visites, que emmagatzema les visites programades pels pacients (el nom d'aquests i les dates).

### Pacient

Cada pacient compta amb un nom, edat, motiu d'accés a l'hospital, i un nombre (natural de l'1 al 3) que indica el nivell de gravetat de l'afecció del pacient.

### Registre de pacients

El registre de pacients, és un arbre binari de cerca (BST) de pacients, que els ordena en base a l'ordre alfabètic dels seus noms.

### Cua de pacients del servei d'urgències

La cua de pacients, ordena els pacients del servei d'urgències, tenint en compte el nivell de gravetat de cadascun. Una vegada son tractats, s'eliminen d'aquesta cua, però no necessàriament del registre de
pacients.

# Instruccions del programa

Una vegada executat el programa, les instruccions disponibles són les següents:

- ```alta_pacient``` S’introdueix les dades d’un pacient (nom complet, edat, motiu de
l’ingrés i gravetat). Si el pacient ja existeix al sistema, es produeix un error; sinó,
el pacient és donat d’alta al sistema i és afegit a la llista d’espera en funció de la
gravetat del seu estat de salut.

- ```baixa_pacient``` S’introdueix el nom d’un pacient. Si el pacient no existeix, es produeix
un error. En cas contrari, el pacient es dona de baixa del sistema completament, per
tant, també cal donar-lo de baixa de la llista d’espera i cancel·lar totes les visites que
pogués tenir programades (si és el cas).

- ```alta_doctor``` S’introdueix el nom del doctor/a, que farà d’identificador. Si ja existeix
al sistema, es produeix un error. En cas contrari, el doctor/a és donat d’alta al
sistema.

- ```llista_espera``` No té paràmetres. S’escriuen les dades de tots els pacients que constin
a la llista d’espera.

- ```tractar_seguent_pacient``` No té paràmetres. Si no hi ha cap pacient a la llista
d’espera, es produeix un error; sinó, s’elimina el primer pacient de la llista d’espera,
però no es dona de baixa del sistema.

- ```modificar_estat_pacient``` ’introdueix el nom d’un pacient i el nou nivell de gra-
vetat. Si el pacient no existeix al sistema o el nivell de gravetat no és vàlid, es
produeix un error; sinó, s’actualitza el valor de gravetat del pacient al sistema i es
ressitua el pacient en la llista d’espera en funció del nou nivell de gravetat.

- ```programar_visita``` S’introdueix el nom d’un pacient, el nom d’un doctor i una
data. Si el pacient o el doctor no existeixen al sistema, es produeix un error; sinó,
s’afegeix una nova visita al doctor amb el pacient i data indicats. Sempre serà possible
afegir una nova visita a qualsevol doctor del sistema, encara que ja tingui altres visites
programades per la mateixa data.

- ```cancellar_visita``` S’introdueix el nom d’un pacient, el nom d’un doctor i una
data. Si el pacient o el doctor no existeixen al sistema, o bé la visita a cancel·lar no
havia estat programada, es produeix un error; sinó, s’elimina la visita al doctor amb
el pacient i data indicats.

- ```mostrar_programacio_visites``` No té paràmetres. Per cada doctor que hi hagi en el
sistema, s’escriu el seu nom i la llista de visites (data i nom pacient) que té programades
ordenada per data. En cas què hagi dues dates coincidents, s’escriuen segons l’ordre
en què hagin estat introduïdes al sistema.

- ```fi``` No té paràmetres. S’acaba l’execució de la simulació.
