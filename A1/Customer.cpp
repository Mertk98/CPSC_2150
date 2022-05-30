#include <iostream>
#include "Customer.h"

int Customer::customerCount = 0;

Customer::Customer()
{
	customerID_ = "";
	requestedBeds_ = 0;
	customerCount++;
}

Customer::Customer(std::string ID, int numOfBeds)
{
	customerID_ = ID;
	requestedBeds_ = numOfBeds;
	customerCount++;
}

std::string Customer::getID()
{
	return customerID_;
}

int Customer::getNumOfBeds()
{
	return requestedBeds_;
}

void Customer::setID(std::string ID)
{
	customerID_ = ID;
}

void Customer::setNumOfBeds(int numOfBeds)
{
	requestedBeds_ = numOfBeds;
}

int Customer::getCustomerCount()
{
	return customerCount;
}