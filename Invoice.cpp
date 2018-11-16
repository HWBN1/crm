#include "Invoice.h"

Invoice::Invoice(void)
{
}

Invoice::~Invoice(void)
{
}

Invoice::Invoice(int id, int day, int rentDay, int rentMonth, int rentYear, Car car, Customer cus)
{		
	this->id = id;
	this->day = day;
	this->rentDay = rentDay;
	this->rentMonth = rentMonth;
	this ->rentYear = rentYear;
	this->car = car;
	this->customer = cus;
}

void Invoice::setId(int id)
{
	this->id = id;
}

void  Invoice::setDay(int day)
{
	this->day = day;
}

void Invoice::setRentDay(int rentDay)
{
	this->rentDay = rentDay;
}

void Invoice::setRentMonth(int rentMonth)
{
	this->rentMonth = rentMonth;
}

void Invoice::setRentYear(int rentYear)
{
	this ->rentYear = rentYear;
}

void Invoice::setCar(Car car)
{
	this->car = car;
}

void Invoice::setCustomer(Customer customer)
{
	this->customer =  customer;
}

int Invoice::getId()
{
	return this->id;
}

int Invoice::getDay()
{
	return this->day;
}

int Invoice::getRentDay()
{
	return this->rentDay;
}

int Invoice::getRentMonth()
{
	return this->rentMonth;
}

int Invoice::getRentYear()
{
	return this->rentYear;
}

Car Invoice::getCar()
{
	return this->car;
}

Customer Invoice::getCustomer()
{
	return this->customer;
}