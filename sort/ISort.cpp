#include "ISort.h"

ISort::ISort(int * arrToSort, size_t nSize, const std::string& strSn, SortMode nMode)
{
    arrSortData = arrToSort;
    nSortDataSize = nSize;
    strSortName = strSn;
    mSortMode = nMode;
}

ISort::~ISort()
{ }

void InsertionSort::Sort()
{
    for(int i = 1; i < nSortDataSize; i++)
    {
        int nTmp = arrSortData[i];
        for(int j = i - 1; j >= 0; j--)
        {
            if(nTmp < arrSortData[j])
            {
                arrSortData[j + 1] = arrSortData[j];//往后移动，给nTmp让路
                arrSortData[j] = nTmp; //移动以后，腾出来的位置，就让nTmp哨兵牌，依次往前插
            }
        }
    }
}

void BubbleSort::Sort()
{
    for(int i = 0; i < nSortDataSize; i++)
    {
        int nTmp = arrSortData[i];
        for(int j = i + 1; j < nSortDataSize; j++)
        {
            if(nTmp > arrSortData[j]) 
            {
                arrSortData[i] = arrSortData[j]; 
                arrSortData[j] = nTmp;
            }
        }
    }
}

/*********************
 * QUICK SORT
 * *******************/
void QuickSort::Sort()
{
    QuickSortRecurse(0, nSortDataSize - 1);
}

int QuickSort::QuickSortRecurse(int nBegin, int nEnd)
{
    if(nBegin < nEnd)
    {
        int mid = Partition(nBegin, nEnd);
        QuickSortRecurse(nBegin, mid - 1);
        QuickSortRecurse(mid + 1, nEnd);
    }
}

int QuickSort::Partition(int nBegin, int nEnd)
{
    int nPivot = arrSortData[nEnd];
    int i = nBegin; 

    for(int j = nBegin; j < nEnd; j++)
    {
        if(arrSortData[j] <= nPivot)
        {
            Swap(arrSortData[i], arrSortData[j]);
            i++;
        }
    }

    Swap(arrSortData[i], arrSortData[nEnd]);
    return i;
}
/********************/