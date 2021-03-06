/*
* Librairie personnelle alimentée au fur et à mesure des tp nécessitant des procédures et fonctions pour le module
* d'introduction à l'algorithmique.
*
* Auteur : Quentin Marcuzzi
* Version : 2.3.0
* Date de création : 01/10/2020
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
#include<vector>



// Attention, ce qui concerne la structure Date et les fonctions/procédures qui y sont associées sont peu recommandées à l'utilisation, préférez utiliser la classe d'objet DateTime quand elle sera opérationnelle
// Définition d'une structure Date :
struct Date {
	int day; // Jour compris entre 1 et 31 maximum
	int month; // Mois compris entre 1 et 12
	int year; // Année supérieure à 0
};

extern "C++" unsigned int PGCD(unsigned int a, unsigned int b);

extern "C++" bool ValidDate(Date date);

extern "C++" bool EstBissextile(int aaaa);

extern "C++" Date DateSuivante(Date date);

extern "C++" void SaisirDate(Date & date);

extern "C++" void SaisirEntier(int borne_inf, int borne_sup, string message, int& nbr);

extern "C++" void SaisirEntier(string message, int& nbr);

extern "C++" void SaisirReel(float borne_inf, float borne_sup, string message, float& nbr);

extern "C++" void SaisirChaine(string message, string & chaine);

extern "C++" int nombreVoyelles(string mot);

extern "C++" void CalculatriceV1(char operande, float nb1, float nb2);

extern "C++" void CalculatriceV2(char operande, float nb1, float nb2);

extern "C++" void AfficherPyramide(int hauteur);

extern "C++" unsigned int Factoriel(unsigned int nbr);

extern "C++" bool EstParfait(int nombre);

extern "C++" int SommeDiviseurs(int nombre);

extern "C++" bool estUnPalindrome(string nom);

extern "C++" void AfficherTableauEntiers(vector<int> tab);

extern "C++" void TriABulleTableauEntiers(vector<int>&tab);

// Classe d'objets

// Menu :
class Menu {
	// Attributs :
private:
	vector<string> choix;
	string titre;
	// Méthodes :
public:
	// Constructeurs
	Menu(vector<string> choix);
	Menu(string titre, vector<string> choix);
	// Autre
	void Afficher();
	int EffectuerChoix();
};

// Date :
class DateTime {
	// Attributs :
private:
	int day, month, year, hour, minutes, seconds;
	// Méthodes :
public:
	//Constructeur sans l'heure
	DateTime(int day, int month, int year);
	//Constructeur avec l'heure
	DateTime(int day, int month, int year, int hour, int minutes, int seconds);
	//Autre 
	bool ValidDate(int day, int month, int year);
};