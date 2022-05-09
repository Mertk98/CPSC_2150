#include <iostream>
#include <vector>

// Performs a binary search to find an occurence of a key
// Time Complexity = O(logn)
int searchIndex(std::vector<int> vect, int key, int left, int right, int mid)
{
    if (vect.at(mid) == key)
    {
        return mid;
    }

    if (vect.at(mid) > key)
    {
        right = mid - 1;
        mid = right / 2 + 1;
        return searchIndex(vect, key, right, left, mid);
    }

    if (vect.at(mid) < key)
    {
        left = mid + 1;
        mid = (right + left) / 2;
        return searchIndex(vect, key, right, left, mid);
    }

    return -1;
}

// Performs a linear search to find the first occurence of a key
// Time Complexity = O(m)
int find_first(std::vector<int> vect, int key, int index)
{
    while (vect.at(index) == key)
    {
        index--;
    }

    return index + 1;
}

// Performs a linear search to find the last occurence of a key
// Time Complexity = O(g)
int find_last(std::vector<int> vect, int key, int index)
{
    while (vect.at(index) == key)
    {
        index++;
    }

    return index - 1;
}

int main()
{
    std::vector <int> vect{ 1, 2, 3, 4, 5, 6, 6, 6, 6, 7, 8, 9};
    int size = vect.size();
    int mid = (size - 1) / 2 + 1;
    int key = 6;
    int index = searchIndex(vect, key, 0, size - 1, mid);
    
    std::cout << "First occurence of " << key << " is at index " << find_first(vect, key, index) << std::endl;
    std::cout << "Last occurence of " << key << " is at index " << find_last(vect, key, index) << std::endl;
    std::cout << "Finding the first occurence: O(logn + m)\n" << "Finding the last occurence: O(logn + g)\n" << std::endl;
}

