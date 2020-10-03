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

/*
* ##############################################################################
* #                                                                            #
* # Procédure de saisie et de vérification d'un entier                         #
* # Entrée : Un booléen déterminant le signe                                   #
* #          Un booléen déterminant si les valeurs nulles sont acceptée ou non #
* #          Une chaîne de caractères contenant le message à afficher          #
* # Sortie : rien                                                              #
* # Entrée/Sortie : le nombre réel à saisir                                    #
* #                                                                            #
* ##############################################################################
*/
void SaisirEntier(bool signe, bool nul, string message, int& nbr) {
	if (signe) {
		if (nul) {
			cout << message;
			cin >> nbr;
		}
		else {
			do {
				cout << message;
				cin >> nbr;
				if (nbr == 0) {
					cout << "Les valeurs nulles ne sont pas acceptees ! " << endl;
					system("pause");
					system("cls");
				}
			} while (nbr == 0);
		}
	}
	else {
		if (nul) {
			do {
				cout << message;
				cin >> nbr;
				if (nbr < 0) {
					cout << "Les valeurs negatives ne sont pas acceptees ! " << endl;
					system("pause");
					system("cls");
				}
			} while (nbr < 0);
		}
		else {
			do {
				cout << message;
				cin >> nbr;
				if (nbr <= 0) {
					cout << "Les valeurs negatives ou nulles ne sont pas acceptees ! " << endl;
					system("pause");
					system("cls");
				}
			} while (nbr <= 0);
		}
	}
}

/*
* ##############################################################################
* #                                                                            #
* # Procédure de saisie et de vérification d'un réel                           #
* # Entrée : un booléen déterminant le signe                                   #
* #          un boléen déterminant si les valeurs nulles sont acceptées ou non #
* #          une chaîne de caractères contenant le message à afficher          #
* # Sortie : Rien                                                              #
* # Entrée/Sortie : le nombre réel à saisir                                    #
* #                                                                            #
* ##############################################################################
*/
void SaisirReel(bool signe, bool nul, string message, float& nbr) {
	if (signe) {
		if (nul) {
			cout << message;
			cin >> nbr;
		}
		else {
			do {
				cout << message;
				cin >> nbr;
				if (nbr == 0) {
					cout << "Les valeurs nulles ne sont pas acceptees." << endl;
					system("pause");
					system("cls");
				}
			} while (nbr == 0);
		}
	}
	else {
		if (nul) {
			do {
				cout << message;
				cin >> nbr;
				if (nbr < 0) {
					cout << "Les valeurs negatives ne sont pas acceptees." << endl;
					system("pause");
					system("cls");
				}
			} while (nbr < 0);
		}
		else {
			do {
				cout << message;
				cin >> nbr;
				if (nbr <= 0) {
					cout << "Les valeurs negatives ou nulles ne sont pas acceptees." << endl;
					system("pause");
					system("cls");
				}
			} while (nbr <= 0);
		}
	}
}

/*
* #######################################################################################
* #                                                                                     #
* # Procédure contenant les instruction de la calculatrice (version si sinon imbriqués) #
* # Entrée : opérande sour la forme d'un caractère                                      #
* #			 2 nombres réels                                                            #
* # Sortie : Rien                                                                       #
* #                                                                                     #
* #######################################################################################
*/
void CalculatriceV1(char operande, float nb1, float nb2) {
	if (operande == '+') {
		cout << nb1 << " + " << nb2 << " = " << nb1 + nb2 << endl;
	}
	else {
		if (operande == '-') {
			cout << nb1 << " - " << nb2 << " = " << nb1 - nb2 << endl;
		}
		else {
			if (operande == '*') {
				cout << nb1 << " * " << nb2 << " = " << nb1 * nb2 << endl;
			}
			else {
				if (operande == '/') {
					if (nb2 != 0) {
						cout << nb1 << " / " << nb2 << " = " << nb1 / nb2 << endl;
					}
					else {
						cout << "Pas de division par 0 ! " << endl;
					}
				}
				else {
					cout << "Opérande inconnue ! " << endl;
				}
			}
		}
	}
}