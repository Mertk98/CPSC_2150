#include <iostream>

int pow(int base, int exp)
{
	if (exp == 0)
	{
		return 1;
	}

	if (exp % 2 == 0)
	{
		return pow(base * base, exp / 2);
	}

	return base * pow(base * base, (exp - 1) / 2);
}

int factorial(int num)
{
	if (num == 0)
	{
		return 1;
	}

	return num * factorial(num - 1);
}

int sum(int n)
{
	if (n == 0)
	{
		return n;
	}

	return n + sum(n - 1);
}

// Uses Horner's Rule
double taylor_series(int x, int n)
{
	static double r = 1;

	if (n == 0)
	{
		return r;
	}

	r = 1 + r * x / n;

	return taylor_series(x, n - 1);
}

// Fibonacci series with O(2^n or ~ O(1.6^n))
int fibonacci(int n)
{
	if (n <= 1)
	{
		return n;
	}

	return fibonacci(n - 1) + fibonacci(n - 2);
}

// Fibonacci series with O(n)
int fibn(int n, int memo[])
{
	if (n <= 1)
	{
		memo[n] = n;
		return n;
	}

	else
	{
		if (memo[n - 2] == 0)
		{
			memo[n - 2] = fibn(n - 2, memo);
		}

		if (memo[n - 1] == 0)
		{
			memo[n - 1] = fibn(n - 1, memo);
		}

		return memo[n - 2] + memo[n - 1];
	}
}

// using formula
int c(int n, int r)
{
	int t1, t2, t3;
	t1 = factorial(n);
	t2 = factorial(r);
	t3 = factorial(n - r);

	return t1 / (t2 * t3);
}

// using recursion
int ncr(int n, int r)
{
	if (r == 0 || n == r)
	{
		return 1;
	}
	return ncr(n - 1, r - 1) + ncr(n - 1, r);
}

// exponential time complexity 2^n - 1 ~ O(2^n)
void TOH(int n, int A, int B, int C, int& i)
{
	if (n > 0)
	{
		TOH(n - 1, A, C, B, i);
		std::cout << "step #" << ++i << " move " << A << " to " << C << std::endl;
		TOH(n - 1, B, A, C, i);
	}
}

int main()
{
	std::cout << pow(2, 5) << std::endl;
	std::cout << factorial(5) << std::endl;
	std::cout << sum(5) << std::endl;
	std::cout << taylor_series(3, 5) << std::endl;
	std::cout << fibonacci(6) << std::endl;

	int n = 5;
	int* memo = new int[n + 1]{ 0 };
	std::cout << fibn(n, memo) << std::endl;
	delete[] memo;
	std::cout << c(7, 4) << std::endl;
	std::cout << ncr(7, 4) << std::endl;

	int i = 0;
	TOH(5, 1, 2, 3, i);
	return 0;
}