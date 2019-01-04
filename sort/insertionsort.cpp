#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void insertionSort(int* arr, size_t length);

int main()
{
    int arr[5] = {3,2,1,4,5};
    insertionSort(arr, 5);
    for(const int& ele : arr)
    {
        cout << ele << " ";
    }
    return 0;
}

void insertionSort(int* arr, size_t length)
{
    for(size_t i = 1;i<length;i++)
    {
        int temp = arr[i];
        for(int j = i - 1;j >= 0;j--)
        {
            if(arr[j] > temp)
            {
                arr[j+1] = arr[j];//往后移动，给temp让路
                arr[j] = temp;//移动以后，腾出来的位置，就让temp哨兵牌，依次往前插
            }
        }
    }
}
