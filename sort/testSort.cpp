#include "ISort.h"

int main()
{
    const int SIZE = 5;
    //int arr[SIZE] = {2,5,3,1,4};
    int arr[SIZE] = {5,4,3,2,1};
    /*
    InsertionSort insertionSt(arr, SIZE);
    insertionSt.Sort();
    */

    /*BubbleSort bubbleSt(arr, SIZE);
    bubbleSt.Sort();*/

    QuickSort quickSt(arr, SIZE);
    quickSt.Sort();
    
    for(size_t i = 0; i < SIZE; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}