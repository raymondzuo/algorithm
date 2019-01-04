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