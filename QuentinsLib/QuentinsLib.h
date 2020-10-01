/*
* Librairie personnelle alimentée au fur et à mesure des tp nécessitant des procédures et fonctions pour le module
* d'introduction à l'algorithmique.
* 
* Auteur : Quentin Marcuzzi
* Version : 1.0.0
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

extern "C++" unsigned int PGCD(unsigned int a, unsigned int b);

extern "C++" bool ValidDate(int jj, int mm, int aaaa);