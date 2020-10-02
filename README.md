# QuentinsLib

Les instructions d'appel de la bibliothèque dans un programme sont à venir prochainement.

Cette librairie contient des fonctions et procédures nécessaires à la réalisation de tâches simples mais souvent répétitives

# Table des matières
1. [Liste des fonctions](#Liste-des-fonctions)
2. [Liste des procédures](#Liste-des-procédures)

## Liste des fonctions : <a name="Liste-des-fonctions"></a>

### PGCD(unsigned int nb1, unsigned int nb2)
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

## Liste des procédures : <a name="Liste-des-procédures"></a>