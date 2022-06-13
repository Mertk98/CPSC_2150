#ifndef _PATIENT_H_
#define _PATIENT_H_
#include <iostream>
#include <string>

class Patient
{
private:
	int priority_;
	std::string name_;
public:
	Patient();
	Patient(int priority, std::string name);
	void setPriority(int priority);
	void setName(std::string name);
	int getPriority();
	std::string getName();
	~Patient() = default;
};

#endif // !_PATIENT_H_
