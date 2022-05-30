#pragma once
#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

#include <iostream>
#include <string>

class Customer
{
private:
	// Variables
	std::string customerID_;
	int requestedBeds_;
	static int customerCount;
public:
	//Constructors
	Customer();
	Customer(std::string, int);
	// Setter functions
	void setID(std::string);
	void setNumOfBeds(int);
	// Getter functions
	std::string getID();
	int getNumOfBeds();
	int getCustomerCount();
};

#endif