#include "pch.h"
#include "ant.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;


Ant::Ant()
{
}

// geter seter 
int Ant::getPosX() {
	return this->posX;
}

void Ant::setPosX(int posX) {
	this->posX = posX;
}

int Ant::getPosY() {
	return this->posY;
}
void Ant::setPosY(int posY) {
	this->posY = posY;
}

int Ant::getStatus()
{
	return this->status;
}

void Ant::setStatus(int status)
{
	this->status = status;
}

Ant::~Ant()
{
}
