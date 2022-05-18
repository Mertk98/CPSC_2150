#include <iostream>
#include "LList.h"

int& change(int a[], int i)
{
    return a[i];
}

int main()
{
    LList<int> A;
    for(int i = 0; i < 20; i++)
    {
        A.insert((int)(rand() % 100));
    }

    std::cout << A << std::endl;
    A.twice();
    std::cout << A << std::endl;
    std::cout << A.length() << std::endl;

    LList<int> B;
    for(int i = 0; i < 20; i++)
    {
        B.insert((int)(rand() % 100));
    }
    std::cout << B << std::endl;
    std::cout << B.length() << std::endl;

    B = A;
    std::cout << B << std::endl;
    std::cout << B.length() << std::endl;
    std::cout << A << std::endl;
    LList<int> C;
    C = A.halve();
    std::cout << C << std::endl;
    std::cout << C.length() << std::endl;
    std::cout << A << std::endl;
    return 0;
}