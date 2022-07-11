#include "Hash.h"

Hash::Hash(std::string fileName)
{
	inputFile = fileName;
}

// String length
int Hash::strLength(std::string word)
{
	return (word.length() % (int)std::pow(2, 16));
}

// First character
int Hash::firstChar(std::string word)
{
	char c = word[0];
	return (int(c) % (int)std::pow(2, 16));
}

int Hash::additive(std::string word)
{
	int num = 0;
	for (int i = 0; i < word.length(); i++)
	{
		char c = word[i];
		num += int(c);
	}

	return (num % (int)std::pow(2, 16));
}

int Hash::difference()
{
	int max = 0;
	int min = 0;
	bool check = false;
	for (size_t i = 0; i < hashTable.size(); i++)
	{
		if (hashTable[i] > max)
		{
			max = hashTable[i];
		}

		if (!check && hashTable[i] != 0)
		{
			min = hashTable[i];
			check = true;
		}

		if (hashTable[i] < min && hashTable[i] != 0 && check)
		{
			min = hashTable[i];
		}
	}

	return max - min;
}

void Hash::resetTable()
{
	for (size_t i = 0; i < hashTable.size(); i++)
	{
		hashTable[i] = 0;
	}
}

void Hash::collisionTest()
{
	// string length test
	std::ifstream inFile;
	inFile.open(inputFile);

	if (inFile.is_open())
	{
		std::string tmp = "";

		while (std::getline(inFile, tmp))
		{
			int index = strLength(tmp);
			hashTable[index]++;
		}
	}
	inFile.close();

	std::cout << "String length: " << difference() << std::endl;
	resetTable();

	inFile.open(inputFile);

	// First Character
	if (inFile.is_open())
	{
		std::string tmp = "";

		while (std::getline(inFile, tmp))
		{
			int index = firstChar(tmp);
			hashTable[index]++;
		}
	}
	inFile.close();

	std::cout << "First Character: " << difference() << std::endl;
	resetTable();

	inFile.open(inputFile);

	// Additive
	if (inFile.is_open())
	{
		std::string tmp = "";

		while (std::getline(inFile, tmp))
		{
			int index = additive(tmp);
			hashTable[index]++;
		}
	}
	inFile.close();

	std::cout << "Additive: " << difference() << std::endl;
	resetTable();
}
