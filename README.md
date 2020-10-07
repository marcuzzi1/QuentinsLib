# QuentinsLib

> Cette librairie contient des fonctions et procédures nécessaires à la réalisation de tâches simples mais souvent répétitives

# Table des matières
1. [Liste des fonctions](#Liste-des-fonctions)
    1. [Fonction PGCD](#PGCD)
    2. [Fonction ValidDate](#ValidDate)
    3. [Fonction EstBissextile](#EstBissextile)
2. [Liste des procédures](#Liste-des-procédures)
    1. [Procédure SaisirEntier](#SaisirEntier)
    2. [Procédure SaisirReel](#SaisirReel)
    3. [Procédure CalculatriceV1](#calcV1)
    4. [Procédure CalculatriceV2](#calcV2)
3. [Utiliser la librairie](#use_library)

## Liste des fonctions : <a name="Liste-des-fonctions"></a>

### PGCD(unsigned int nb1, unsigned int nb2) <a name="PGCD"></a>

> Cette fonction retourne le PGCD de 2 entiers naturels.

```text
####################################################
# Fonction retournant le pgcd de 2 entier positifs #
# Entrée : 2 entiers positifs                      #
# Sortie : Leur PGCD                               #
####################################################

Fonction PGCD (a : entier, b : entier) retourne entier
Début
    Tant que a != b faire :
        Si a > b alors :
            a <- a - b
        Sinon :
            b <- b - a
        Fin Si
    Fin Faire
    Retourner a
Fin PGCD
```

> Exemple de code appelant :

```c++
#include<iostream>
using namespace std;
#include<QuentinsLib.h>

int main(){
    int nb1, nb2;
    cout << "Saisir les valeurs : " << endl;
    cin >> nb1;
    cin >> nb2;
    // Ici on vérifie que les entiers sont positifs avant de faire le calcul
    cout << "Leur PGCD est : " << PGCD(nb1, nb2) << endl;
    return 0;
}
```

> Ce qui donne :

![Recordit GIF](http://recordit.co/uWcXfK36cf.gif)

### bool ValidDate(int jj, int mm, int aaaa) <a name="ValidDate"></a>

> Cete fonction **dépendante de<a href="#EstBissextile"> la fonction ci-dessous**</a> permet de valider la saisie d'une date saisie sous la forme jj/mm/aaaa

```text
#########################################################################
#                                                                       #
# Fonction retournant un booléen pour la vérification d'une date saisie #
# Entrée : 3 entiers (jj, mm, aaaa)                                     #
# Sortie : 1 booléen                                                    #
#                                                                       #
#########################################################################

Fonction ValidDate(jj : entier, mm : entier, aaaa : entier;) retourne booléen
Début
    Si (mm = 1) ou (mm = 3) ou (mm = 5) ou (mm = 7) ou (mm = 8) ou (mm = 10) ou (mm = 12) alors :
        Si (jj > 31) alors :
            Retourner faux
        Fin Si
    Sinon :
        Si (mm != 2) et (mm < 12) alors :
            Si (jj > 30) alors :
                Retourner faux
            Fin Si
        Sinon :
            Si (mm = 2) alors :
                Si (EstBissextile(aaaa)) alors :
                    Si (jj > 29) alors :
                        Retourner faux
                    Fin Si
                Sinon :
                    Si (jj > 28) alors :
                        Retourner faux
                    Fin Si
                Fin Si
            Sinon :
                Retourner faux
            Fin Si
        Fin Si
    Fin Si
    Retourner vrai
Fin ValidDate
```

> Exemple de programme appelant :

```c++
#include<iostream>
using namespace std;
#include<Windows.h>
#include<QuentinsLib.h>

int main() {
	// Ajout d'une ligne permettant d'afficher les accents en console :
	locale::global(locale{ "" });
	// Les 2 lignes suivantes permettent de maximiser la taille de la console sur l'écran
	HWND hwnd = GetForegroundWindow();
	ShowWindow(hwnd, SW_MAXIMIZE);

	int jour, mois, annee;

	do {
		cout << "Saisir le jour : ";
		cin >> jour;
		cout << "Saisir le mois : ";
		cin >> mois;
		cout << "Saisir l'année : ";
		cin >> annee;
	} while (jour < 1 || mois < 1 || annee < 0);

	if (ValidDate(jour, mois, annee)) {
		cout << "La date saisie est valide." << endl;
	}
	else {
		cout << "La date saisie est invalide." << endl;
	}

	system("pause");
	return 0;
}
```

> Ce qui donne :

![Recordit GIF](http://recordit.co/LVaCxX3siC.gif)

### bool EstBissextile(int aaaa) <a name="EstBissextile"></a>

> Cette fonction permet de vérifier si une année saisie est bissextile ou non

```text
###################################################################
#                                                                 #
# Fonction retournant un booléen à vrai si l'année est bissextile #
# et faux si l'année ne l'est pas                                 #
# Entrée : Un entier contenant l'année                            #
# Sortie : Un booléen                                             #
#                                                                 #
###################################################################

Fonction EstBissextile(aaaa : entier;) retourne booléen
Début
    Si ((aaaa mod 4 = 0) et (aaaa mod 100 != 0)) ou (aaaa mod 400 = 0) alors :
        Retourner Vrai
    Fin Si
    Retourner faux
Fin EstBissextile
```

## Liste des procédures : <a name="Liste-des-procédures"></a>

### SaisirEntier(bool signe, bool nul, string message, int& nbr) <a name="SaisirEntier"></a>

> Cette procédure simplifie le code pour la saisie d'entiers avec des conditions particulières pour vos programmes

```text
##############################################################################
#                                                                            #
# Procédure de saisie et de vérification d'un entier                         #
# Entrée : Un booléen déterminant le signe                                   #
#          Un booléen déterminant si les valeurs nulles sont acceptée ou non #
#          Une chaîne de caractères contenant le message à afficher          #
# Sortie : rien                                                              #
# Entrée/Sortie : le nombre réel à saisir                                    #
#                                                                            #
##############################################################################

Procédure SaisirEntier(signe : booléen, nul : booléen, message : chaîne de caractères; nbr : entier)
Début
    Si (signe) alors :
        Si (nul) alors :
            Afficher message
            Saisir nbr
        Sinon :
            Répéter :
                Afficher message
                Saisir nbr
                Si nbr = 0 alors :
                    Afficher "Les valeurs nulles ne sont pas acceptees"
                Fin Si
            Tant que nbr = 0
        Fin Si
    Sinon :
        Si (nul) alors :
            Répéter :
                Afficher message
                Saisir nbr
                Si nbr < 0 alors :
                    Afficher "Les valeurs negatives ne sont pas acceptees"
                Fin Si
            Tant que nbr < 0
        Sinon :
            Répéter :
                Afficher message
                Saisir nbr
                Si nbr <= 0 alors :
                    Afficher "Les valeurs negatives ou nulles ne sont pas acceptees"
                Fin Si
            Tant que nbr <= 0
        Fin Si
    Fin Si
Fin SaisirEntier
```

> Exemple de code appelant :

```c++
#include<iostream>
using namespace std;
#include<Windows.h>
#include"QuentinsLib.h"

int main() {
	int entier;
	SaisirEntier(true, true, "Saisir un entier : ", entier);

	int entierNonNul;
	SaisirEntier(true, false, "Saisir un entier non nul : ", entierNonNul);

	int entierPositif;
	SaisirEntier(false, true, "Saisir un entier positif : ", entierPositif);

	int entierPositifNonNul;
	SaisirEntier(false, false, "Saisir un entier positif non nul : ", entierPositifNonNul);

	cout << "Valeurs saisies : " << entier << "; " << entierNonNul << "; " << entierPositif << "; " << entierPositifNonNul << endl;

	system("pause");
	return 0;
}
```

> Ce qui donne :

![Recordit GIF](http://recordit.co/5NxA8jtdi5.gif)

### SaisirReel(bool signe, bool nul, string message, float& nbr) <a name="SaisirReel"></a>

> Cette procédure simplifie le code pour la saisie d'entiers avec des conditions particulières pour vos programmes

```text
##############################################################################
#                                                                            #
# Procédure de saisie et de vérification d'un réel                           #
# Entrée : un booléen déterminant le signe                                   #
#          un boléen déterminant si les valeurs nulles sont acceptées ou non #
#          une chaîne de caractères contenant le message à afficher          #
# Sortie : Rien                                                              #
# Entrée/Sortie : le nombre réel à saisir                                    #
#                                                                            #
##############################################################################

Procédure SaisirReel(signe : booléen, nul : booléen, message : chaîne de caractères; nbr : réel)
Début
    Si (signe) alors :
        Si (nul) alors :
            Afficher message
            Saisir nbr
        Sinon :
            Répéter :
                Afficher message
                Saisir nbr
                Si nbr = 0 alors :
                    Afficher "Les valeurs nulles ne sont pas acceptees"
                Fin Si
            Tant que nbr = 0
        Fin Si
    Sinon :
        Si (nul) alors :
            Répéter :
                Afficher message
                Saisir nbr
                Si nbr < 0 alors :
                    Afficher "Les valeurs negatives ne sont pas acceptees"
                Fin Si
            Tant que nbr < 0
        Sinon :
            Répéter :
                Afficher message
                Saisir nbr
                Si nbr <= 0 alors :
                    Afficher "Les valeurs negatives ou nulles ne sont pas acceptees"
                Fin Si
            Tant que nbr <= 0
        Fin Si
    Fin Si
Fin SaisirReel
```

> Exemple de code appelant : 

```c++
#include<iostream>
using namespace std;
#include<Windows.h>
#include<QuentinsLib.h>

int main() {
	// Ajout d'une ligne permettant d'afficher les accents en console :
	locale::global(locale{ "" });
	// Les 2 lignes suivantes permettent de maximiser la taille de la console sur l'écran
	HWND hwnd = GetForegroundWindow();
	ShowWindow(hwnd, SW_MAXIMIZE);

	float nombre;

	SaisirReel(false, true, "Saisir un nombre réel : ", nombre);

    cout << "Vous avez saisi : " << nombre << endl;
	return 0;
}
```

> Ce qui donne : 

![Recordit GIF](http://recordit.co/NJiozKTsmN.gif)

### void CalculatriceV1(char operande, float nb1, float nb2) <a name="calcV1"></a>

> Cette procédure gère la fonctionnalité de calculatrice demandée avec un `si alors sinon` imbriqué

```text
#######################################################################################
#                                                                                     #
# Procédure contenant les instruction de la calculatrice (version si sinon imbriqués) #
# Entrée : opérande sour la forme d'un caractère                                      #
#			 2 nombres réels                                                          #
# Sortie : Rien                                                                       #
#                                                                                     #
#######################################################################################

Procédure CalculatriceV1(operande : caractère, nb1 : réel, nb2 : réel;)
Début
    Si operande = '+' alors :
        Afficher nb1, " + ", nb2, " = ", nb1 + nb2
    Sinon
        Si operande = '-' alors :
            Afficher nb1, " - ", nb2, " = ", nb1 - nb2
        Sinon : 
            Si operande = '*' alors :
                Afficher nb1, " * ", nb2, " = ", nb1 * nb2
            Sinon :
                Si operande = '/' alors : 
                    Si nb2 != 0 alors :
                        Afficher nb1, " / ", nb2, " = ", nb1 / nb2
                    Sinon : 
                        Afficher "Pas de division par 0 !"
                    Fin Si
                Sinon :
                    Afficher "Operande inconnue ! "
                Fin Si
            Fin Si
        Fin Si
    Fin Si
Fin CalculatriceV1
```

> Exemple de programme appelant : 

```c++
#include<iostream>
using namespace std;
#include<Windows.h>
#include<QuentinsLib.h>

int main() {
	// Ajout d'une ligne permettant d'afficher les accents en console :
	locale::global(locale{ "" });
	// Les 2 lignes suivantes permettent de maximiser la taille de la console sur l'écran
	HWND hwnd = GetForegroundWindow();
	ShowWindow(hwnd, SW_MAXIMIZE);

	float nb1;
	float nb2;
	char operande;

	SaisirReel(true, true, "Saisir un premier nombre : ", nb1);
	SaisirReel(true, true, "Saisir un deuxième nombre : ", nb2);

	cout << "Saisir l'opération à effectuer (+, -, /, *) : ";
	cin >> operande;

	CalculatriceV1(operande, nb1, nb2);

	return 0;
}
```

> Ce qui donne :

![Recordit GIF](http://recordit.co/mwAAWW9NdE.gif)

### void CalculatriceV2(char operande, float nb1, float nb2) <a name="calcV2"></a>

> Cette procédure gère la fonctionnalité de calculatrice demandée avec un `si alors sinon` imbriqué

```text
##########################################################################
#                                                                        #
# Procédure contenant les instruction de la calculatrice (version selon) #
# Entrée : opérande sour la forme d'un caractère                         #
#			 2 nombres réels                                             #
# Sortie : Rien                                                          #
#                                                                        #
##########################################################################

Procédure CalculatriceV2(operande : caractère, nb1 : réel, nb2 : réel;)
Début
    Selon (operande) faire :
    cas '+' :
        Afficher nb1, " + ", nb2, " = ", nb1 + nb2
    cas '-' :
        Afficher nb1, " - ", nb2, " = ", nb1 - nb2
    cas '*' :
        Afficher nb1, " * ", nb2, " = ", nb1 * nb2
    cas '/' :
        Si nb2 != 0 alors :
            Afficher nb1, " / ", nb2, " = ", nb1 / nb2
        Sinon :
            Afficher "Pas de division par 0 !"
        Fin Si
    Fin Faire
Fin CalculatriceV2
```

> Exemple de programme appelant : 

```c++
#include<iostream>
using namespace std;
#include<Windows.h>
#include<QuentinsLib.h>

int main() {
	// Ajout d'une ligne permettant d'afficher les accents en console :
	locale::global(locale{ "" });
	// Les 2 lignes suivantes permettent de maximiser la taille de la console sur l'écran
	HWND hwnd = GetForegroundWindow();
	ShowWindow(hwnd, SW_MAXIMIZE);

	float nb1;
	float nb2;
	char operande;

	SaisirReel(true, true, "Saisir un premier nombre : ", nb1);
	SaisirReel(true, true, "Saisir un deuxième nombre : ", nb2);

	cout << "Saisir l'opération à effectuer (+, -, /, *) : ";
	cin >> operande;

	CalculatriceV2(operande, nb1, nb2);

	return 0;
}
```

> Ce qui donne :

![Recordit GIF](http://recordit.co/BkuIynjXjo.gif)

## Utiliser la librairie QuentinsLib.lib <a name="use_library"></a>

> Cette section décrit les étapes à suivre pour utiliser la librairie sans problème de compilation.

> 1 : `Clic droit` sur le projet dans `l'explorateur de solution`

> 2 : Sélectionner `Propritétés` dans le menu déroulant

> 3 : Dans l'onglet `Propriétés de configuration -> C/C++ -> Général` allez chercher la ligne `Autres répertoires include`, cliquez sur la flèche, `modifier`

> 4 : Ici, remplacer `C:\Users\....\QuentinsLib\QuentinsLib` par `Chemin_Vers_Le_Téléchargement\QuentinsLib\QuentinsLib`

![Recordit GIF](http://recordit.co/f4vnlUbbMp.gif)

> 5 : Dans l'onglet `Propriétés de configuration -> Éditeur de liens -> Général` allez chercher le ligne `Répertoires de bibliothèques supplémentaires`, cliquez sur la flèche, `modifier`

> 6 : Ici, remplacer `C:\Users\....\QuentinsLib\x64\Debug\` par `Chemin_Vers_Le_Téléchargement\QuentinsLib\x64\Debug`

![Recordit GIF](http://recordit.co/suPAP77Xce.gif)

> 7 : Dans l'onglet `Propriétés de configuration -> Éditeur de liens -> entrée` allez chercher le ligne `Dépendances supplémentaires`, cliquez sur la flèche puis tapez `QuentinsLib.lib`

![Recordit GIF](http://recordit.co/6cznfMh6mx.gif)