#ifndef _HASH_H_
#define _HASH_H_
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>

class Hash
{
private:
    const int SIZE = (int)std::pow(2, 16);
    std::vector<int> hashTable = std::vector<int>(SIZE, 0);
    std::string inputFile;
    int strLength(std::string word);
    int firstChar(std::string word);
    int additive(std::string word);
    int mystery(std::string word);
    int bonus(std::string word);
    int difference();
    void resetTable();
public:
    Hash(std::string fileName);
    void collisionTest();
};

#endif // _HASH_H_