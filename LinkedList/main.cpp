#include <iostream>
#include "LList.h"

int& change(int a[], int i)
{
    return a[i];
}

int main()
{
    LList A;
    for(int i = 0; i < 40; i++)
    {
        A.insert((int)(rand() % 100));
    }

    // A.twice();
    // std::cout << A << std::endl;
    // std::cout << A.length() << std::endl;

    // LList B;
    // for(int i = 0; i < 40; i++)
    // {
    //     B.insert((int)(rand() % 100));
    // }
    // std::cout << B << std::endl;
    // std::cout << B.length() << std::endl;

    // B = A;
    // std::cout << B << std::endl;
    // std::cout << B.length() << std::endl;
    std::cout << A << std::endl;
    std::cout << A.halve() << std::endl;
    std::cout << A << std::endl;


    return 0;
}