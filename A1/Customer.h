#pragma once
#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

#include <iostream>
#include <string>

class Customer
{
private:
	std::string customerID_;
	int requestedBeds_;
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
	~Customer();
};

#endif