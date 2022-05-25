#include <iostream>
#include <string>

// Mert Kilic
// 100334228
// Lab2
// CPSC 2150

// Performs a swap
void swap(int i, int j, std::string* arr)
{
	std::string tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

int main()
{
	// Test array
	std::string arr[14] = { "red", "white", "blue", "blue", "blue", "red", "red", "blue", "white", "red", "white", "blue", "red", "blue"};
	// size of the array
	int size = 14;
	// number of reds
	int countRed = 0;
	// number of blues
	int countBlue = 0;
	// number of whites
	int countWhite = 0;

	// Counts each color linearly
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == "red")
		{
			countRed++;
		}

		else if(arr[i] == "blue")
		{
			countBlue++;
		}

		else if (arr[i] == "white")
		{
			countWhite++;
		}
	}
	
	// Array of indexes of reds
	int* redArr = new int[countRed];
	// Array of indexes of blues
	int* blueArr = new int[countBlue];
	// Array of indexes of whites
	int* whiteArr = new int[countWhite];
	
	// iterator for redArr
	int p = 0;
	// iterator for blueArr
	int j = 0;
	// iterator for whiteArr
	int k = 0;

	// Find the index of colors and stores then in their given arrays
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == "red")
		{
			redArr[p] = i;
			p++;
		}

		else if (arr[i] == "blue")
		{
			blueArr[j] = i;
			j++;
		}

		else if (arr[i] == "white")
		{
			whiteArr[k] = i;
			k++;
		}
	}

	// Size of redArr 
	int sizeOfRed = p;
	// Size of blueArr
	int sizeOfBlue = j;
	// Size of whiteArr
	int sizeOfWhite = k;

	// set the its to 0
	p = 0;
	j = 0;
	k = 0;
	
	// Sort reds by comparing their indexes with blues and whites
	for (int i = 0; i < sizeOfRed; i++)
	{
		if (redArr[i] != i)
		{
			if (j < sizeOfBlue && blueArr[j] == i)
			{
				swap(redArr[i], blueArr[j], arr);
				int tmp = redArr[i];
				redArr[i] = blueArr[i];
				blueArr[j] = tmp;
				j++;
			}

			else if (k < sizeOfWhite && whiteArr[k] == i)
			{
				swap(redArr[i], whiteArr[k], arr);
				int tmp = redArr[i];
				redArr[i] = whiteArr[i];
				whiteArr[j] = tmp;
				k++;
			}
		}
	}

	p = 0;
	j = 0;
	k = 0;

	// Since whites has to be the end, check the back of the array and
	// swap if neceserray in order to sort the back of the list
	for (int i = size - 1; i >= size - sizeOfWhite; i--)
	{
		if (arr[i] != "white")
		{
			swap(i, whiteArr[k], arr);
			k++;
		}
	}
	
	// print the sorted array
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << std::endl;
	}

	// Deallocate the dynamic arrays
	delete[] redArr;
	delete[] blueArr;
	delete[] whiteArr;

	return 0;
}