#include <iostream>
#include <vector>

// Performs a binary search to find an occurence of a key
// Time Complexity = O(logn)
int searchIndex(std::vector<int> vect, int key, int left, int right)
{
    int mid = (left + right) / 2;

    if (vect.at(mid) == key)
    {
        return mid;
    }

    if (vect.at(mid) > key)
    {
        right = mid - 1;
        return searchIndex(vect, key, right, left);
    }

    if (vect.at(mid) < key)
    {
        left = mid + 1;
        return searchIndex(vect, key, right, left);
    }

    return -1;
}

int FBinarySearch(int low, int high, const std::vector<int>& data, int target) {
    int res = -1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (target == data[mid]) {
            res = mid;
            high = mid - 1;
        }
        else
            if (target < data[mid])
                high = mid - 1;
            else
                low = mid + 1;
    }
    return res;
}

int LBinarySearch(int low, int high, const std::vector<int>& data, int target, int res = -1) {
    int mid;
    if (low > high)
        return res;
    mid = (low + high) / 2;
    if (target == data[mid])
        return LBinarySearch(mid + 1, high, data, target, mid);
    if (target < data[mid])
        return LBinarySearch(low, mid - 1, data, target, res);
    else
        return LBinarySearch(mid + 1, high, data, target, res);
}

int main()
{
    std::vector <int> vect{ 1, 2, 3, 4, 5, 6, 6, 6, 6, 7, 8, 9};
    int size = vect.size();
    int mid = (size - 1) / 2 + 1;
    int key = 6;
    int index = searchIndex(vect, key, 0, size - 1);
    std::cout << index << std::endl;
    /*std::cout << "First occurence of " << key << " is at index " << FBinarySearch(0, size-1, vect, key) << std::endl;
    std::cout << "Last occurence of " << key << " is at index " << LBinarySearch(0, size - 1, vect, key) << std::endl;*/
}
