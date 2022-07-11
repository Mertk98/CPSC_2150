#ifndef _HASH_H_
#define _HASH_H_

#include <iostream>
#include <cmath>
#include <vector>

class Hash
{
    const int SIZE = (int)std::pow(2,16);
    std::vector<int> hashTable = std::vector<int>(SIZE);

}

#endif // _HASH_H_