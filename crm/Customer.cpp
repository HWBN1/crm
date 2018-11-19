#include "Customer.h"

Customer::Customer(void)
{
}

Customer::~Customer(void)
{
}

Customer::Customer(char* name, char* phone, char* address)
{
		 this->name = name;
		 this->phone = phone;
		 this->address = address;
}

void Customer::setName(char* name)
{
	this->name = name;
}

void Customer::setPhone(char* phone)
{
	this->phone = phone;
}

void Customer::setAddress(char* address)
{
	this->address = address;
}
	
char* Customer::getName()
{
	return this->name;
}

char* Customer::getPhone()
{
	return this->phone;
}

char* Customer::getAddress()
{
	return this->address;
}