/*
* Librairie personnelle alimentée au fur et à mesure des tp nécessitant des procédures et fonctions pour le module
* d'introduction à l'algorithmique.
* 
* Auteur : Quentin Marcuzzi
* Version : 1.0.1
* Date de création : 01/10/2020
* 
*/

// Le bloc ifdef suivant est la façon standard de créer des macros qui facilitent l'exportation
// à partir d'une DLL plus simple. Tous les fichiers contenus dans cette DLL sont compilés avec le symbole QUENTINSLIB_EXPORTS
// défini sur la ligne de commande. Ce symbole ne doit pas être défini pour un projet
// qui utilise cette DLL. Ainsi, les autres projets dont les fichiers sources comprennent ce fichier considèrent les fonctions
// QUENTINSLIB_API comme étant importées à partir d'une DLL, tandis que cette DLL considère les symboles
// définis avec cette macro comme étant exportés.
#ifdef QUENTINSLIB_EXPORTS
#define QUENTINSLIB_API __declspec(dllexport)
#else
#define QUENTINSLIB_API __declspec(dllimport)
#endif

#include<iostream>
using namespace std;
#include<limits>

// Définition d'une structure Date :
typedef struct Date {
	int day; // Jour compris entre 1 et 31 maximum
	int month; // Mois compris entre 1 et 12
	int year; // Année supérieure à 0
};

extern "C++" unsigned int PGCD(unsigned int a, unsigned int b);

extern "C++" bool ValidDate(Date date);

extern "C++" bool EstBissextile(int aaaa);

extern "C++" Date DateSuivante(Date date);

extern "C++" void SaisirEntier(int borne_inf, int borne_sup, string message, int& nbr);

extern "C++" void SaisirReel(bool signe, bool nul, string message, float& nbr);

extern "C++" void CalculatriceV1(char operande, float nb1, float nb2);

extern "C++" void CalculatriceV2(char operande, float nb1, float nb2);

extern "C++" typedef struct Date;