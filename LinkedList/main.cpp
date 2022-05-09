#include <iostream>
#include "LList.h"

int main()
{
    LList A;
    for(int i = 0; i < 50; i++)
    {
        A.insert((int)(rand() % 100));
    }

    std::cout << A << std::endl;

    A.twice();
    
    return 0;
}