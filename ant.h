#ifndef ANT_H
#define ANT_H
#include <string>
#pragma once

using namespace std;

class Ant
{
public:
	Ant();
	~Ant();

	int getPosX();
	int getPosY();
	int getStatus();
	void setPosX(int posX);
	void setPosY(int posY);
	void setStatus(int status);

private:
	int posX; // position sur la grille
	int posY; // position sur la grille 
	int status; // 0 = vide   1 = nourriture
};

#endif // !ANT_H


