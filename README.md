# QuentinsLib

> Les instructions d'appel de la bibliothèque dans un programme sont à venir prochainement.

> Cette librairie contient des fonctions et procédures nécessaires à la réalisation de tâches simples mais souvent répétitives

# Table des matières
1. [Liste des fonctions](#Liste-des-fonctions)
    1. [Fonction PGCD](#PGCD)
2. [Liste des procédures](#Liste-des-procédures)
    1. [Procédure SaisirEntier](#SaisirEntier)
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

## Liste des procédures : <a name="Liste-des-procédures"></a>

### SaisirEntier(bool signe, bool nul, string message, int& nbr) <a name="SaisirEntier"></a>

> Cette procédure simplifie le code pour la saisie d'entiers avec des conditions particulières pour vos programmes

```text
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

## Utiliser la librairie QuentinsLib.lib <a name="use_library"></a>

> Cette section décrit les étapes à suivre pour utiliser la librairie sans problème de compilation.

> 1 : `Clic droit` sur le projet dans `l'explorateur de solution`

> 2 : Sélectionner `Propritétés` dans le menu déroulant

> 3 : Dans l'onglet `Propriétés de configuration -> C/C++ -> Général` allez chercher la ligne `Autres répertoires include`, cliquez sur la flèche, `modifier`

> 4 : Ici, remplacer `C:\Users\....\QuentinsLib\QuentinsLib` par `Chemin_Vers_Le_Téléchargement\QuentinsLib\QuentinsLib`

> 5 : Dans l'onglet `Propriétés de configuration -> Éditeur de liens -> Général` allez chercher le ligne `Répertoires de bibliothèques supplémentaires`, cliquez sur la flèche, `modifier`

> 6 : Ici, remplacer `C:\Users\....\QuentinsLib\x64\Debug\` par `Chemin_Vers_Le_Téléchargement\QuentinsLib\x64\Debug`

> 7 : Dans l'onglet `Propriétés de configuration -> Éditeur de liens -> entrée` allez chercher le ligne `Dépendances supplémentaires`, cliquez sur la flèche puis tapez `QuentinsLib.lib`

![Recoredit GIF](http://recordit.co/LPyHRNEN8G.gif)