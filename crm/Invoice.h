#pragma once
#ifndef _INVOICE_
#define _INVOICE_
#include<iostream>
#include"Car.h"
#include"Customer.h"
#include<ctime>

class Invoice
{
private:
	int id;
	int day;
	int rentDay;
	int rentMonth;
	int rentYear;
	Car car;
	Customer customer;
public:
	Invoice(void);
	~Invoice(void);
	Invoice(int, int, int, int, int, Car, Customer);
	
	void setId(int);
	void setDay(int);
	void setRentDay(int);
	void setRentMonth(int);
	void setRentYear(int);
	void setCar(Car);
	void setCustomer(Customer);

	int getId();
	int getDay();
	int getRentDay();
	int getRentMonth();
	int getRentYear();
	Car getCar();
	Customer getCustomer();
};

#endif