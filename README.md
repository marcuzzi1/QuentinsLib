# QuentinsLib

> Cette librairie contient des fonctions et procédures nécessaires à la réalisation de tâches simples mais souvent répétitives

# Table des matières

1. [Importer et utiliser la librairie](#use_library)
2. [Fonctions mathématiques](#maths)
	1. [unsigned int PGCD(unsigned int a, unsigned int b)](#pgcd)
3. [Manipulation de dates](#dates)
	1. [Structure Date](#date_struct)
	2. [ValidDate](#valid_date)

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

> Retourne le PGCD de deux nombres *entiers ~non signés~*

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

## Manipulations de dates : <a name="dates"></a>

### Structure Date : <a name="date_struct"</a>

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

> Elle est *dépendante* de la fonction `<a href="bissext">EstBissextile(int annee)</a>`

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

```