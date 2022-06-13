#include <iostream>
#include <string>
#include "ER.h"
#include "PriorityQueue.h"
#include "Patient.h"


int main()
{
	srand(time(0));

	ER<Patient> er;

	for (int i = 0; i < 50; i++)
	{
		std::string str = "patient" + std::to_string(i);
		er.insert(new Patient(rand() % 10 + 1, str));
	}
	
	er.printEr();

	for (int i = 0; i < 50; i++)
	{
		std::cout << "ER Update: Removed the patient with most urgent status" << std::endl;
		er.remove();
	}



	return 0;
}