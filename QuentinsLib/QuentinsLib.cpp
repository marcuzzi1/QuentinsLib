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
* ############################################################################################
* #                                                                                          #
* # Fonction retournant un entier permettant de faciliter l'étape de saisie et vérifications #
* # Entrée : booléen permettant d'indiquer le signe (true pour positif / false pour le reste #
* #          Chaîne de caractères contenant le message à afficher                            #
* # Sortie : entier                                                                          #
* #                                                                                          #
* ############################################################################################
*/
int SaisirEntier(bool positif, string message) {
	int nbr;
	if (positif) {
		do {
			cout << message;
			cin >> nbr;
			if (nbr < 0) {
				cout << "Les nombres négatifs ne sont pas acceptés !" << endl;
				system("pause");
				system("cls");
			}
		} while (nbr < 0);
	}
	else {
		cout << message;
		cin >> nbr;
	}
	return nbr;
}
