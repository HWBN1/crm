#pragma once
#ifndef _CAR_
#define _CAR_
#include<iostream>

class Car
{
private:
	int left;//so luong con
	char* name;//ten hang xe
	int seat;//so cho
	int fee;

public:
	Car(void);
	~Car(void);
	Car(char* name, int fee, int seat,int left);

	void setLeft(int left);
	void setName(char* name);
	void setSeat(int seat);
	void setFee(int fee);
	
	int getLeft();
	char* getName();
	int getSeat();
	int getFee();
};

#endif