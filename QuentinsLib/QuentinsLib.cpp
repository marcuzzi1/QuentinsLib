// QuentinsLib.cpp : Définit les fonctions exportées de la DLL.
//
#include "pch.h"
#include "QuentinsLib.h"
#include<iostream>
#include<algorithm>
#include<stdarg.h>
using namespace std;

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

/*
* ###########################################################################################
* #                                                                                         #
* # Fonction retournant un booléen à vrai si le nombre en paramètre est parfait, faux sinon #
* # Entrée : Un nombre entier                                                               #
* # Sortie : un booléen                                                                     #
* #                                                                                         #
* ###########################################################################################
*/
bool EstParfait(int nombre) {
	return (nombre == SommeDiviseurs(nombre));
}

/*
* #######################################################################################################
* #                                                                                                     #
* # Fonction retournant la somme de tous les diviseurs d'un nombre passé en paramètre (lui-même) exclus #
* # Entrée : un nombre entier                                                                           #
* # Sortie : la somme de ses diviseurs (entier)                                                         #
* #                                                                                                     #
* #######################################################################################################
*/
int SommeDiviseurs(int nombre) {
	int somme = 0;
	for (int i = 1; i < nombre; i++) {
		if (nombre % i == 0) {
			somme += i;
		}
	}
	return somme;
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
* # Entrée/Sortie : le nombre entier à saisir                                  #
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
* #############################################
* #                                           #
* # Procédure de saisie d'un entier non borné #
* # Entrée : un message à afficher            #
* # Sortie : rien                             #
* # Entrée/Sortie : le nombre entier à saisir #
* #                                           #
* #############################################
*/
void SaisirEntier(string message, int& nbr) {
	cout << message;
	bool valid = false;
	do {
		cin >> nbr;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Saisie invalide, reessayez : ";
		}
		else {
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
void SaisirReel(float borne_inf, float borne_sup, string message, float& nbr) {
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

void SaisirChaine(string message, string& chaine) {
	cout << message;
	bool valid = false;
	do {
		cin >> chaine;
		if (cin.fail()) {
			cout << "Probleme lors de la saisie, reessayez svp : ";
		}
		else {
			valid = !valid;
		}
	} while (!valid);
}

int nombreVoyelles(string mot) {
	int nb = 0;
	for (int i = 0; i < mot.length(); i++) {
		mot[i] = (char)tolower(mot[i]);
	}
	for (char mychar : mot) {
		switch (mychar) {
		case 'a':
			nb++;
			break;
		case 'e':
			nb++;
			break;
		case 'i':
			nb++;
			break;
		case 'o':
			nb++;
			break;
		case 'u':
			nb++;
			break;
		case 'y':
			nb++;
			break;
		default:
			break;
		}
	}
	return nb;
}

bool estUnPalindrome(string nom) {
	string nom_inverse = "";
	// On met le mot en minuscule pour éviter les conflits
	for (int i = 0; i < nom.length(); i++) {
		nom[i] = tolower(nom[i]);
	}
	for (int i = nom.length() - 1; i >= 0; i--) {
		nom_inverse += nom[i];
	}
	if (nom_inverse == nom) {
		return true;
	}
	return false;
}

void AfficherTableauEntiers(vector<int> tab) {
	for (int i = 0; i < tab.size(); i++) {
		cout << tab[i];
		if (i < tab.size() - 1) {
			cout << " | ";
		}
	}
	cout << endl;
}

void TriABulleTableauEntiers(vector<int>& tab) {
	int passage = 0;
	bool permut;
	do {
		permut = false;
		for (int i = 0; i < tab.size() - 1 - passage; i++) {
			try {
				if (tab[i] >= tab[i + 1]) {
					swap(tab[i], tab[i + 1]);
					permut = true;
				}
			}
			catch (exception e) {
				cerr << "ERR : execution failed, aborting." << endl;
				return; // Quitte de façon directe la procédure
			}
		}
		passage++;
	} while (permut);
}

// ============================================= SPECIFIQUES =============================================

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

// ============================================= Classes d'objets : =============================================

// Menu :
/*
* Cette classe sert à créer, afficher et effectuer des choix en allégeant le programme principal de l'affichage répétitif.
* Pour l'instancier vous devez lui passer en paramètre un 'vector' (tableau à dimension variable) contenant la liste des choix possibles.
* Le traitement en fonction de ces choix est à faire dans votre programme principal.
* La numérotation est automatique.
* Pour effectuer un choix le menu utilise et retourne un entier.
*/
Menu::Menu(vector<string> choix) {
	this->titre = "Menu : ";
	this->choix = choix;
}

Menu::Menu(string titre, vector<string> choix) {
	this->titre = titre;
	this->choix = choix;
}

void Menu::Afficher() {
	locale::global(locale{ "" });
	cout << this->titre << endl;
	int num = 1;
	for (string choice : this->choix) {
		cout << num << ". " << choice << endl;
		num++;
	}
}

int Menu::EffectuerChoix() {
	int choice;
	SaisirEntier(1, this->choix.size(), "Votre choix : ", choice);
	return choice;
}
