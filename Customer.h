#pragma once
#ifndef _CUSTOMER_
#define _CUSTOMER_	 
#include<iostream>
using namespace std;

class Customer
{
private:
	char* name;
	char* phone;
	char* address;
public:
	Customer(void);
	~Customer(void);
	void setName(char* name);
	void setPhone(char* phone);
	void setAddress(char* address);
	Customer(char*, char*, char*);

	char* getName();
	char* getPhone();
	char* getAddress();
};

#endif