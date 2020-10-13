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
* #########################################################################
* #                                                                       #
* # Fonction retournant un booléen pour la vérification d'une date saisie #
* # Entrée : une date sous le format de la structure de données Date      #
* # Sortie : 1 booléen                                                    #
* #                                                                       #
* #########################################################################
*/
// Veuillez utiliser la structure de données Date pour pouvoir faire appel à cette fonction
bool ValidDate(int jj, int mm, int aaaa) { // À REFAIRE !
	if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) {
		if (jj > 31) {
			return false;
		}
	}
	else {
		if (mm != 2 && mm < 12) {
			if (jj > 30) {
				return false;
			}
		}
		else {
			if (mm == 2) {
				if (EstBissextile(aaaa)) {
					if (jj > 29) {
						return false;
					}
				}
				else {
					if (jj > 28) {
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
bool EstBissextile(int aaaa) { // À REFAIRE !
	if ((aaaa % 4 == 0 && aaaa % 100 != 0) || aaaa % 400 == 0) {
		return true;
	}
	return false;
}

Date DateSuivante(Date date) {
	Date suivante = date;
	int jour = suivante.day;
	int mois = suivante.month;
	int annee = suivante.year;
	return suivante;
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
void SaisirEntier(bool signe, bool nul, string message, int& nbr) { // À REFAIRE !
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
void SaisirReel(bool signe, bool nul, string message, float& nbr) { // À REFAIRE !
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
	case '+' :
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

