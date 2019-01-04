#include "ISort.h"

int main()
{
    const int SIZE = 5;
    int arr[SIZE] = {2,5,3,1,4};
    InsertionSort insertionSt(arr, SIZE);
    insertionSt.Sort();
    
    for(size_t i = 0; i < SIZE; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}