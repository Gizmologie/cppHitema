#include "pch.h"
#include <iostream>
#include <string>
#include <time.h>
#include <windows.h>
#include "GameElement.h"
#include "ant.h"
#include "Anthil.h"
#include "Food.h"

using namespace std;

const int x = 24; 
const int y = 18; 

int grid[x][y];

bool antStatus = false;

void createGrid() // remplis le tableau de 0 à tous les emplacements non assigné pour les fourmis, la nourriture ou la fourmiliere 
{
	for (int i = 0; i < x; i++)
	{
	
		for (int j = 0; j < y; j++)
		{
			if (grid[i][j] != 5 && grid[i][j] != 3 && grid[i][j] != 1
)	grid[i][j]=0;
		}
	}
}

void displayGrid()
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			Color(15, 0);
			if (grid[j][i] == 5)
			{
				Color(12, 0);
				cout << grid[j][i] << " ";
				Color(15, 0);
			}
			else if (grid[j][i] == 3)
			{
				Color(6, 0);
				cout << grid[j][i] << " ";
				Color(15, 0);
			}
			else if (grid[j][i] == 1)
			{
				Color(9, 0);
				cout << grid[j][i] << " ";
				Color(15, 0);
			}
			else	cout << grid[j][i] << " ";
		}
		cout << endl;
	}
}

void createAnthil(int anthilX, int anthilY, Anthil* anthil) // création de la fourmiliere
{
	cout << "anthilX = " << anthilX << " et anthilY = " << anthilY << endl;
	grid[anthilX][anthilY] = 5;
}

void createFood(int anthilX, int anthilY, Anthil* anthil,int &FoodX,int &FoodY) {
	bool status = true; // sera utilisé pour s'assurer que la nourriture ne se créer pas à la meme position que la fourmiliere  
	while (status == true)
	{
		int randFoodX = rand() % x;
		int randFoodY = rand() % y;
		if (randFoodX != anthilX || randFoodY != anthilY) {
			FoodX = randFoodX; 
			FoodY = randFoodY;
			grid[randFoodX][randFoodY] = 3;
			status = false;
		}
	}
}

void createAnt(int anthilX, int anthilY, int &antX, int &antY, int foodX, int foodY,Ant* ant) // creation de la fourmi
{
	int randAntX = anthilX;
	int randAntY = anthilY + 1;
	bool status = true; // meme fonctionnement que createFood 

	cout << "randAntX = " << randAntX << " et randAntY = " << randAntY << endl;
	cout << "FoodX = " << foodX << " et FoodY = " << foodY << endl;

	while (status == true)
	{
		if (randAntX != foodX || randAntY != foodY) {
			antX = randAntX;
			antY = randAntY;
			grid[randAntX][randAntY] = 1;
			status = false;
		}
	}
}

void moveAnt(int anthilX, int anthilY, int &antX, int &antY, int foodX, int foodY,Ant* ant)
{
	string direction = randDirection();
	cout << direction << endl;

	if (direction == "nord")
	{
		grid[antX][antY] = 0;
		if (grid[antX][antY - 1] == 3)
		{
			grid[antX][antY] = 1;
			antStatus = true;
		}
		else if (grid[antX][antY - 1] == 5)	antY -= 2; 
		else	antY--;	
		grid[antX][antY] = 1;
	}
	if (direction == "sud")
	{
		grid[antX][antY] = 0;
		if (grid[antX][antY + 1] == 3)
		{
			grid[antX][antY] = 1;
			antStatus = true;
		}
		else if (grid[antX][antY + 1] == 5)	antY += 2;
		else	antY++;
		grid[antX][antY] = 1;
	}
	if (direction == "est")
	{
		grid[antX][antY] = 0;
		if (grid[antX+1][antY] == 3)
		{
			grid[antX][antY] = 1;
			antStatus = true;
		}
		else if (grid[antX+1][antY] == 5)	antX += 2;
		else	antX++;
		grid[antX][antY] = 1;
	}
	if (direction == "ouest")
	{
		grid[antX][antY] = 0;
		if (grid[antX-1][antY] == 3)
		{
			grid[antX][antY] = 1;
			antStatus = true;
		}
		else if (grid[antX - 1][antY] == 5)	antX -= 2;
		else	antX--;
		grid[antX][antY] = 1;
	}
}

void backAnt(int anthilX, int anthilY, int &antX, int &antY, int foodX, int foodY, Ant* ant)
{
	
	if (anthilX < antX)	
	{
		if (grid[antX--][antY] == grid[anthilX][anthilY])	antStatus == false;
		else antX--;
	}
	else if (anthilX > antX)	
	{
		if (grid[antX++][antY] == grid[anthilX][anthilY])	antStatus == false;
		else antX++;
	}
	else if (anthilY < antY)
	{
		if (grid[antX][antY--] == grid[anthilX][anthilY])	antStatus == false;
		else antY--;
	}
	else if (anthilY > antY)
	{
		if (grid[antX][antY++] == grid[anthilX][anthilY])	antStatus == false;
		else antY++;
	};
}

void autoAnt(int anthilX, int anthilY, int &antX, int &antY, int foodX, int foodY, Ant* ant)
{
	if (foodY > antY)
	{
		grid[antX][antY] = 0;
		if (grid[antX][antY - 1] == 3)
		{
			grid[antX][antY] = 1;
			antStatus = true;
		}
		else if (grid[antX][antY - 1] == 5)	antY -= 2;
		else	antY--;
		grid[antX][antY] = 1;
	}
	if (foodY < antY)
	{
		grid[antX][antY] = 0;
		if (grid[antX][antY + 1] == 3)
		{
			grid[antX][antY] = 1;
			antStatus = true;
		}
		else if (grid[antX][antY + 1] == 5)	antY += 2;
		else	antY++;
		grid[antX][antY] = 1;
	}
	if (foodX > antX)
	{
		grid[antX][antY] = 0;
		if (grid[antX + 1][antY] == 3)
		{
			grid[antX][antY] = 1;
			antStatus = true;
		}
		else if (grid[antX + 1][antY] == 5)	antX += 2;
		else	antX++;
		grid[antX][antY] = 1;
	}
	if (foodX < antX)
	{
		grid[antX][antY] = 0;
		if (grid[antX - 1][antY] == 3)
		{
			grid[antX][antY] = 1;
			antStatus = true;
		}
		else if (grid[antX - 1][antY] == 5)	antX -= 2;
		else	antX--;
		grid[antX][antY] = 1;
	}

}

int main()
{
	// commande time.h
	srand(time(NULL));

	// Instanciation de la fourmi
	Ant* ant = new Ant();
	Anthil* anthil = new Anthil();
	Food* food = new Food();

	// creation variable 
	int choice; // Choix de l'execution du programe en auto ou en aléatoire 
	bool game = true; // 
	int randAnthilX;
	int randAnthilY;
	int randAntX=0; 
	int randAntY=0;
	int randFoodX = 0; // la valeur sera modifie par reference dans la fonction createFood()
	int randFoodY=0; // same same 
	//int antStatus = ant->getStatus;

	// Assignation de valeur aléatoire 
	randAnthilX = rand() % x;
	randAnthilY = rand() % y;

	// Methodes et fonctions
	createAnthil(randAnthilX, randAnthilY, anthil);
	createFood(randAnthilX, randAnthilY, anthil, randFoodX, randFoodY);
	createAnt(randAnthilX, randAnthilY, randAntX, randAntY, randFoodX, randFoodY, ant);
	createGrid();
	displayGrid();
	cout << "Choisir : " << endl << "\t(1) La fourmi cherchera son chemin" << endl << "\t(2) La fouri trouvera son chemin" << endl;
	cin >> choice;
	system("PAUSE");
	system("CLS");

	switch (choice)
	{
	case 1:
		while (antStatus == false)
		{

			moveAnt(randAnthilX, randAnthilY, randAntX, randAntY, randFoodX, randFoodY, ant);
			displayGrid();
			Sleep(1000);
			system("CLS");
		}
		break;
	case 2:
		while (antStatus == false)
		{
			autoAnt(randAnthilX, randAnthilY, randAntX, randAntY, randFoodX, randFoodY, ant);
			displayGrid();
			Sleep(1000);
			system("CLS");
		}
		break;
	default: cout << "exception" << endl;
	}

	cout << "La fourmi ayant trouvee ses mouches et vermisseaus" << endl << "rebroussa chemin plein de vertus et de maux" << endl;
	/*
	while (antStatus == true)
	{
		backAnt(randAnthilY, randAnthilY, randAntX, randAntY, randFoodX, randFoodY, ant);
		displayGrid();
		system("PAUSE");
		system("CLS");
		
	}*/
}
