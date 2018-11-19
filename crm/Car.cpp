#include "Car.h"

Car::Car(void)
{
}

Car::~Car(void)
{
}

Car::Car(char* name, int fee, int seat,int left)
{
	this->left = left;
	this->name = name;
	this->seat = seat;
	this->fee = fee;
}

void Car::setLeft(int left)
{
	this->left = left;
}

void Car::setName(char* name)
{
	this->name = name;
}

void Car::setSeat(int seat)
{
	this->seat = seat;
}

void Car::setFee(int fee)
{
	this->fee = fee;
}

int Car::getLeft()
{
	return this->left;
}

char* Car::getName()
{
	return this->name;
}

int Car::getSeat()
{
	return this->seat;
}

int Car::getFee()
{
	return this->fee;
}