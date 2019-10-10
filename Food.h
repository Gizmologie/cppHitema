#ifndef FOOD_H 
#define FOOD_H
#include <string>
#pragma once

using namespace std;

class Food
{
public:
	Food();
	~Food();

	int getPosX();
	int getPosY();
	void setPosX(int posX);
	void setPosY(int posY);

private:
	int posX;
	int posY;
};

#endif 