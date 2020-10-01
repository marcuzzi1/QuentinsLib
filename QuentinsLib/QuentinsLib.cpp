// QuentinsLib.cpp : Définit les fonctions exportées de la DLL.
//
#include "pch.h"
#include "QuentinsLib.h"

/*
* #######################################################
* #                                                     #
* # Fonction retournant le PGCD de 2 entiers non signés #
* # Entrée : 2 nombres entiers non signés               #
* # Sortie : Un entier non signé                        #
* #                                                     #
* #######################################################
*/
unsigned int PGCD(unsigned int a, unsigned int b) {
	while (a != b) {
		if (a > b) {
			a -= b;
		}
		else {
			b -= a;
		}
	}
	return a;
}

/*
* #########################################################################
* #                                                                       #
* # Fonction retournant un booléen pour la vérification d'une date saisie #
* # Entrée : 3 entiers (jj, mm, aaaa)                                     #
* # Sortie : 1 booléen                                                    #
* #                                                                       #
* #########################################################################
*/
bool ValidDate(int jj, int mm, int aaaa) {

	return true;
}