#include <iostream>
#include <string>
#include <vector>
#include "Room.h"

Date currentDate;

Room::Room()
{
	customer_ = nullptr;
	daysOfStay_ = 0;
	numOfBeds_ = 0;
	bedsInUse_ = 0;
}

Room::Room(const int numOfBeds)
{
	numOfBeds_ = numOfBeds;
	customer_ = nullptr;
	daysOfStay_ = 0;
	bedsInUse_ = 0;
}

Room::Room(Customer* cus, std::string checkIn, const int stay, const int reqBeds, const int numOfBeds)
{
	customer_ = cus;
	daysOfStay_ = stay;
	numOfBeds_ = numOfBeds;
	bedsInUse_ = reqBeds;
	setCheckIn(checkIn);
	setCheckOut(stay);
}

void Room::setCustomer(Customer* cus)
{
	customer_ = cus;
}

void Room::setCheckIn(std::string checkIn)
{
	int* dmy = parseDate(checkIn);
	checkInDate_.day_ = dmy[0];
	checkInDate_.month_ = dmy[1];
	checkInDate_.year_ = dmy[2];
}

void Room::setCheckOut(const int stay)
{
	checkOutDate_ = checkInDate_;
	checkOutDate_ + stay;
}

void Room::setStay(const int stay)
{
	daysOfStay_ = stay;
}

void Room::setNumOfBeds(const int numOfBeds)
{
	numOfBeds_ = numOfBeds;
}

void Room::setBedsInUse(const int reqBeds)
{
	bedsInUse_ = reqBeds;
}

Customer* Room::getCustomer() const
{
	return customer_;
}

Date Room::getCheckInDate() const
{
	return checkInDate_;
}

Date Room::getCheckOutDate() const
{
	return checkOutDate_;
}

int Room::getNumOfBeds() const
{
	return numOfBeds_;
}

int Room::getBedsInUse() const
{
	return bedsInUse_;
}

int* Room::parseDate(std::string date)
{
	std::string del = "/";
	int* dmy = new int[3];
	size_t pos = 0;
	int i = 0;

	// Parse the date string by delimeter "/"
	while ((pos = date.find(del)) != std::string::npos)
	{
		dmy[i] = std::stoi(date.substr(0, pos));
		date.erase(0, pos + del.length());
		i++;
	}
	dmy[i] = std::stoi(date);

	return dmy;
}

void Room::emptyTheRoom()
{
	if (customer_ != nullptr)
	{
		delete customer_;
		customer_ = nullptr;
	}

	daysOfStay_ = 0;
	numOfBeds_ = 0;
	bedsInUse_ = 0;
	checkInDate_.reset();
	checkOutDate_.reset();
}

Room::~Room()
{
	emptyTheRoom();
}