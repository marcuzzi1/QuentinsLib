# QuentinsLib

Les instructions d'appel de la bibliothèque dans un programme sont à venir prochainement.

Cette librairie contient des fonctions et procédures nécessaires à la réalisation de tâches simples mais souvent répétitives

# Table des matières
1. [Liste des fonctions](#Liste-des-fonctions)
2. [Liste des procédures](#Liste-des-procédures)

## Liste des fonctions : <a name="Liste-des-fonctions"></a>

### PGCD(unsigned int nb1, unsigned int nb2)

///////////////////////////////////////////////////////  
//                                                   //  
// Fonction retournant le PGCD de 2 entiers positifs //  
// Entrée : 2 entiers non signés                     //  
// Sortie : Le PGCD des 2 entiers                    //  
//                                                   //  
///////////////////////////////////////////////////////  

Procédure PGCD (nb1 : entier, nb2 : entier) retourne entier  
Début  
  Tant que a != b faire :  
    Si a > b alors :  
      a <- a - b  
    Sinon :  
      b <- b - a  
    Fin Si  
  Fin Faire  
  Retourne a  
Fin PGCD  

## Liste des procédures : <a name="Liste-des-procédures"></a>