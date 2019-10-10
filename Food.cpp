#include "pch.h"
#include "Food.h"


Food::Food()
{
}

// geter seter 
int Food::getPosX() {
	return this->posX;
}
void Food::setPosX(int posX) {
	this->posX = posX;
}
int Food::getPosY() {
	return this->posY;
}
void Food::setPosY(int posY) {
	this->posY = posY;
}

Food::~Food()
{
}
