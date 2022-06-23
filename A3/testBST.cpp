#include <iostream>
#include <ctime>
#include <vector>

// instructions for random number generating algorithm
void printInstructions()
{
    std::cout << "To generate a random positive integer, enter 0." << std::endl;
    std::cout << "Otherwise, enter a positive integer." << std::endl;
}

// generate either a random num or user input depending on the input
int getInput()
{
    int num = -1;

    while(num  < 0)
    {
        printInstructions();
        std::cin >> num;
    }

    if(num == 0)
    {
        num = rand() % 100000;
    }

    return num;
}

// generate a list of random integers in an interval of [-n,n]
std::vector<int> genData(int n)
{
    std::vector<int> list;

    for(int i = 0; i < n; i++)
    {
        // generate a random num in [-n, n]
        list.push_back(2 * (rand() % (n+1)) - n);
    }

    return list;
    
}

// print the list items
void printList(std::vector<int> list)
{   
    std::cout << "{ ";
    for(int i = 0; i < list.size(); i++)
    {
        std::cout << list[i] << " ";
    }
    std::cout << " }\n";
}

int main()
{
    // get different random nums all the time
    srand(time(0));

    // first data list
    int n1 = getInput();
    std::vector<int> list1 = genData(n1);
    printList(list1);

    // second data list
    int n2 = getInput();
    std::vector<int> list2 = genData(n2);
    printList(list2);
    return 0;
}