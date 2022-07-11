#ifndef _HASH_H_
#define _HASH_H_
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

class Hash
{
private:
    const int SIZE = (int)std::pow(2,16);
    std::vector<int> hashTable = std::vector<int>(SIZE);
    int hashFunction(std::string word);
public:
    Hash(std::string fileName);

};

#endif // _HASH_H_