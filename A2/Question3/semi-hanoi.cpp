#include <iostream>

int TOH(int disks, char A, char B, char C) {

	int moves = 0;

	if (disks == 1) 
	{
		moves++;
	}
	else 
	{
		moves += TOH(disks - 1, A , C, B);
		moves += TOH(1, A, B, C);
		moves += TOH(disks - 1, C, B, A);
	}

	return moves;
}

int semiHanoi(int disks, char A, char B, char C)
{
	int n = disks / 2;
	int moves = 0;

	if (n == 1)
	{
		moves += 2;
	}

	if (n > 1)
	{
		moves += semiHanoi(2 * (n - 1), A, B, C);
		moves += TOH(disks - 1, C, A, B);
		moves += TOH(disks - 1, A, C, B);
	}

	return moves;
}

int main()
{
	for (int i = 1; i < 6; i++)
	{
		std::cout << semiHanoi(2 * i, 'A', 'B', 'C') << std::endl;
	}

	return 0;
}