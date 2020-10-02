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