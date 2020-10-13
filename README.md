# QuentinsLib

> Cette librairie contient des fonctions et procédures nécessaires à la réalisation de tâches simples mais souvent répétitives

# Table des matières

1. [Importer et utiliser la librairie](#use_library)
2. [Fonctions mathématiques](#maths)
	1. [unsigned int PGCD(unsigned int a, unsigned int b)](#pgcd)

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

> Exemple de résultat lors de l'appel de la fonction : 

![Recordit GIF](http://recordit.co/6WOSjMCtPr.gif)