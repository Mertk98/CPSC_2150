#include <iostream>
#include <string>

int numPathsFromHome(int street, int avenue)
{
    int paths = 0;

    if (street == 0 || avenue == 0)
    {
        return 1;
    }

    paths += numPathsFromHome(street - 1, avenue);
    paths += numPathsFromHome(street, avenue - 1);

    return paths;
}

bool hasSubsequence(const std::string& text, const std::string& subseq)
{

    if (subseq.length() == 1 && subseq[0] == text[0])
    {
        return  true;
    }
    else if (subseq.length() > 0 && (text.length() <= 1 && subseq[0] != text[0]) || subseq.length() == 0)
    {
        return false;
    }
    else
    {
        std::string tmp = (subseq[0] == text[0]) ? subseq.substr(1, subseq.length()) : subseq;
        return hasSubsequence(text.substr(1, text.length()), tmp);
    }

    return false;
}

int main()
{
    std::cout << "======= numPathsFromHome Test =======" << std::endl;
    std::cout << numPathsFromHome(2, 1) << std::endl;
    std::cout << numPathsFromHome(1, 2) << std::endl;
    std::cout << numPathsFromHome(2, 2) << std::endl;
    std::cout << numPathsFromHome(2, 3) << std::endl;
    std::cout << numPathsFromHome(3, 2) << std::endl;
    std::cout << numPathsFromHome(3, 4) << std::endl;
    std::cout << numPathsFromHome(4, 3) << std::endl;
    std::cout << numPathsFromHome(4, 4) << std::endl;
    std::cout << numPathsFromHome(5, 5) << std::endl;

    std::cout << "======= hasSubsequence Test =======" << std::endl;
    std::cout << hasSubsequence("springtime", "singe") << std::endl;
    std::cout << hasSubsequence("least", "steal") << std::endl;
    std::cout << hasSubsequence("agreeable", "AGREE") << std::endl;
    std::cout << hasSubsequence("programming", "pin") << std::endl;
    std::cout << hasSubsequence("programming", "pni") << std::endl;

    return 0;
}