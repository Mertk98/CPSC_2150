#include <iostream>
#include "Date.h"

Date::Date()
{
	day_ = 0;
	month_ = 0;
	months_ = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	year_ = 0;
}

Date::Date(int day, int month, int year)
{
	day_ = day;
	month_ = month;
	months_ = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	year_ = year;

	// Check if the current year is a leap year
	// if it is, then change the last day of feb to 29
	if (isLeapYear(year))
	{
		months_[2] = 29;
	}
}

Date::Date(std::string date)
{
	day_ = 0;
	month_ = 0;
	months_ = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	year_ = 0;

	parseDate(date);
	// Check if the current year is a leap year
	// if it is, then change the last day of feb to 29
	if (isLeapYear(year_))
	{
		months_[2] = 29;
	}
}

void Date::setDay(int day)
{
	day_ = day;
}

void Date::setMonth(int month)
{
	month_ = month;
}

void Date::setYear(int year)
{
	year_ = year;
}

int Date::getDay()
{
	return day_;
}

int Date::getMonth()
{
	return month_;
}

int Date::getYear()
{
	return year_;
}

bool Date::isLeapYear(int year)
{
	if (year % 100 == 0 && year % 400 == 0)
	{
		return true;
	}
	else if (year % 100 != 0 && year % 4 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Date::parseDate(std::string date)
{
	std::string del = "/";
	int dmy[3];
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
	
	day_ = dmy[0];
	month_ = dmy[1];
	year_ = dmy[2];
}

void Date::reset()
{
	day_ = 0;
	month_ = 0;
	year_ = 0;
}

void Date::operator+(int extraDay)
{
	while (extraDay > 0)
	{
		months_[2] = (isLeapYear(year_)) ? 29 : 28;



		int toEnd = months_[month_] - day_;
		extraDay -= toEnd+1;

		if (extraDay > 0)
		{
			month_++;
			day_ = 1;

			if (month_ > 12)
			{
				month_ = 1;
				year_++;
			}
		}
		else
		{
			day_ += (toEnd + extraDay + 1);
		}
	}
}

bool Date::operator<=(const Date& other)
{
	if (year_ > other.year_)
	{
		return false;
	}
	
	else if (year_ < other.year_)
	{
		return true;
	}

	else if (year_ == other.year_)
	{
		if (month_ > other.month_)
		{
			return false;
		}
		else if (month_ < other.month_)
		{
			return true;
		}
		else if (month_ == other.month_)
		{
			if (day_ > other.day_)
			{
				return false;
			}
			else if (day_ < other.day_)
			{
				return true;
			}
			else if (day_ == other.day_)
			{
				return true;
			}

			return false;
		}

		return false;
	}

	return false;
}

Date& Date::operator=(const Date& other)
{
	if (this == &other)
	{
		return *this;
	}

	day_ = other.day_;
	month_ = other.month_;
	year_ = other.year_;

	return *this;
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	out << " Day/Month/Year: ";
	out << date.day_ << "/" << date.month_ << "/" << date.year_;
	
	return out;
}