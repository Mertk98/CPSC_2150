#pragma once
#ifndef _DATE_H_
#define _DATE_H_
#include <iostream>
#include <string>
#include <vector>

class Date {
private:
	int day_;
	int month_;
	int year_;
	std::vector<int> months_;
	friend class Customer;
	friend class Room;
public:
	Date();
	Date(int day, int month, int year);
	Date(std::string date);
	//setters
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	//getters
	int getDay();
	int getMonth();
	int getYear();
	bool isLeapYear(int year);
	void parseDate(std::string date);
	void reset();
	void operator+(int extraDay);
	bool operator<=(const Date& other);
	Date& operator=(const Date& other);
	friend std::ostream& operator<<(std::ostream& out, const Date& date);
};

#endif // !_DATE_H_
