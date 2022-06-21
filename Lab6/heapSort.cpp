// Mert Kilic
// 100334228
#include <iostream>
#include <random>
#include <ctime>

// find max
int max(int* dataList, int num1, int num2)
{
    int max = (dataList[num1] >= dataList[num2]) ? num1 : num2;
    return max;
}

//swap items in the array
void swap(int* dataList, int data1, int data2)
{
    int tmp = dataList[data1];
    dataList[data1] = dataList[data2];
    dataList[data2] = tmp;
}

// heapify the max-heap
// logn runtime
void heapify(int* dataList, int size, int data)
{
    int left = (data * 2) + 1;
    int right = (data * 2 ) + 2;
    int current = data;

    while(left < size - 1)
    {
        if(right < size - 1)
        {
            int larger = max(dataList, left, right);

            if(dataList[larger] > dataList[current])
            {
                swap(dataList, current, larger);
            }

            current = larger;
            left = (current * 2) + 1;
            right = (current * 2) + 2;
        }
        else
        {
            // if there is no right child at the end
            if(dataList[left] > dataList[current])
            {
                swap(dataList, current, left);
            }
            current = left;
            left = (current * 2) + 1;
        }
    }
}

// insert the element into max-heap
// takes logn time
void insert(int* dataList, int data)
{
    int parent = (data - 1) / 2;

    while(parent > 0)
    {
        if(dataList[parent] > dataList[data])
        {
            break;
        }
        else
        {
            swap(dataList, parent, data);
            data = parent;
            parent = (data - 1) / 2;
        }
    }

    if(parent == 0 && (dataList[parent] < dataList[data]))
    {
        swap(dataList, parent, data);
    }
}

// create a max heap
void createHeap(int* dataList, int size)
{
    // n times
    for(int i = 0; i < size; i++)
    {
        // nlogn times
        insert(dataList, i);
    }
}

// sort the dataset by using max-heap and heapify
void heapSort(int* dataList, int size)
{
    int root = 0;
    int last = size-1;
    int currentSize = size;

    // create a max heap first
    createHeap(dataList, size);
    
    // sort the array by using the max heap
    while(last > 0)
    {
        swap(dataList, root, last);
        heapify(dataList, currentSize, root);
        currentSize--;
        last--;
    }

}

int main()
{
    // Testing
    int size = 15;
    int* dataList = new int[size];
    srand(time(0));

    for(int i = 0; i < size; i++)
    {
        dataList[i] = std::rand() % 10000;
    }
    
    std::cout << "before heap sort" << std::endl;
    for(int i = 0; i < size; i++)
    {
        std::cout << dataList[i] << std::endl;
    }

    heapSort(dataList, size);
    std::cout << "" << std::endl;

    std::cout << "after heap sort" << std::endl;
    for(int i = 0; i < size; i++)
    {
        std::cout << dataList[i] << std::endl;
    }

    delete[] dataList;
    return 0;
}