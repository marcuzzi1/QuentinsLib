# QuentinsLib

> Cette librairie contient des fonctions et procédures demandées pour les tp de DUT informatique de première année

> Pour mettre à jour la bibliothèque : 
> 	1. Vous possédez git sur votre machine Windows --> Exécutez `pull.bat`
>	2. Vous êtes sous Linux --> Exécutez `git pull` dans un terminal en se plaçant dans le répertoire où cous avez téléchargé la librairie
>	3. Vous n'avez pas git --> Retéléchargez la librairie depuis cette page et pensez à vos éditions de liens si vous le téléchargez ailleurs

# Table des matières

1. [Importer et utiliser la librairie](#use_library)
2. [Fonctions mathématiques](#maths)
	1. [PGCD](#pgcd)
	2. [Factoriel](#fact)
3. [Manipulation de dates](#dates)
	1. [Structure Date](#date_struct)
	2. [ValidDate](#valid_date)
	3. [EstBissextile](#bissext)
	4. [DateSuivante](#date_suiv)
	5. [SaisirDate](#saisir_date)
4. [Fonctions et procédures spécifiques aux tp](#specific)
	1. [CalculatriceV1](#calcv1)
	2. [CalculatriceV2](#calcv2)

## Utiliser la librairie QuentinsLib.lib <a name="use_library"></a>

> Cette section décrit les étapes à suivre pour utiliser la librairie sans problème de compilation.

> Actuellement je ne sais pas encore comment inclure la destination des fichiers nécessaires dans un projet fait sur Visual Studio Code

> Des mises à jour étant régulièrement faites il est recommandé d'installer Git afin d'effectuer un `git pull`

> Pour d'éventuels problèmes ou questions n'hésitez pas à la reporter dans l'onglet `Issues`

> Maintenant à vous de jouer !

> 1 : `Clic droit` sur le projet dans `l'explorateur de solution`

> 2 : Sélectionner `Propritétés` dans le menu déroulant

> 3 : Dans l'onglet `Propriétés de configuration -> C/C++ -> Général` allez chercher la ligne `Autres répertoires include`, cliquez sur la flèche, `modifier`

> 4 : Ici, remplacer `C:\Users\....\QuentinsLib\QuentinsLib` par `Chemin_Vers_Le_Téléchargement\QuentinsLib\QuentinsLib`

> Pensez également à sélectionner une compilation en x64 de votre programme (les processeurs 32 bits se faisant oublier...)

![Recordit GIF](http://recordit.co/a5oktr0R2T.gif)

![Recordit GIF](http://recordit.co/f4vnlUbbMp.gif)

> 5 : Dans l'onglet `Propriétés de configuration -> Éditeur de liens -> Général` allez chercher le ligne `Répertoires de bibliothèques supplémentaires`, cliquez sur la flèche, `modifier`

> 6 : Ici, remplacer `C:\Users\....\QuentinsLib\x64\Debug\` par `Chemin_Vers_Le_Téléchargement\QuentinsLib\x64\Debug`

![Recordit GIF](http://recordit.co/suPAP77Xce.gif)

> 7 : Dans l'onglet `Propriétés de configuration -> Éditeur de liens -> entrée` allez chercher le ligne `Dépendances supplémentaires`, cliquez sur la flèche puis tapez `QuentinsLib.lib`

![Recordit GIF](http://recordit.co/6cznfMh6mx.gif)

## Fonctions mathématiques : <a name="maths"></a>

> Ici vous trouverez les fonctions mathématiques non trouvables de base pour certains besoins : 

### unsigned int PGCD(unsigned int a, unsigned int b) <a name="pgcd"></a>

> Retourne le PGCD de deux nombres *entiers _non signés_*

```text
#######################################################
#                                                     #
# Fonction retournant le PGCD de 2 entiers non signés #
# Entrée : 2 nombres entiers non signés               #
# Sortie : Un entier non signé                        #
#                                                     #
#######################################################

Fonction PGCD(a, b : entiers non signés;) retourne entier non signé
Début
	Tant que (a != b) faire :
		Si (a > b) alors :
			a <- a - b
		Sinon :
			b <- b- a
		Fin Si
	Fin faire
	Retourne a
Fin PGCD
```

```c++
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
```

> Exemple de résultat : 

![Recordit GIF](http://recordit.co/6WOSjMCtPr.gif)

### unsigned int Factoriel(unsigned int nbr) <a name="fact"></a>

> Cette fonction retourne le factoriel d'un entier non signé passé en paramètre

> Attention ! Par soucis de précision vous ne pourrez afficher qu'au maximum fatoriel 33

```text
#################################################################
#                                                               #
# Fonction retournant le factoriel d'un nombre entier non signé #
# Entrée : 1 entier non signé                                   #
# Sortie : Le résultat du factoriel                             #
#                                                               #
#################################################################

Fonction Factoriel (nbr : entier non signé ;) retoune entier non signé
Début
	Avec fact : entier non signé
	fact <- 1
	Pour (i : entier de 1 à nbr pas de 1) faire :
		fact <- fact * i
	Fin Faire
Fin Factoriel
```

```c++
unsigned int Factoriel(unsigned int nbr) {
	unsigned int fact = 1;
	for (int i = 1; i <= nbr; i++) {
		fact *= i;
	}
	return fact;
}
```

## Manipulations de dates : <a name="dates"></a>

> Une procédure de saisie et de contrôle d'une date est à venir

### Structure Date : <a name="date_struct"></a>

> Cette structure est utilisée dans toutes les fonctions et procédures se rapportant à une date.

```c++
typedef struct Date {
	int day; // Jour compris entre 1 et 31 maximum
	int month; // Mois compris entre 1 et 12
	int year; // Année supérieure à 0
};
```

> Le choix des valeurs négatives pour l'année peut très bien être pris par l'utilisateur.

### bool ValidDate(Date date) <a name="valid_date"></a>

> Cette fonction retourne un booléen et permet donc d'en déterminer si une date saisir par l'utilisateur est valide ou non

> Elle est *dépendante* de la fonction <a href="#bissext">`EstBissextile(int annee)`</a>

```text
#########################################################################
#                                                                       #
# Fonction retournant un booléen pour la vérification d'une date saisie #
# Entrée : une date sous le format de la structure de données Date      #
# Sortie : 1 booléen                                                    #
#                                                                       #
#########################################################################

Fonction ValidDate (Date date;) retourne booléen
Début
	Si (date.month = 1 ou date.month = 3 ou date.month = 5 ou date.month = 7 ou date.month = 8 ou date.month = 10 ou date.month = 12) alors :
		Si (date.day > 31) alors :
			Retourne faux
		Fin Si
	Sinon :
		Si (date.month != 2 et date.month < 12) alors :
			Si (date.day > 30) alors :
				Retourne faux
			Fin Si
		Sinon :
			Si (date.month = 2) alors :
				Si (EstBissextile(date.year)) alors :
					Si (date.day > 29) alors :
						Retourne faux
					Fin Si
				Sinon :
					Si (date.day > 28) alors :
						Retourne faux
					Fin Si
				Fin Si
			Sinon :
				Retourne faux
			Fin Si
		Fin Si
	Fin Si
	Retourne vrai
Fin ValidDate
```

```c++
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
```

> Exemple de résultat : 

![Recordit GIF](http://recordit.co/9kNhJrbO1L.gif)

### bool EstBissextile(int annee) <a name="bissext"></a>

> Cette fonction permet de savoir si une année est bissextile ou non, ce qui est utile lors de la vérification ou modification d'une date

```text
###################################################################
#                                                                 #
# Fonction retournant un booléen à vrai si l'année est bissextile #
# et faux si l'année ne l'est pas                                 #
# Entrée : Un entier contenant l'année                            #
# Sortie : Un booléen                                             #
#                                                                 #
###################################################################

Fonction EstBissextile(annee : entier) retourne booléen
Début
	Si ((annee mod 4 = 0 et annee mod 100 != 0) ou annee mod 400 = 0) alors :
		Retourne vrai
	Sinon :
		Retourne faux
	Fin si
Fin EstBissextile
```

```c++
bool EstBissextile(int annee) {
	if ((annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0) {
		return true;
	}
	return false;
}
```

> Il n'y aura pas d'exemple ici

### Date DateSuivante(Date date) <a name="date_suiv"></a>

> Cette fontion retourne la date suivante de celle passée en paramètre

```text
###############################################################################
#                                                                             #
# Fonction retournant une Date contenant le jour suivant de la Date en entrée #
# Entrée : une Date (auparavant contrôlée !)                                  #
# Sortie : La date suivante                                                   #
#                                                                             #
###############################################################################

Fonction DateSuivante (Date date;) retourne Date
Début
	Avec suivante : Date
	suivante <- date
	Si (date.month = 1 ou date.month = 3 ou date.month = 5 ou date.month = 7 ou date.month = 8 ou date.month = 10 ou date.month = 12) alors :
		Si (date.day < 31) alors :
			suivante.day <- suivante.day + 1
		Sinon :
			date.day <- date.day + 1
			Si (date.month = 12) alors :
				suivante.month <- 1
				suivante.year <- suivante.year + 1
			Sinon :
				suivante.month <- suivante.month + 1
			Fin Si
		Fin Si
	Sinon :
		Si (date.month != 2) alors :
			Si (date.date < 30) alors :
				suivante.day <- suivante.day + 1
			Sinon :
				suivante.day <- 1
				suivante.month <- suivante.month + 1
			Fin Si
		Sinon :
			Si (EstBissextile(date.year)) alors :
				Si (date.day < 29) alors :
					suivante.day <- suivante.day + 1
				Sinon :
					suivante.day <- 1
					suivante.month <- suivante.month + 1
				Fin Si
			Sinon :
				Si (date.day < 28) alors :
					suivante.day <- suivante.day + 1
				Sinon :
					suivante.day <- 1
					suivante.month <- suivante.month + 1
				Fin Si
			Fin Si
		Fin Si
	Fin Si
	Retourne suivante
Fin DateSuivante
```

```c++
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
```

> Exemple de résultat :

![Recordit GIF](http://recordit.co/S4La67D2aX.gif)

### void SaisirDate(Date& date) <a name="saisir_date"></a>

> Cette procédure permet de saisir et de contrôler une date (attention à utiliser la structure Date)

```text
##########################################################
#                                                        #
# Procédure de saisie de date (véfification automatique) #
# Entrée : Rien                                          #
# Sortie : Rien                                          #
# Entrée/Sortie : La Date à saisir                       #
#                                                        #
##########################################################

Procédure SaisirDate(; date : Date)
Début
	Avec valid : booléen
	valid <- faux
	Répéter :
		SaisirEntier(0, 31, "Saisir le jour : ", date.day);
		SaisirEntier(0, 12, "Saisir le mois : ", date.month);
		SaisirEntier(0, 65535, "Saisir l'annee : ", date.year);
		Si (!ValidDate(date)) alors :
			Afficher "La date saisie est invalide, reessayez svp !"
			À la ligne
		Sinon :
			valid <- vrai
		Fin Si
	Tant que (!valid)
Fin SaisirDate
```

```c++
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
```

## Fonctions et procédures spécifiques aux tp <a name="specific"></a>

### void CalculatriceV1(char operande, float nb1, float nb2) <a name="calcv1"></a>

> Cette procédure simule une calculatrice simple avec des `Si Sinon` imbriqués

```text
#######################################################################################
#                                                                                     #
# Procédure contenant les instruction de la calculatrice (version si sinon imbriqués) #
# Entrée : opérande sour la forme d'un caractère                                      #
#          2 nombres réels                                                            #
# Sortie : Rien                                                                       #
#                                                                                     #
#######################################################################################

Procédure CalculatriceV1(operande : caractère, nb1 : réel, nb2 : réel ;)
Début
	Si (operande = '+') alors :
		Afficher nb1, operande, nb2, " = ", nb1 + nb2
	Sinon :
		Si (operande = '-') alors :
			Afficher nb1, operande, nb2, " = ", nb1 - nb2
		Sinon :
			Si (operande = '*') alors :
				Afficher nb1, operande, nb2, " = ", nb1 * nb2
			Sinon :
				Si (operande = '/') alors :
					Si (nb2 != 0) alors :
						Afficher nb1, operande, nb2, " = ", nb1 / nb2
					Sinon :
						Afficher "Pas de division par 0 !"
					Fin Si
				Sinon :
					Afficher "Operande inconnue !"
				Fin Si
			Fin Si
		Fin Si
	Fin Si
Fin CalculatriceV1
```

```c++
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
```

### void CalculatriceV2(char operande, float nb1, float nb2) <a name="calcv2"></a>

> Cette procédure simule une calculatrice avec une stucture conditionnelle `sinon`

```text
##########################################################################
#                                                                        #
# Procédure contenant les instruction de la calculatrice (version selon) #
# Entrée : opérande sour la forme d'un caractère                         #
#          2 nombres réels                                               #
# Sortie : Rien                                                          #
#                                                                        #
##########################################################################

Procédure CalculatriceV2(operande : caractère, nb1 : réel, nb2 : réel ;)
Début
	Selon (operande) faire :
	cas '+' :
		Afficher nb1, operande, nb2, " = ", nb1 + nb2
	cas '-' :
		Afficher nb1, operande, nb2, " = ", nb1 - nb2
	cas '*' :
		Afficher nb1, operande, nb2, " = ", nb1 * nb2
	cas '/' :
		Si (nb2 != 0) alors :
			Afficher nb1, operande, nb2, " = ", nb1 / nb2
		Sinon :
			Afficher "Pas de division par 0 !"
		Fin Si
	Défaut :
		Afficher "Opérande inconnue !"
	Fin Faire
Fin CalculatriceV2
```

```c++
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
```