#include <iostream>

int numPathsFromHome(int street, int avenue)
{
    int num = 0;

        if (street == 0 || avenue == 0)
        {
            return 1;
        }


        num += numPathsFromHome(street - 1, avenue);
        num += numPathsFromHome(street, avenue - 1);

        return num;
        
}

bool hasSubsequence(const std::string& text, const std::string& subseq)
{
    
}

int main()
{
    std::cout << numPathsFromHome(2,1) << std::endl;

    return 0;
}