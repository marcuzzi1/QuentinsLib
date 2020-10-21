// QuentinsLib.cpp : Définit les fonctions exportées de la DLL.
//
#include "pch.h"
#include "QuentinsLib.h"

// ============================================= FONCTIONS MATHEMATIQUES =============================================

/*
* #######################################################
* #                                                     #
* # Fonction retournant le PGCD de 2 entiers non signés #
* # Entrée : 2 nombres entiers non signés               #
* # Sortie : Un entier non signé                        #
* #                                                     #
* #######################################################
*/
// Attention ici les entiers sont non signés, veuillez vous assurer lors de la saisie qu'ils sont positifs, au risque d'avoir un résultat éronné
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
* #######################################################################################
* #                                                                                     #
* # Procédure contenant les instruction de la calculatrice (version si sinon imbriqués) #
* # Entrée : opérande sour la forme d'un caractère                                      #
* #          2 nombres réels                                                            #
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
					cout << "Operande inconnue ! " << endl;
				}
			}
		}
	}
}

/*
* ##########################################################################
* #                                                                        #
* # Procédure contenant les instruction de la calculatrice (version selon) #
* # Entrée : opérande sour la forme d'un caractère                         #
* #	         2 nombres réels                                               #
* # Sortie : Rien                                                          #
* #                                                                        #
* ##########################################################################
*/
void CalculatriceV2(char operande, float nb1, float nb2) {
	switch (operande) {
	case '+':
		cout << nb1 << " + " << nb2 << " = " << nb1 + nb2 << endl;
		break;
	case '-':
		cout << nb1 << " - " << nb2 << " = " << nb1 - nb2 << endl;
		break;
	case '*':
		cout << nb1 << " * " << nb2 << " = " << nb1 * nb2 << endl;
		break;
	case '/':
		if (nb2 != 0) {
			cout << nb1 << " / " << nb2 << " = " << nb1 / nb2 << endl;
		}
		else {
			cout << "Pas de division par 0 !" << endl;
		}
		break;
	default:
		cout << "Operande inconnue !" << endl;
		break;
	}
}

/*
* #################################################################
* #                                                               #
* # Fonction retournant le factoriel d'un nombre entier non signé #
* # Entrée : 1 entier non signé                                   #
* # Sortie : Le résultat du factoriel                             #
* #                                                               #
* #################################################################
*/

unsigned int Factoriel(unsigned int nbr) {
	unsigned int fact = 1;
	for (int i = 1; i <= nbr; i++) {
		fact *= i;
	}
	return fact;
}

// ============================================= MANIPULATION DE DATES =============================================

/*
* #########################################################################
* #                                                                       #
* # Fonction retournant un booléen pour la vérification d'une date saisie #
* # Entrée : une date sous le format de la structure de données Date      #
* # Sortie : 1 booléen                                                    #
* #                                                                       #
* #########################################################################
*/
// Veuillez utiliser la structure de données Date pour pouvoir faire appel à cette fonction
bool ValidDate(Date date) {
	if (date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12) {
		if (date.day > 31) {
			return false;
		}
	}
	else {
		if (date.month != 2 && date.month < 12) {
			if (date.day > 30) {
				return false;
			}
		}
		else {
			if (date.month == 2) {
				if (EstBissextile(date.year)) {
					if (date.day > 29) {
						return false;
					}
				}
				else {
					if (date.day > 28) {
						return false;
					}
				}
			}
			else {
				return false;
			}
		}
	}
	return true;
}

/*
* ###################################################################
* #                                                                 #
* # Fonction retournant un booléen à vrai si l'année est bissextile #
* # et faux si l'année ne l'est pas                                 #
* # Entrée : Un entier contenant l'année                            #
* # Sortie : Un booléen                                             #
* #                                                                 #
* ###################################################################
*/
// Cette fonction utilise seulement l'année envoyée avec date.year
bool EstBissextile(int annee) {
	if ((annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0) {
		return true;
	}
	return false;
}

/*
* ###############################################################################
* #                                                                             #
* # Fonction retournant une Date contenant le jour suivant de la Date en entrée #
* # Entrée : une Date (auparavant contrôlée !)                                  #
* # Sortie : La date suivante                                                   #
* #                                                                             #
* ###############################################################################
*/
Date DateSuivante(Date date) {
	Date suivante = date;
	if (date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12) {
		if (date.day < 31) {
			suivante.day++;
		}
		else {
			suivante.day = 1;
			if (date.month == 12) {
				suivante.month = 1;
				suivante.year++;
			}
			else {
				suivante.month++;
			}
		}
	}
	else {
		if (date.month != 2) {
			if (date.day < 30) {
				suivante.day++;
			}
			else {
				suivante.day = 1;
				suivante.month++;
			}
		}
		else {
			if (EstBissextile(date.year)) {
				if (date.day < 29) {
					suivante.day++;
				}
				else {
					suivante.day = 1;
					suivante.month++;
				}
			}
			else {
				if (date.day < 28) {
					suivante.day++;
				}
				else {
					suivante.day = 1;
					suivante.month++;
				}
			}
		}
	}
	return suivante;
}

/*
* ##########################################################
* #                                                        #
* # Procédure de saisie de date (véfification automatique) #
* # Entrée : Rien                                          #
* # Sortie : Rien                                          #
* # Entrée/Sortie : La Date à saisir                       #
* #                                                        #
* ##########################################################
*/
// Veuillez utiliser la structure Date pour que cette procédure fonctionne
void SaisirDate(Date& date) {
	bool valid = false;
	do {
		SaisirEntier(0, 31, "Saisir le jour : ", date.day);
		SaisirEntier(0, 12, "Saisir le mois : ", date.month);
		SaisirEntier(0, 65535, "Saisir l'annee : ", date.year);
		if (!ValidDate(date)) {
			cout << "La date saisie est invalide, reessayez svp !" << endl;
		}
		else {
			valid = !valid;
		}
	} while (!valid);
}

// ============================================= MANIPULAITONS DE VARIABLES =============================================

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
void SaisirEntier(int borne_inf, int borne_sup, string message, int& nbr) {
	cout << message;
	bool valid = false;
	do {
		cin >> nbr;
		if (cin.fail() || nbr < borne_inf || nbr > borne_sup) {
			cin.clear();
			cin.ignore();
			cout << "Saisie invalide, reessayez : ";
		}
		else if (nbr >= borne_inf && nbr <= borne_sup) {
			valid = !valid;
		}
	} while (!valid);
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
void SaisirReel(float borne_inf, float borne_sup, string message, float& nbr) { // À REFAIRE !
	cout << message;
	bool valid = false;
	do {
		cin >> nbr;
		if (cin.fail() || nbr < borne_inf || nbr > borne_sup) {
			cin.clear();
			cin.ignore();
			cout << "Saisie invalide, reessayez : ";
		}
		else if (nbr >= borne_inf && nbr <= borne_sup) {
			valid = !valid;
		}
	} while (!valid);
}

// ============================================= SPECIFIQUES AUX TP =============================================

/*
* ##################################################
* #                                                #
* # Procédure d'affichage d'une pyramide d'étoiles #
* # Entrée : Le nombre de lignes (entier)          #
* # Sortie : Rien                                  #
* # Entrée/Sortie : Rien                           #
* #                                                #
* ##################################################
* 
* Le nombre d'étoiles à afficher par ligne est déduit par la relation suivante :
* Soit i le numéro de l'étape de la première boucle POUR
* Soit hauteur la hauteur de pyramide saisie
* nombre d'étoiles = 1 + 2 (hauteur - (hauteur - (i - 1))
*                  = 1 + 2 (hauteur - (hauteur - i + 1))
*                  = 1 + 2 (hauteur - hauteur + i - 1)
*                  = 1 + 2 (i - 1)
*                  = 1 + 2i - 2
*                  = -1 + 2i
*/
// Attention à la largeur maximale de votre console !
void AfficherPyramide(int hauteur) {
	for (int i = 1; i <= hauteur; i++) {
		for (int j = 1; j <= (hauteur - i); j++) {
			cout << " ";
		}
		for (int j = 1; j <= (-1 + 2 * i); j++) {
			cout << "*";
		}
		cout << endl;
	}
}