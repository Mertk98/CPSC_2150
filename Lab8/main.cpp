#include <iostream>
#include <string>
#include "Hash.h"

int main()
{
	Hash hash("keys1.txt");
	hash.collisionTest();

	return 0;
}