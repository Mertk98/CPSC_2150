#include <iostream>
#include <vector>
#include <string>

int* calcFrequency(std::string str, int size)
{
    int* frequency = new int[128]{0};

    for(size_t i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        frequency[(int)ch]++;
    }
    
}

int main()
{
    std::string str = "EYEWITNESSNEWS";


    return 0;
}