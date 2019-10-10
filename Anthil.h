#ifndef ANTHIL_H
#define ANTHIL_H
#include <string>
#pragma once
class Anthil
{
public:
	Anthil();
	~Anthil();

	int getPosX();
	int getPosY();
	void setPosX(int posX);
	void setPosY(int posY);

private:
	int posX;
	int posY;
};

#endif // !ANTHIL_H


