#include <iostream>
#include <vector>

int searchIndex(std::vector <int> arr, int target, int mid)
{
    if(target > arr.at(mid))
    {
        searchIndex(arr, target, mid / 2);
    }

    if(target < arr.at(mid))
    {
        searchIndex(arr, target, mid + (mid / 2));
    }

    return mid;
}

int main()
{
    int arr = [1, 2, 3, 4, 5, 6, 6, 6, 6, 7];
    int size = sizeof(arr) / sizeof(arr[0]);
    std::vector <int> vect(arr, arr+size);

    int mid = vect.size() / 2;
    std::cout << searchIndex(vect, 6, mid) << std::endl;
    return 0;
}
