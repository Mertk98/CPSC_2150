#include "Patient.h"
#include <string>

Patient::Patient()
{
	priority_ = -1;
	name_ = "";
}

Patient::Patient(int priority, std::string name)
{
	priority_ = priority;
	name_ = name;
}

void Patient::setPriority(int priority)
{
	priority_ = priority;
}

void Patient::setName(std::string name)
{
	name_ = name;
}

int Patient::getPriority()
{
	return priority_;
}

std::string Patient::getName()
{
	return name_;
}