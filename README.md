# QuentinsLib

Les instructions d'appel de la bibliothèque dans un programme sont à venir prochainement.

Cette librairie contient des fonctions et procédures nécessaires à la réalisation de tâches simples mais souvent répétitives

# Table des matières
1. [Liste des fonctions](#Liste-des-fonctions)
2. [Liste des procédures](#Liste-des-procédures)

## Liste des fonctions : <a name="Liste-des-fonctions"></a>

### PGCD(unsigned int nb1, unsigned int nb2)

///////////////////////////////////////////////////////\n
//                                                   //\n
// Fonction retournant le PGCD de 2 entiers positifs //\n
// Entrée : 2 entiers non signés                     //\n
// Sortie : Le PGCD des 2 entiers                    //\n
//                                                   //\n
///////////////////////////////////////////////////////\n

Procédure PGCD (nb1 : entier, nb2 : entier) retourne entier\n
Début\n
  Tant que a != b faire :\n
    Si a > b alors :\n
      a <- a - b\n
    Sinon :\n
      b <- b - a\n
    Fin Si\n
  Fin Faire\n
  Retourne a\n
Fin PGCD\n

## Liste des procédures : <a name="Liste-des-procédures"></a>