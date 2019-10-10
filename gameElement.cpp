#include "pch.h"
#include "gameElement.h"
#include <time.h>
#include <string>
#include <Windows.h>


using namespace std;

string randDirection()
{
	srand(time(NULL));
	string direction;
	int randPos = rand() % 4 + 1;

	if (randPos == 1)	direction = "nord";
	if (randPos == 2)	direction = "est";
	if (randPos == 3)	direction = "sud";
	if (randPos == 4)	direction = "ouest";

	return direction;
}


void Color(int couleurDuTexte, int couleurDeFond) // fonction d'affichage de couleurs
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, couleurDeFond * 16 + couleurDuTexte);
}