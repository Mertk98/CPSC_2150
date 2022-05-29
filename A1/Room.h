#pragma once
#ifndef _ROOM_H_
#define _ROOM_H_

#include <iostream>
#include <string>
#include "Customer.h"
#include "Date.h"

class Room
{
private:
	// Vars
	Customer* customer_;
	Date checkInDate_;
	Date checkOutDate_;
	int daysOfStay_;
	int numOfBeds_;
	int bedsInUse_;
	// Helper functions and vars
	int* parseDate(std::string);
	static Date currentDate;

public:
	// Constructors
	Room();
	Room(const int);
	Room(Customer*, std::string, const int, const int, const int);
	// Setter Functions
	void setCustomer(Customer*);
	void setCheckIn(std::string);
	void setCheckOut(const int);
	void setStay(const int);
	void setNumOfBeds(const int);
	void setBedsInUse(const int);
	// Getter Functions
	Customer* getCustomer() const;
	Date getCheckInDate() const;
	Date getCheckOutDate() const;
	int getNumOfBeds() const;
	int getBedsInUse() const;
	// resets the room
	void emptyTheRoom();
	~Room();
};

#endif