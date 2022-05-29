#include <iostream>
#include <fstream>
#include <string>
#include "Room.h"
#include "Customer.h"
#include "Date.h"

std::string* parseInput(std::string input)
{
	std::string del = ", ";
	static std::string parsedIn[4];
	size_t pos = 0;
	int i = 0;

	//Parse the input string by delimeter ","
	while ((pos = input.find(del)) != std::string::npos)
	{
		parsedIn[i] = input.substr(0, pos);
		input.erase(0, pos + del.length());
		i++;
	}

	parsedIn[i] = input;

	return parsedIn;
}

// Finds the best available combination of rooms for customers
std::vector<std::vector<int>> findAvailableRooms(int cap3, int cap2, int cap1, int requested)
{
	std::vector<std::vector<int>> comb;

	while (requested > 0)
	{
		if (requested >= 3 && cap3 > 0)
		{
			comb.push_back({3,3});
			requested -= 3;
			cap3--;
		}
		else if (requested >= 2 && cap2 > 0)
		{
			comb.push_back({2,2});
			requested -= 2;
			cap2--;
		}
		else if (requested >= 1 && cap1 > 0)
		{
			comb.push_back({1,1});
			requested -= 1;
			cap1--;
		}
		else
		{
			if (cap3 > 0 && requested <= 3)
			{
				comb.push_back({3, requested});
				requested -= requested;
			}
			else if (cap2 > 0 && requested <= 2)
			{
				comb.push_back({2, requested});
				requested -= requested;
			}
			else if (cap1 > 0 && requested <= 1)
			{
				comb.push_back({1, requested});
				requested -= requested;
			}
			else
			{
				comb.push_back({0,0});
				requested = 0;
			}
		}
	}

	return comb;
}

// Performs a modified binary search and find available rooms for customers
// Can be improved
// Add a boolean to check if the index is found
// start from left side to then go to right side
// best case o(1), ave o(logn) worst o(n)
int  findRoomIndex(int low, int high, Room* rooms, bool& found)
{
	int mid = (low + high) / 2;
	int index = -1;

	if (rooms[mid].getBedsInUse() == 0)
	{
		found = true;
		return mid;
	}
	else
	{
		if (!found && low < high)
		{
			index = findRoomIndex(low, mid - 1, rooms, found);
		}
		
		if (!found && high > low)
		{
			index = findRoomIndex(mid + 1, high, rooms, found);
		}
	}

	return index;
}

// Help customers to checkout
void cleanRooms(const int* totalRooms, int* capacity, Room* rooms3, Room* rooms2, Room* rooms1, Date currentDate)
{
	for (int i = 0; i < totalRooms[0]; i++)
	{
		if (rooms3[i].getCustomer() != nullptr && rooms3[i].getCheckOutDate() <= currentDate)
		{
			rooms3[i].emptyTheRoom();
			capacity[0]++;
		}
	}

	for (int i = 0; i < totalRooms[1]; i++)
	{
		if (rooms2[i].getCustomer() != nullptr && rooms2[i].getCheckOutDate() <= currentDate)
		{
			rooms2[i].emptyTheRoom();
			capacity[1]++;
		}
	}

	for (int i = 0; i < totalRooms[2]; i++)
	{
		if (rooms1[i].getCustomer() != nullptr && rooms1[i].getCheckOutDate() <= currentDate)
		{
			rooms1[i].emptyTheRoom();
			capacity[2]++;
		}
	}
}

void setRoom(std::string date, int bedsInUse, int stay, Customer* cus, Room& room)
{
	room.setBedsInUse(bedsInUse);
	room.setCustomer(cus);
	room.setCheckIn(date);
	room.setCheckOut(stay);
	room.setStay(stay);
}

// handle the rooms for customers
void roomHandler(const int* totalRooms, int* capacity, Room* rooms3, Room* rooms2, Room* rooms1, const std::string* details)
{
	std::string date = details[0];
	std::string cusID = details[1];
	int totalBeds = std::stoi(details[2]);
	int stay = std::stoi(details[3]);

	Date currentDate(date);
	cleanRooms(totalRooms, capacity, rooms3, rooms2, rooms1, currentDate);
	std::vector<std::vector<int>> comb = findAvailableRooms(capacity[0], capacity[1], capacity[2], totalBeds);
	bool isFull = (comb.back()[0] == 0) ? true : false;

	if (!isFull)
	{
		for (size_t i = 0; i < comb.size(); i++)
		{
			int room = comb[i][0];
			int index = -1;
			bool found = false;

			if (room == 1)
			{
				index = findRoomIndex(0, totalRooms[2] - 1, rooms1, found);
				setRoom(date, comb[i][1], stay, new Customer(cusID, totalBeds), rooms1[index]);
				capacity[2]--;
			}
			else if (room == 2)
			{
				index = findRoomIndex(0, totalRooms[1] - 1, rooms2, found);
				setRoom(date, comb[i][1], stay, new Customer(cusID, totalBeds), rooms2[index]);
				capacity[1]--;
			}
			else if (room == 3)
			{
				index = findRoomIndex(0, totalRooms[0] - 1, rooms3, found);
				setRoom(date, comb[i][1], stay, new Customer(cusID, totalBeds), rooms3[index]);
				capacity[0]--;
			}
		}
	}
	
}

int main()
{
	// An array to store total number of rooms. Left to right w/ 3 beds ... 1 beds
	int totalRoomsArr[3] = { 30, 50, 100 };

	//Initializing dynamic arrays for rooms
	Room* rooms3 = new Room[totalRoomsArr[0]];
	Room* rooms2 = new Room[totalRoomsArr[1]];
	Room* rooms1 = new Room[totalRoomsArr[2]];

	// Keep track of capacity
	int capacityArr[3] = { 30, 50, 100 };

	// initializing the number of beds in each room for rooms with 3 beds
	for (int i = 0; i < totalRoomsArr[0]; i++)
	{
		rooms3[i].setNumOfBeds(3);
	}
	
	// initializing the number of beds in each room for rooms with 2 beds
	for (int i = 0; i < totalRoomsArr[1]; i++)
	{
		rooms2[i].setNumOfBeds(2);
	}
	
	// initializing the number of beds in each room for rooms with 1 beds
	for (int i = 0; i < totalRoomsArr[2]; i++)
	{
		rooms1[i].setNumOfBeds(1);
	}


	std::fstream myFile;
	myFile.open("Customers.txt");

	if (myFile.is_open())
	{
		std::string tmp;
		std::string* inputArr = nullptr;
	/*	std::string date;
		std::string cusID;
		std::string beds;
		std::string stay;
		std::vector<int> comb;*/
		int i = 0;

		while (std::getline(myFile, tmp))
		{
			if (i > 0)
			{
				inputArr = parseInput(tmp);
				/*date = inputArr[0];
				cusID = inputArr[1];
				beds = inputArr[2];
				stay = inputArr[3];*/

				roomHandler(totalRoomsArr, capacityArr, rooms3, rooms2, rooms1, inputArr);
				std::cout << i << std::endl;
			}
			i++;
		}
		myFile.close();
	}
	
	delete[] rooms3;
	delete[] rooms2;
	delete[] rooms1;
	return 0;
}